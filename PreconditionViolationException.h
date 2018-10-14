/*
 * File Name: PreconditionViolationException.h
 * Author: Brandon Lammey 
 * Description: this class inherits from std::runtime_error. This class will catch basic exceptions and 
 * will take in a message to output if an exception is encountered. 
 */

#ifndef PRECONDITIONVIOLATEDEXCEPTION_H
#define PRECONDITIONVIOLATEDEXCEPTION_H

#include<string>
#include<iostream>
#include<stdexcept>

using namespace std;

class PreconditionViolationException: public std::runtime_error
{	
	public:
	//constructor 
	PreconditionViolationException(const char* message);
};

#endif
