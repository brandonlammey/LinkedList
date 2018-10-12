/*
 * File Name: main.cpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 03
 * Description: 
 */

#include <string>
#include "Test_LinkedList.h"

int main(int argc, char** argv)
{ 
        int testSize = std::stoi(argv[1]); //convert from char* to int
        Test_LinkedList tester(testSize); //create a tester
        tester.runTests(); //run tests
        return (0);
}
