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
#include "PreconditionViolationException.h" 
#include <vector>

template<typename T>
class LinkedList: public ListInterface<T>
{
	private:
		//private memory variables 		
		Node<T>* m_headPtr;
		int m_length; 

		//internal use only for getting positions within the Linked List
		Node<T>* getNodeAt(int position) const; 
		
	public: 
		//constructor and deconstructor 		
		LinkedList();
		LinkedList(const LinkedList<T>& aList); 
		~LinkedList();
		
		//returns true if list is empty
		//returns false otherwise
		bool isEmpty() const; 
		
		//returns size of the linked list
		int getLength() const; 

		//returns true if the value exists in any node
		//returns false otherwise
		bool search(T value) const; 

		/** @throw PrecondViolatedExcep if position < 1 or position > getLength(). */
		//Get entry at selected position
		//@return: Value of type T in node at selected position
		T getEntry(int position) const throw(PreconditionViolationException);

		/** @throw PrecondViolatedExcep if position < 1 or position > getLength(). */
		//Set entry at selected position
		//@return:
		void setEntry(int position, const T& newEntry) throw(PreconditionViolationException); 

		//insert node at select position
		//@return: bool to determine if inserted or not 
		bool insert(int position, const T& newEntry);
	
		//remove node at select position 
		//@return: bool to determine if removed or not 
		bool remove(int position);

		//remove all nodes from list
		//@return: bool to determine if removed or not 
		void clear(); 

		//creates new vector 
		//copy contents of list into vector
		//returns a standard vector with the contents of the list inside
		//used by test class to varify contents of list 
		std::vector<T> toVector() const;
};
#include "LinkedList.hpp"
#endif
