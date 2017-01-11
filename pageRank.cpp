// CS 302
// Final Project, Google Page Rank Algorithm

// Note, must use C++11 compiler option
//	g++ -Wall -Wpedantic -g -std=c++11

#include <iostream>
#include <string>
#include <cstdlib>

#include "webGraph.h"

using namespace std;

// *****************************************************************

int main(int argc, char *argv[])
{

// ------------------------------------------------------------------
//  Headers.

	string	stars, bars, dashes;
	string	fName;
	stars.append(65, '*');
	bars.append(65, '=');
	dashes.append(65,'-');
	const char* bold   = "\033[1m";
	const char* unbold   = "\033[0m";

	cout << stars << endl << bold << "CS 302 - Assignment #11" << endl;
	cout << "Google Page Rank Program" << unbold << endl;
	cout << endl;

// ------------------------------------------------------------------
//  Check argument
//	requires formatted graph file.

	if (argc == 1) {
		cout << "usage: <graphFileName>" << endl;
		return 0;
	}

	if (argc != 2) {
		cout << "main: Error, invalid command line argument." << endl;
		return 0;
	}

// ------------------------------------------------------------------
//  Read graph and perform page rank operations.

	string		graphFile;
	webGraph	myGraph;

	graphFile = string(argv[1]);

	if (myGraph.readGraph(graphFile)) {
        myGraph.showGraphStats();
        cout << "ABout to find page ranks" << endl;
		myGraph.findPageRanks();
        cout << "FOund page ranks" << endl;
		myGraph.displayPageRanks(10);
        
	} else {
		cout << "main: Error reading " << graphFile << "." << endl;
	}


// ------------------------------------------------------------------
//  All done.

	cout << stars << endl;
	cout << "Game over, thanks for playing." << endl;

	return 0;
}

