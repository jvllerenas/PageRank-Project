/* **********************************
* 
*  Implementation of the tree d.s.
*
*  By Javier Llerenas
*
** ******************************* */

#include <iostream>

template <class T>
tree<T>::tree()
//Constructor.
{
	nodeCount = 0;
	root = NULL;
}		

template <class T>
tree<T>::~tree()
//Destructor
{
	destroyTree(root);
}		

template <class T>
void tree<T>::destroyTree()
//Deallocates the memory used
//Postcondition: root = NULL
{
	destroyTree(root);
}		

template <class T>
int tree<T>::height() 
//Function to determine the height of a given tree.
//Postcondition: the height is returned;
{
	return height(root);
}		

template <class T>
bool tree<T>::isEmpty() const
//Function  to determine if tree is empty
//Postcondition: return  TRUE if empty, FALSE toehrwise
{
	return (root == NULL);
}		

template <class T>
int tree<T>::getNodeCount() const
//Function  to return the number of nodes in the tree
//Postcondition: returns num of nodes.
{
	return nodeCount;
}		

template <class T>
void tree<T>::print() 
//Function that outputs the nodes  in an inorder sequence
//Postcondition: nodes are displayed
{
	print(root);
}		


//==================================================================
//==================================================================

template <class T>
void tree<T>::destroyTree(treeNode<T>* nd)
//Function that recursively destroys the tree that nd points to
//Postcondition: All nodes under nd are deallocated, nd = NULL
{
	if (nd != NULL) {
		destroyTree(nd->left);  //del. left
		destroyTree(nd->right); //del. right
		delete nd;              //del. root
		nd = NULL;
	}
}		

template <class T>
void tree<T>::print(treeNode<T>* nd)
//Function that recursively prints the nodes in an  inorder sequence
//Postcondition: nodes are printed in an inorder sequence
{
	if (nd != NULL) {
		print(nd->left);          //left
        
		cout << nd->info << endl; //root
		
		print(nd->right);         //right
	}
}		

template <class T>
int tree<T>::height(treeNode<T>* nd)
//Function that recursively obtains the height of a given node
//Postcondition: the height of the tree to which nd points to is returned
{
	if (nd == NULL) return 0;
	else return 1 + max( height(nd->left), height(nd->right) );
}		

template <class T>
int tree<T>::max(int x, int y)
//Function that determines the max of two given integers
//Postcondition: thelarger of x, y is returned
{
	return (x > y)? x : y;
}

template <class T>
double tree<T>::max(double x, double y)
//Same max function, with doubles
//Postcondition: the larger of x, y is returned	
{
    return (x > y)? x : y;
}

template <class T>
long double tree<T>::max (long double x, long double y)
//Same max function, with doubles
//Postcondition: the larger of x, y is returned	
{
   return (x > y)? x : y;
}
