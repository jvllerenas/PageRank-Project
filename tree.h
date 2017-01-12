/* **********************************
* 
*  Simple Tree data structure.
*
*  By Javier Llerenas
*
** ******************************* */

#ifndef H_TREE
#define H_TREE

using namespace std;


template <class T>
struct treeNode {
	T item;
	treeNode *left;
	treeNode *right;
};

template <class T>
class tree {
  public:
    tree();
    //Constructor.
	
    ~tree();
    //Destructor
	
    void destroyTree();
    //Deallocates the memory used
    //Postcondition: root = NULL
	
    int height();
    //Function to determine the height of a given tree.
    //Postcondition: the height is returned;
	
    bool isEmpty() const;
    //Function  to determine if tree is empty
    //Postcondition: return  TRUE if empty, FALSE toehrwise
	
    int getNodeCount() const;
    //Function  to return the number of nodes in the tree
    //Postcondition: returns num of nodes.
	
    void print();
    //Function that outputs the nodes  in an inorder sequence
    //Postcondition: nodes are displayed
    
 protected:
    treeNode<T> *root;
    unsigned nodeCount;
    
    int height(treeNode<T>* nd);
    //Function that recursively obtains the height of a given node
    //Postcondition: the height of the tree to which nd points to is returned

    int max(int x, int y);
    //Function that determines the max of two given integers
    //Postcondition: the larger of x, y is returned	
    
    double max (double x, double y);
    //Same max function, with doubles
    //Postcondition: the larger of x, y is returned	
    
    long double max (long double x, long double y);
    //Same max function, with doubles
    //Postcondition: the larger of x, y is returned	

	
 private:
    void destroyTree(treeNode<T>* nd);
    //Function that recursively destroys the tree that nd points to
    //Postcondition: All nodes under nd are deallocated, nd = NULL
	
    void print(treeNode<T>* nd);
    //Function that recursively prints the nodes in an  inorder sequence
    //Postcondition: nodes are printed in an inorder sequence
    
        
};

#include "tree.cpp"
#endif //H_TREE
