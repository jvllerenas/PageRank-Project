/* **********************************
* 
* Unordered Linked List
*
* By Javier Llerensa
*
** ******************************* */

#ifndef H_LINKEDLIST
#define H_LINKEDLIST
 
#include "linkedListIterator.h"
using namespace std;
 

template<class Type>
class unorderedLinkedList {
protected:
	node<Type> *head;	//pointer to the first node
	int count;			//count of numebr of nodes
	
public:	
	unorderedLinkedList();
		//default constructor.
		//initializes the list to an empty state
		//Postcondition: first = NULL, count = 0;
		
	~unorderedLinkedList();
		//destructor
		//deletes all elements in  the list
		//Postcondition: list is destroyed

	void destroyList();
		//Function to set the list to an empty state
		//Postcondition: list is destroyed, count = 0;
	
	void insert(Type newItem);
		//Function to insert newItem in the list
		//Postcondition: head points to the newItem in the list
		//		    	 count++;
					
	void deleteNode(Type target);
		//Function that deletes item from the list
		//Postcondition: If found, element is removed, and
		//				 count--;
		
	bool search(Type target);
		//Function to check if a given element appears in the list
		//Postcondition: Returns TRUE if found, FALSE otherwise
	
	linkedListIterator<Type> begin() const;
		//Function to return an iterator at the beginning of the list
		//Postcondition: Returns an iterator s.t. curr is set to 'head'

	linkedListIterator<Type> end() const;
		//Function to return an iterator at the end of the list
		//Postcondition: Returns an iterator s.t. curr is set to NULL
		
	bool isEmpty() const;
		//Function to determine is the list is empty
		//Postcondition: Returns TRUE if the list is empty, FALSE otherwise
		
	int length() const;
		//Function that returns the length of the list
		//Postcondition: Value of 'count' is returned
		
	void print() const;
		//Function to output the data in the list
		//Postcondition: none
};

#include "unorderedLinkedList.cpp"
#endif //H_LINKEDLIST
