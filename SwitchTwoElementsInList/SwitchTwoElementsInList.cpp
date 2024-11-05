// SwitchTwoElementsInList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

void PrintList(ListNode* pHead)
{
    if (pHead == nullptr)
        return;

    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data;
        pHead = pHead->next;
    }
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

ListNode* GetNodeByIndex(ListNode* pHead, int index)
{
    if (index == -1)
        return nullptr;

    for (int i = 0; i < index; ++i)
    {
        pHead = pHead->next;
    }

    return pHead;
}

ListNode* ReverseLinkedList(ListNode* head, int left, int right)
{
    if (left == right)
        return head;

    ListNode* pHead = head;
    ListNode* pLeftPrevious = nullptr;
    ListNode* pLeft = nullptr;
    ListNode* pRightPrevious = nullptr;
    ListNode* pRight = nullptr;

    int count = 0;
    while (pHead != nullptr)
    {
        if (++count == left)
            pLeft = pHead;
        else if (count == right)
            pRight = pHead;

        if (pLeft == nullptr)
            pLeftPrevious = pHead;

        if (pRight == nullptr)
            pRightPrevious = pHead;

        pHead = pHead->next;
    }

    if (pRight == nullptr || pLeft == nullptr)
        return head;

    if (pRightPrevious == nullptr)
        return head;

    // remove right from the list
    pRightPrevious->next = pRight->next;

    // insert right to the place that left is at
    pRight->next = pLeft->next;
    if (pLeftPrevious != nullptr)
    {   // only when the left is not the head, we need to move 
        //  its prevous next to the right element
        pLeftPrevious->next = pRight;
    }

    // insert left node to the place that right used to be
    pLeft->next = pRightPrevious->next;
    if (pRightPrevious == pLeft)
    {   // switching the adjacent 2 elements, the element before
        //  the right node has changed to the right node
        pRight->next = pLeft;
    }
    else
        pRightPrevious->next = pLeft;

    if (pLeftPrevious == nullptr)   // the left node is the head, head has changed
        return pRight;

    return head;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of nodes in list: ";
        std::cin >> count;
        if (count < 0)
            break;

        ListNode* pHead = nullptr;
        ListNode* pTail = GetListFromInput(&pHead, count);

        std::cout << "The two nodes to be reversed: ";
        int index1 = 0, index2 = 0;
        std::cin >> index1 >> index2;

        if (index1 > index2)
            std::swap(index1, index2);

        pHead = ReverseLinkedList(pHead, index1, index2);

        std::cout << "The reversed linked list: ";
        PrintList(pHead);
        std::cout << std::endl;

        FreeList(pHead);
    }
}
