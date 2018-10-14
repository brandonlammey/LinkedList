/*
 * File Name: LinkedList.h
 * Author: Brandon Lammey 
 * Description: This linked list contains two variables. The initial pointer to the first node and the
 * size of the list. The linked list contains methods to check if the list is empty, check size of list, 
 * search for a specific value in held by the nodes, print list, add, and remove nodes. 
 */



#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h" 


#include <vector>

template<typename T>
class LinkedList: public ListInterface<T>
{
	private:
		//private memory variables 		
		Node<T>* m_headPtr;
		int m_size; 
		Node<T>* getNodeAt(int position) const; 
		
	public: 
		//constructor and deconstructor 		
		LinkedList();
		LinkedList(const LinkedList<ItemType>& aList); 
		~LinkedList();
		
		//returns true if list is empty
		//returns false otherwise
		bool isEmpty() const; 
		
		//returns size of the linked list
		int getSize() const; 

		//returns true if the value exists in any node
		//returns false otherwise
		bool search(T value) const; 


		/** @throw PrecondViolatedExcep if position < 1 or position > getLength(). */
		T getEntry(int position) const throw(PreconditionViolationException);
		void setEntry(int position, const T& newEntry) throw(PreconditionViolationException); 

		//adds 1 new node to List 
		//increments size
		void insertBack(const T& newEntry);
		void insertFront(const T& newEntry);
	
		//removes 1 node to back or front of the list
		//decrements size
		bool removeBack();
		bool removeFront(); 
		bool removeEntry(int position);
		void clear(); 

		//creates new vector 
		//copy contents of list into vector
		//returns a standard vector with the contents of the list inside
		//used by test class to varify contents of list 
		std::vector<int> toVector() const;
};
#include "LinkedList.hpp"
#endif
