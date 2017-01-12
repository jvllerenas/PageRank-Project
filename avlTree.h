/* **********************************
* 
*  Definition of an avlTree
*
*  By Javier Llerenas
*
** ******************************* */

#ifndef H_AVLTREE
#define H_AVLTREE

#include "tree.h"
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

#include "avlTree.cpp"
#endif //H_AVLTREE
