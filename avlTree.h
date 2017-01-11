// *****************
// avl tree
// *****************/

#ifndef H_AVLTREE
#define H_AVLTREE

#include "tree.h"
#include <iostream>
using namespace std;


template <class T>
class avlTree : public tree<T> {
  public:
    avlTree();
    //Constructor
	
    void insert(const T item);
    //Function to insert an element into the tree
    //Postcondition: the element is inserted

    
	
 protected:
    int getBalance(treeNode<T>* nd);
    //Support function that determines the balance of a given node
    //Postcondition: the balance of the current node is returned;
	
    treeNode<T>* leftRotate(treeNode<T>* nd);
    //Support function that aids in insertion and deletion of nodes.
	
    treeNode<T>* rightRotate(treeNode<T>* nd);
    //Support function that aids in insertion and deletion of nodes.

    
 private:
    treeNode<T>* insert(treeNode<T>* nd, const T item);
    //Function to recursively insert an element into the tree
    //Postcondition: the element is inserted
     
};


// ----------------------
// Implementation

template <class T>
avlTree<T>::avlTree() : tree<T>()
//Constructor
{				
	this->nodeCount = 0;
}

template <class T>
void avlTree<T>::insert(const T item)
//Function to insert an element into the tree
//Postcondition: the element is inserted
{
	this.root = insert(this.root, item);
}		

template <class T>
treeNode<T>* avlTree<T>::insert(treeNode<T>* nd, const T item)
//Function to recursively insert an element into the tree
//Postcondition: the element is inserted
{
	if (nd == NULL) {			// Default
		nd = new treeNode<T>;
		nd->item = item;
		nd->left = NULL;
		nd->right = NULL;
		return nd;
	}
	
	if (item < nd->num)			
		nd->left = insert(nd->left, item);	  //Rec. Left
	else					
		nd->right = insert(nd->right, item);  //Rec. Right
	
	int bal = getBalance(nd);
	
	//Check for balance cases
	if (bal > 1 && item < nd->left->num)
		return rightRotate(nd);
	
	if (bal < -1 && item > nd->right->num)
		return leftRotate(nd);
	
	if (bal > 1 && item > nd->left->num) {
		nd->left = leftRotate(nd->left);
		return rightRotate(nd);
	}
	
	if (bal < -1 && item < nd->right->num) {
		nd->right = rightRotate(nd->right);
		return leftRotate(nd);
	}
	
	return nd;
}

template <class T>
treeNode<T>* avlTree<T>::leftRotate(treeNode<T>* nd)
//Support function that aids in insertion and deletion of nodes.
{
	treeNode<T> *tmp;
    treeNode<T> *y;
	
	y = nd->right;
	tmp = y->left;
	
	y->left = nd;
	nd->right = tmp;
	
	return y;	
}	

template <class T>
treeNode<T>* avlTree<T>::rightRotate(treeNode<T>* nd)
//Support function that aids in insertion and deletion of nodes.
{
	treeNode<T> *tmp;
    treeNode<T> *y;
	
	y = nd->left;
	tmp = y->right;
	
	y->right = nd;
	nd->left = tmp;
	
	return y;
}	

template <class T>
int avlTree<T>::getBalance(treeNode<T>* nd) 
//Function that determines the balance of a given node
//Postcondition: the balance of the current node is returned;
{	
	return (this->height(nd->left) - this->height(nd->right));
}

#endif //H_AVLTREE
