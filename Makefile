SwitchTwoElementInList: SwitchTwoElementInList.o
	g++ -g -o SwitchTwoElementInList.exe SwitchTwoElementInList.o -pthread    

SwitchTwoElementInList.o: SwitchTwoElementInList/SwitchTwoElementInList.cpp
	g++ -g  -c -pthread SwitchTwoElementInList/SwitchTwoElementInList.cpp
