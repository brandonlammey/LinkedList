/*
 * File Name: PreconditionViolationException.cpp
 * Author: Brandon Lammey 
 * Description: Implemetation of PreconditionViolationException class
 */

#include "PreconditionViolationException.h"
//class PreconditionViolationException: public std::runtime_error

PreconditionViolationException::PreconditionViolationException(const char* message): std::runtime_error(message)
{
}

