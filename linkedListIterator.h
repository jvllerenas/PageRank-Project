
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

#ifndef H_NODETYPE
#define H_NODETYPE
template<class Type>
struct node {
    Type info;
    node<Type> *link;
};
#endif // H_NODETYPE

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

// IMPLEMENTATIONS
template<class Type>
linkedListIterator<Type>::linkedListIterator()
	//default constructor
	//Postcondition: curr = NULL
{
	curr = NULL;
}
  
template<class Type>
linkedListIterator<Type>::linkedListIterator(node<Type> *ptr)
	//Constructor with a parameter
	//Postcondition: curr = ptr
{
	curr = ptr;
}
  
template<class Type>
Type linkedListIterator<Type>::operator*()
	//Function  to overload the derencing operator
	//Postcondition: Returns the info contained in the curr node
{
	return curr->info;
}
  
template<class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
	//Overload the pre-increment operator
	//Postcondition: iterator is advanced to the next element
{
	curr = curr->link;
	
	return *this;
}
  
template<class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
	//Overload the equality operator
	//Postcondition: ret TRUE if equal, FALSE otherwise
{
	return (curr == right.curr);
}
	  
template<class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
	//Overload the not equal operator
    //Postcondition: ret TRUE if not equal, FALSE otherwise
{
	return (curr != right.curr);
}

#endif //H_ITERATOR