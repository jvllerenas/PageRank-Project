/* **********************************
* 
*  Custom Directed Graph for Page Rank
*
*  This data structure makes use of a modified version of
*  and adjacency list. 
*		
*  For an index I in the array, the nodes in the unorderedLinkedList 
*  represent the webpages that point to element I.
*
*  In addition, an extra unorderedLinkedList is used for the set of
*  Sink nodes.
* 
* 
*  By Javier Llerenas
*
** ******************************* */

#ifndef H_WEBGRAPH
#define H_WEBGRAPH
 
#include <iostream>
#include "unorderedLinkedList.h"
#include "avlWeb.h"
using namespace std;

const int LIMIT = 10;


struct webNode {
	long double pr;
	long double newPR;
	short outLinks;
	unorderedLinkedList<unsigned> inLinks;
};


class webGraph {
 private:
    string title;
    unsigned int vertexCount;
    unsigned int edgeCount;
    webNode *webpages;
    unorderedLinkedList<unsigned> sinkSet;
	
    static constexpr float d = 0.85;
    avlWeb rankedPages;
	
 public:
    webGraph();
    //Default Constructor
    //Initializes all elements to an empty State
    //Postcondition: title = "", vertexCount = 0, edgeCount = 0
    //    webpages = NULL, sinkSet is empty
	
    ~webGraph();
    //Destructor
    //Deletes all elements if the graph
    //Postcondition: the graph and linkedList are destroyed
    
    bool readGraph(string filename);
    //Function that attempts to open a given file, reads the data, 
    //populates the graph, and sets the sinkSet
    //Postcondition: title is set, vertexCount is set, edgeCount is set,
    //    webpages is set, with an initial pr of 0
    //    sinkSet is set
	
    void showGraphStats();
    //Function that outputs the graph's stats
    //Postcondition: Title, edgeCount, and vertexCount are diplayed
    
    void findPageRanks();
    //Function that computes the page rank of  every webpage in 'webpages'
    //by using 1989's PageRank algorithm
    //Postcondition: the 'pr' of every node in webpages is set
    //Precondition: readGraph() must have previously been executed
    
    void displayPageRanks(int number);
    //Function that displays LIMIT number of webpages in decreasing order
    //based on their pr;
    //Postcondition: LIMIT number of webpages are displayed to screen
    //Precondition: findPageRanks() must have previously been executed
    
    void print() const;
};

#endif //H_WEBGRAPH
