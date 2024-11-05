Reverse a Linked List II


Given a linked list and two numbers left and right, reverse the nodes from position 'left' to position 'right'. Assume: left <= right.

Example
left: 2, right: 4
Linked list: 1→5→7→13
Result: 1→13→7→5
left: 2, right: 3
Linked list: 1→5→7→13
Result: 1→7→5→13
Testing
Input Format
The first line contains an integer ‘T’ denoting the number of independent test cases.

For each test case the input has three lines:

An integer ‘n’ denoting the length of the linked list.
n space-separated integers denoting elements of the linked list.
Two integers: left and right.
Output Format
For each test case, a line containing ‘n’ space-separated integers denoting the resultant linked list elements.

Sample Input
3
4
1 5 7 13
2 4
4
1 5 7 13
2 3
4
1 5 7 13
3 3
Expected Output
1 13 7 5
1 7 5 13
1 5 7 13