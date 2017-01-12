/* **********************************
* 
* Linked List Iterator
*
* By Javier Llerensa
*
** ******************************* */

#ifndef H_ITERATOR
#define H_ITERATOR
 
#include <iostream>
using namespace std;

template<class Type>
struct node {
    Type info;
    node<Type> *link;
};

template<class Type>
class linkedListIterator {
 private:
    node<Type> *curr;

 public:
    linkedListIterator();
		//default constructor
		//Postcondition: curr = NULL
		
    linkedListIterator(node<Type> *ptr);
		//Constructor with a parameter
		//Postcondition: curr = ptr
	
	Type operator*();
		//Function  to overload the deferencing operator
		//Postcondition: Returns the info contained in the curr node
	  
	linkedListIterator<Type> operator++();
		//Overload the pre-increment operator
		//Postcondition: iterator is advanced to the next element
	  
	bool operator==(const linkedListIterator<Type>& right) const;
		//Overload the equality operator
		//Postcondition: ret TRUE if equal, FALSE otherwise
	  
	bool operator!=(const linkedListIterator<Type>& right) const;
		//Overload the not equal operator
		//Postcondition: ret TRUE if not equal, FALSE otherwise

};

#include "linkedListIterator.cpp"
#endif //H_ITERATOR
