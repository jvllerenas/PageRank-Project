/* **********************************
* 
*  Definition of a custom version of an avlTree
*  that maintains only the largest elements in 
*  the tree, up to a LIMIT number of elements
*
*  The purpose of this data structure is to 
*  be able to efficiently sort a list of elements
*  and print the LIMIT amount of greatest elements
*
*  By Javier Llerenas
*
** ******************************* */

#ifndef H_AVLWEB
#define H_AVLWEB

#include "avlTree.h"
using namespace std;


struct rankNode {
    long double pr;
    unsigned pn;
};


class avlWeb : public avlTree<rankNode> {
 public:

    avlWeb(int limit = 300);
    //Default constructor.
    //Postcondition: Limit equals to the passed arg, ortherwise -1

    bool isFull() const;
    //Function that determines if the tree is full
    //Postcondition: Return TRUE if nodeCount = limit,
    //    FALSE otherwise
    
    void deleteMax();
    //Function that finds and returns the rightmost node
    //Postcondition: The rightmost node is deleted and nodeCount--

    void insert(const long double pr, const unsigned pg);
    //Function that inserts item into the tree
    //Postcondition: the item is added and nodeCount++

    void print();
    //Function that prints the webpages in a formatted manner
    //Postcondition: The webpages are displayed to the console

    void printLimit();
    
 private:
    long double maxNode;
    int limit;

    treeNode<rankNode>* insert(treeNode<rankNode>* nd, const rankNode item);
    //Function to recursively insert an element into the tree
    //Postcondition: the element is inserted

    treeNode<rankNode>* deleteMax(treeNode<rankNode>* nd);
    //Function to recursively insert anl ement into the tree
    //Postcondition: the element is inserted

    void print(treeNode<rankNode>* nd);
    //Function thatrecursively prints the webpages
    //Postcondition: The webpages are displayed to the console

};

#endif //H_AVLWEB
