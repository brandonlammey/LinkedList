/*
 * File Name: Node.h
 * Author: Brandon Lammey 
 * Description: This node class will create a node object that will hold a templated type T and contain
 * a pointer to another which is initially set to null. Methods contain allow to set the pointer, get
 * the next next node the pointer is pointing too, set the type T in the node, and get the type T in
 * the node. 
 */

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
	private:
	T m_value;	//value in the node 
	Node<T>* m_next;	//pointer to another node

	public:
	//constructor for each node includes a value and a pointer to another node	
	Node();

	//set and get methods for the value within the node
	void setValue(T val);
	T getValue() const;
	
	//set and get methods for the pointer of each node 
	void setNext(Node<T>* prev);
	Node<T>* getNext() const;
};

#include "Node.hpp" 
#endif
