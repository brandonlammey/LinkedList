/*
 * File Name: LinkedList.hpp
 * Author: Brandon Lammey 
 * Description: Implementation of LinkedList class. 
 */


template<typename T>	
Node<T>* LinkedList<T>::getNodeAt(int position) const
{
	assert((position >= 1) && position<=m_length);

	//traverse list
	Node<T>* tempNodePtr = m_headPtr;
	
	for(int i = 1; i < position; i++)
	{
		tempNodePtr = tempNodePtr->getNext();
	}
	//return pointer to item at position
	return(tempNodePtr);
}

template<typename T>	
LinkedList<T>::LinkedList()
{
	m_headPtr= nullptr; 
	m_length = 0; 
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& aList)
{

}

template<typename T>
LinkedList<T>::~LinkedList()
{
	//deletes all nodes in the list avoid memory errors
	if(isEmpty())
	{
		m_headPtr = nullptr;
	}
	else
	{
		clear();
	}
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
	//returns true if list is empty
	//returns false otherwise
	if(m_length == 0)
	{
		return(true);
	}
	else
	{
		return(false); 
	}
}

template<typename T>
int LinkedList<T>::getLength() const
{
	return(m_length); 
}

template<typename T>
bool LinkedList<T>::search(T value) const
{
	//pointer to headnode
	Node<T>* tempNodePtr = m_headPtr; 

	//returns true if the value exists in any node
	//returns false otherwise
	if(m_length == 0)
	{
		return(false);
	}
	else
	{
		//check n-1 nodes
		while(tempNodePtr-> getNext() != nullptr)
		{
			if(tempNodePtr -> getValue() == value)
			{
				return(true);			
			}
			tempNodePtr = tempNodePtr -> getNext();			
			
		}
		
		//check last node 
		if(tempNodePtr -> getValue() == value)
		{
				return(true);			
		}
		return(false);
	}
} 

template<typename T>
T LinkedList<T>::getEntry(int position) const throw(PreconditionViolationException)
{
	//start linked list at index 1
	//if out of bounds throw error
	if(position < 1 || position > m_length)
	{
		throw PreconditionViolationException("Invalid position!");
	}

	//traverse list
	Node<T>* tempNodePtr = getNodeAt(position);
	return(tempNodePtr -> getValue());
}

template<typename T>
void LinkedList<T>::setEntry(int position, const T& newEntry) throw(PreconditionViolationException)
{
	//start linked list at index 1
	//if out of bounds throw error
	if(position < 1 || position > m_length)
	{
		throw PreconditionViolationException("Invalid position!");
	}
	Node<T>* tempNodePtr = getNodeAt(position);
	tempNodePtr->setValue(newEntry);

} 

template<typename T>
bool LinkedList<T>::insert(int position, const T& newEntry)
{
	//return false if not valid position
	if(position<1 || position>m_length)
	{
		return false;
	}

	Node<T>* tempNodePtr = new Node<T>();
	tempNodePtr->setValue(newEntry);

	if(position == 1)
	{
		//set new node to point to previous head
		//set head to new node
		tempNodePtr -> setNext(m_headPtr);
		m_headPtr = tempNodePtr;
	}
	else
	{
		//get previous node to position
		//set new node pointer to node at current position
		//set previous node pointer to new node
		Node<T>* prevPtr = getNodeAt(position-1);
		tempNodePtr-> setNext(prevPtr->getNext());
		prevPtr->setNext(tempNodePtr);
	}
	m_length++;
	return true;
}

template<typename T>
bool LinkedList<T>::remove(int position)
{
	//start linked list at index 1
	//if out of bounds throw error
	if(position < 1 || position > m_length)
	{
		return false;
	}

	//traverse list
	Node<T>* tempNodePtr = getNodeAt(position);
	if(position == 1)
	{
		//set head to next pointer
		m_headPtr = m_headPtr->getNext();
	}
	else
	{
		//set previous node to node after position
		Node<T>* prevPtr = getNodeAt(position-1);
		prevPtr->setNext(tempNodePtr->getNext());

	}

	delete tempNodePtr;
	m_length--;
	return true;
	


}

template<typename T>
void LinkedList<T>::clear()
{
	while(!isEmpty())
	{
		remove(1);
	}
} 

template<typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> listContents;//creates new vector to hold values
	

	if(m_headPtr != nullptr)
	{
		Node<T>* tempNodePtr = m_headPtr; 
				
		for(int i=0; i<m_length; i++)//traverse list and input values into vector
		{
			listContents.push_back(tempNodePtr->getValue());
			tempNodePtr = tempNodePtr->getNext(); 
		}
		
	}

	return(listContents); 
}