/* **********************************
* 
* Linked List Iterator
*
* By Javier Llerensa
*
** ******************************* */

#include <iostream>
using namespace std;

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
