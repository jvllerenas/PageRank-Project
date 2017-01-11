/* **********************************
* 
* Custom Directed Graph for Page Rank
*
* This data structure makes use of a modified version of
* and adjacency list. 
*		
*	For an index I in the array, the nodes in the unorderedLinkedList 
*		represent the webpages that point to element I.
*
*	In addition, an extra unorderedLinkedList is used for the set of
*		Sink nodes.
* 
* 
* By Javier Llerenas
*
** ******************************* */

#include "webGraph.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


webGraph::webGraph()
//Default Constructor
//Initializes all elements to an empty State
//Postcondition: title = "", vertexCount = 0, edgeCount = 0
//				 webpages = NULL, sinkSet is empty
{
	title = "";
	vertexCount = 0;
	edgeCount = 0;
	webpages = NULL;
	//sinkSet is already empty;
}

webGraph::~webGraph()
//Destructor
//Deletes all elements if the graph
//Postcondition: the graph and linkedList are destroyed
{
	for (int i = 0;  i < vertexCount; i++)
		webpages[i].inLinks.destroyList();
	
	delete [] webpages;
	webpages = NULL;
	
	sinkSet.destroyList();
}

bool webGraph::readGraph(string filename)
//Function that attempts to open a given file, reads the data, 
//populates the graph, and sets the sinkSet
//Postcondition: title is set, vertexCount is set, edgeCount is set,
//				 webpages is set, sinkSet is set
{
	ifstream in;
	in.open(filename.c_str());
	string tmp;
	int from,  to;
	
	if (!in.good())
		return false;
	else {
        in.ignore(256, '\n'); 	//ignores first line;
        getline(in, title);    	//gets the title
        in >> tmp >> tmp;		
        in >> vertexCount;		//gets vertexCount
        in >> tmp;
        in >> edgeCount;		//gets edgeCount
        
        in.ignore();			//ignores \n
        in.ignore(256, '\n'); 	//ignores 4th line
        
        webpages = new webNode[vertexCount];
        for (int i = 0; i < vertexCount; ++i) 
            webpages[i].outLinks = 0; 		//Set outLinks to 0
        
        // Populate webpages graph
        in >> from >> to;
        while (in.good()) {
            
            if (from != to) { 			//To avoid SELF-LINKS
                webpages[from].outLinks++;
                webpages[to].inLinks.insert(from);
            }
            
            in >> from >> to;
        }
        
        //set SinkSet
        for (int i = 0; i < vertexCount; i++) 
            if (webpages[i].outLinks == 0) {
                sinkSet.insert(i);
            }
    }
	return true;
}

void webGraph::showGraphStats() 
//Function that outputs the graph's stats
//Postcondition: Title, edgeCount, and vertexCount are diplayed
{
	cout << "Graph Statistics: \n"
		 << "\tTitle: " << title << endl
		 << "\tNodes: " << vertexCount << endl
		 << "\tEdges: " << edgeCount << endl << endl;

    rankedPages.printLimit();
    
}

void webGraph::findPageRanks()
//Function that computes the page rank of  every webpage in 'webpages'
//by using 1989's PageRank algorithm
//Postcondition: the 'pr' of every node in webpages is set
//Precondition: readGraph() must have previously been executed
{
	double sinkPR;
	double tmp = 1.0 / double(vertexCount);
	linkedListIterator<unsigned> curr1;
	linkedListIterator<unsigned> curr2;
    linkedListIterator<unsigned> end;

	//initial setup
	for (int i=0; i < vertexCount; i++)		
		webpages[i].pr = tmp;

    
	//while pagerank has not converged
	for (int i = 0; i < 100; i++) {	
        
		sinkPR = 0;
		
		//LOOP1. For each page in SinkSet
		curr1 = sinkSet.begin();
        end = sinkSet.end();
		while (curr1 != end) {		//calculate total sink PR
            sinkPR += webpages[(*curr1)].pr;
			++curr1;
		}
        
		//LOOP2. For each page in webpages
		for (int k = 0; k <  vertexCount; k++) 
            {	
                webpages[k].newPR = (1 - double(d)) / double(vertexCount);		//damping
                webpages[k].newPR += d * sinkPR / double(vertexCount);	//spread sinkPRevenly
                
                //For each INLINK to 'k'
                curr2 = webpages[k].inLinks.begin();
                while (curr2 != webpages[k].inLinks.end()) 			//pages pointing to K
                    {
                        webpages[k].newPR += d * webpages[(*curr2)].pr / double(webpages[(*curr2)].outLinks);
                        ++curr2;
                    }
                //newPR = webpages[k].pr; // finally set the PR
            }
        
		//LOOP3
		for (int m=0; m < vertexCount; m++)
			webpages[m].pr = webpages[m].newPR;
	}//end for
	//min.destroy();
    cout << "Finished calculating PRS" << endl << endl;
}

void webGraph::displayPageRanks(int number) 
//Function that displays LIMIT number of webpages in decreasing order
//based on their pr;
//Postcondition: LIMIT number of webpages are displayed to screen	
//Precondition: findPageRanks() must have previously been executed
{
    for (int idx = 0; idx < vertexCount; idx++) 
        rankedPages.insert(webpages[idx].pr, idx);
    
    rankedPages.print();
}

void webGraph::print() const
//Function used for mere testing purposes
{
    /*
      cout << "LINKS:\n";
      linkedListIterator<short> start;
      
      for (int i = 0; i < vertexCount; i++) {
      cout << i << "| ";
      
      start = (webpages[i].inLinks.begin());
      while (start != webpages[i].inLinks.end())
      {
      cout << " <- " << *start;
      ++start;
      }
      cout << endl;
      }	
      
      cout << "SINK NODES: "; 
      
      start = sinkSet.begin();
      while (start != sinkSet.end()) {
		cout << *start << " | ";
		++start;
        }
        
        cout << endl << endl;
    */	
}
