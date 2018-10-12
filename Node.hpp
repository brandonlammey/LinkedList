/*
 * File Name: Node.hpp
 * Author: Brandon Lammey 
 * Description: Implementation of Node class. 
 */

template<typename T>
Node<T>::Node()
{
	m_next = nullptr; //sets pointer initially to null
	m_value = T(); //initilaizes to equivalent of 0
}


//set and get methods for the value within the node
template<typename T>
void Node<T>::setValue(T val)
{
	m_value = val;
}

template<typename T>
T Node<T>::getValue() const
{
	return(m_value);
}

//set and get methods for the Node pointers 
template<typename T>
void Node<T>::setNext(Node<T>* prev)
{
	m_next = prev;
}

template<typename T>
Node<T>* Node<T>::getNext() const
{
	return(m_next); 
}

