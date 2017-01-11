// *****************
// avl WEB
// *****************/

#include "avlWeb.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ------------------------
// Implementation


avlWeb::avlWeb(int limit) : avlTree<rankNode>()
//Default constructor.
//Postcondition: Limit equals to the passed arg, ortherwise -1
{
    this->limit = limit;
    maxNode = 0;
}


bool avlWeb::isFull() const
//Function that determines if the tree is full
//Postcondition: Return TRUE if nodeCount = limit,
//    FALSE otherwise
{
    return (nodeCount >= limit);
}

void avlWeb::deleteMax()
//Function that finds and returns the rightmost node
//Postcondition: The rightmost node is deleted and nodeCount--
{
    this->root = deleteMax(this->root->right);
    nodeCount--;
}

void avlWeb::insert(const long double pr, const unsigned int pn)
//Function that inserts item into the tree
//Postcondition: the item is added and nodeCount++
{
    if (!this->isFull()) {
        cout << "Tree is NOT full; inserting " << pr << endl;

        rankNode rn;
        rn.pr = pr;
        rn.pn = pn;
            
        this->root = insert(this->root, rn);

        maxNode = max(maxNode, pr);

        nodeCount++;
        cout << "Nodecount is now: " << nodeCount << endl;
    } else if (maxNode < pr) {
        cout << "Tree is FULL; but max: " << maxNode
             << " is greater than pr: " << pr << endl;
        deleteMax();
        
        rankNode rn;
        rn.pr = pr;
        rn.pn = pn;
        
        this->root = insert(this->root, rn);
        maxNode = max(maxNode, pr);
        
        nodeCount++;
        cout << "Nodecount is now: " << nodeCount << endl;
    } 
}
    
void avlWeb::print()
//Function that prints the webpages in a formatted manner
//Postcondition: The webpages are displayed to the console
{
    if (this->root != NULL) {
        cout << "Page Ranks: " << endl
             << "------------" << endl;
        cout << right << fixed << setprecision(15)
             << setw(5) << "Rank"
             << setw(10) << "Page"
             << setw(25) << "Rank Value" << endl;
        
        print(this->root);
    }
}

// =============================================
// =============================================


treeNode<rankNode>* avlWeb::insert(treeNode<rankNode>* nd,
                                              const rankNode item)
//Function to recursively insert an element into the tree
//Postcondition: the element is inserted
{
    
	if (nd == NULL) {			// Default
		nd = new treeNode<rankNode>;
		nd->item = item;
		nd->left = NULL;
		nd->right = NULL;
		return nd;
	}
	
	if (item.pr < nd->item.pr)			
		nd->left = insert(nd->left, item);	  //Rec. Left
	else					
		nd->right = insert(nd->right, item);  //Rec. Right
	
	int bal = getBalance(nd);
	
	//Check for balance cases
	if (bal > 1 && item.pr < nd->left->item.pr) {
        //        cout << "\tRIGHT rotation" << endl;
		return rightRotate(nd);
	}
	if (bal < -1 && item.pr > nd->right->item.pr) {
        //        cout << "\tLEFT rotation" << endl;
        return leftRotate(nd);
    }
	if (bal > 1 && item.pr > nd->left->item.pr) {
        //        cout << "\tL-R rotation" << endl;
        nd->left = leftRotate(nd->left);
		return rightRotate(nd);
	}
	
	if (bal < -1 && item.pr < nd->right->item.pr) {
        //        cout << "\tR-L rotation" << endl;
		nd->right = rightRotate(nd->right);
		return leftRotate(nd);
	}
	
	return nd;
}

treeNode<rankNode>* avlWeb::deleteMax(treeNode<rankNode>* nd)
//Function to recursively insert an element into the tree
//Postcondition: the element is inserted
{
    if (nd->right->right == NULL)
        maxNode = nd->item.pr;       //get new max

    if (nd->right == NULL) {      //if is the last node

        treeNode<rankNode> *tmp;
        tmp = nd->left;  //save left node
        
        delete nd;       //delete max node
        nd = NULL;
        return tmp;      //return left

    } else nd->right = deleteMax(nd->right); //recurse right
}

void avlWeb::print(treeNode<rankNode>* nd)
//Function thatrecursively prints the webpages
//Postcondition: The webpages are displayed to the console
{
    static short rank = 0;
    
    if (nd == NULL)
        return;
    
    print(nd->right);
    
    cout << setw(5) << ++rank
         << setw(10) << nd->item.pn
         << setw(25) << nd->item.pr
         << endl;
    
    print(nd->left);
}

void avlWeb::printLimit()
{
    cout << "LIMIT: " << limit << endl
         << "NodeC: " << this->nodeCount << endl << endl;
}
