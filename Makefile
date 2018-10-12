LinkedList: main.o Test_LinkedList.o Test.o
	g++ -std=c++11 -g -Wall main.o Test_LinkedList.o Test.o -o LinkedList

main.o: main.cpp Test_LinkedList.h Node.h LinkedList.h
	g++ -std=c++11 -g -Wall -c main.cpp

Test_LinkedList.o: Test_LinkedList.h Test_LinkedList.cpp LinkedList.h Test.h
	g++ -std=c++11 -g -Wall -c Test_LinkedList.cpp

Test.o: Test.h Test.cpp
	g++ -std=c++11 -g -Wall -c Test.cpp

clean:
	rm *.o LinkedList
