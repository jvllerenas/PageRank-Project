/* **********************************
* 
* Unordered Linked List
*
* By Javier Llerensa
*
** ******************************* */

#include <iostream>
using namespace std;


template<class Type>
unorderedLinkedList<Type>::unorderedLinkedList()
	//default constructor.
{
    count = 0;
    head = NULL;
}
	
	
template<class Type>	
unorderedLinkedList<Type>::~unorderedLinkedList()
	//destructor
{
	destroyList();
	head = NULL;
}

template<class Type>
void unorderedLinkedList<Type>::destroyList()
	//Function to set the list to an empty state
	//Postcondition: list is destroyed, count = 0;
{
    node<Type> *tmp;         //pointer to deallocate mem
    
    while (head != NULL) {
	tmp = head;         //set tmp to head
	head = head->link;  //advance head
	delete tmp;         //delete tmp
    }
	head = NULL;
    count = 0;
}
		
	
template<class Type>	
void unorderedLinkedList<Type>::insert(Type newItem)
	//Function to insert newItem in the list
	//Postcondition: head points to the newItem in the list
	//		    	 count++;
{
    node<Type> *newNode;

    newNode = new node<Type>;
    
    newNode->info = newItem;  //store newItem 
    newNode->link = head;     //set the newNode point to the head
 
    head = newNode;           //set newNode be the new head

    ++count;
}
	
template<class Type>
void unorderedLinkedList<Type>::deleteNode(Type target)
	//Function that deletes item from the list
	//Postcondition: If found, element is removed, and
	//				 count--;
{
    node<Type> *curr;
    node<Type> *trailCurr;
    bool found;
    
    if (count == 0) return;  //if EMPTY, cannot delete;
    else {//A
	
	if (head->info == target) { //if is the first element
	    curr = head;
	    head = head->link;
	    count--;
	    delete curr;

	} else {//B
	    found = false;
	    trailCurr = head;
	    curr = head->link;

	    while (curr != NULL && !found) {

		if (curr->info != target) {
		    trailCurr = curr;
		    curr = curr->link;
		} else
		    found = true;
	    }//end while

	    if(found) {
		trailCurr->link = curr->link;
		count--;
		delete curr;
	    } else
		cout << "Item was not found\n\n";
	}//end B
    }//end A 
}

template<class Type>	
bool unorderedLinkedList<Type>::search(Type target)
	//Function to check if a given element appears in the list
	//Postcondition: Returns TRUE if found, FALSE otherwise
{
    bool found = false; //var to return
    node<Type> *curr;   //pointer to traverse the list

    curr = head;

    while (curr != NULL && !found)  //if not end of list AND not found
	if (curr->info == target)   //if found
	    found = true;
        else                        //else advance curr
	    curr = curr->link;
    
    return found;		
}

template<class Type>	
linkedListIterator<Type> unorderedLinkedList<Type>::begin() const
	//Function to return an iterator at the beginning of the list
	//Postcondition: Returns an iterator s.t. curr is set to 'head'
{
	linkedListIterator<Type> temp(head);
	
	return temp;
}

template<class Type>		
linkedListIterator<Type> unorderedLinkedList<Type>::end() const
	//Function to return an iterator at the end of the list
	//Postcondition: Returns an iterator s.t. curr is set to NULL
{
	linkedListIterator<Type> temp(NULL);
    
	return temp;
}
	
template<class Type>	
bool unorderedLinkedList<Type>::isEmpty() const
	//Function to determine is the list is empty
	//Postcondition: Returns TRUE if the list is empty, FALSE otherwise
{
  return (count == 0);
}

template<class Type>
int unorderedLinkedList<Type>::length() const
	//Function that returns the length of the list
	//Postcondition: Value of 'count' is returned
{
  return count;
}

template<class Type>
void unorderedLinkedList<Type>::print() const
	//Function to output the data in the list
	//Postcondition: none
{
	node<Type> *curr;
	curr = head;
	
	cout << "List: \n";
	
	while (curr != NULL) {
		cout << curr->info << " ";
		curr = curr->link;
	}
	cout << endl;	
}
