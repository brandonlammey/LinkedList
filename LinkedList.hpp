/*
 * File Name: LinkedList.cpp
 * Author: Brandon Lammey 
 * Description: Implementation of LinkedList class. 
 */



template<typename T>	
LinkedList<T>::LinkedList()
{
	m_headPtr= nullptr; 
	m_size = 0; 
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<ItemType>& aList)
{

}

template<typename T>
LinkedList<T>::~LinkedList()
{
	//deletes all nodes in the list avoid memory errors
	if(isEmpty())
	{
		m_front = nullptr;
	}
	else
	{
		Node<T>* tempNodePtr = m_headPtr; 
		
		while(m_headPtr->getNext() != nullptr)//loops until only one node remaining 
		{
			tempNodePtr = m_headPtr->getNext();//sets tempNode to point to the second Node
			delete(m_headPtr); //deletes the current front node
			m_headPtr = tempNodePtr; //new front is node behind first
		}
		//deletes final node
		delete(m_headPtr);
		m_headPtr = nullptr;
	}
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
	//returns true if list is empty
	//returns false otherwise
	if(m_size == 0)
	{
		return(true);
	}
	else
	{
		return(false); 
	}
}

template<typename T>
int LinkedList<T>::getSize() const;
{
	return(m_size); 
}

template<typename T>
bool LinkedList<T>::search(T value) const
{
	//pointer to headnode
	Node<T>* tempNodePtr = m_headPtr; 

	//returns true if the value exists in any node
	//returns false otherwise
	if(m_size == 0)
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
		if(tempNode -> getValue() == value)
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
	if(position < 1 || position > m_size)
	{
		throw PreconditionViolationException("Position does not exist!");
	}

	//traverse list
	Node<T>* tempNodePtr = m_headPtr;
	for(int i = 1; i< position; i++)
	{
		tempNodePtr->getNext();
	}
	return(tempNodePtr -> getValue())
}

template<typename T>
void LinkedList<T>::setEntry(int position, const T& newEntry) throw(PreconditionViolationException)
{

} 

template<typename T>
void LinkedList<T>::insertBack(const T& newEntry)
{

}

template<typename T>
void LinkedList<T>::insertFront(const T& newEntry)
{

}


template<typename T>
bool LinkedList<T>::removeBack()
{

}

template<typename T>
bool LinkedList<T>::removeFront()
{

} 

template<typename T>
bool LinkedList<T>::removeEntry(int position)
{

}

template<typename T>
void LinkedList<T>::clear()
{

} 

template<typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> listContents;//creates new vector to hold values
	

	if(m_front != nullptr)
	{
		Node<T>* tempNodePtr = m_headPtr; 
				
		for(int i=0; i<m_size; i++)//traverse list and input values into vector
		{
			listContents.push_back(tempNodePtr->getValue());
			tempNodePtr = tempNodePtr->getNext(); 
		}
		
	}

	return(listContents); 
}