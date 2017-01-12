-------------------------
Student: Javier Llerenas
Class:   CS 302
Section: 1002
Ast:  	 11-B : Page Rank
--------------------------
# Google's PageRank Algorithm
#### This is the final project submitted for my Data Structures class (CS 302)

## How to use it?
To compile, use the 'make' utility
```
   $ make
```
This should generate the .o files and the out file.

## Usage
To use the program, execute:
```
    $ a.out web1.txt
```
or
```
    $ a.out web2.txt
```

## Data Structures Used
For this project I designed two custom data structure to allow the algorithm to efficiently execute.

### Trees: Custom AVL Tree
The first data structure is a modified version of the regular AVL Tree.

#####Purpose:
To efficiently be able to sort and store the greates LIMIT number of elements, and print their information.

#####Features:
> This version keeps only a LIMIT number of elements in it.
> When an element is to be inserted, if it is greater than the smallest element, then they are replaced
> Insertion executes in  O(log n)


### Graph: Custom Edge List
The second data structure is a modified version of an edge list for a graph.

#####Purpose:
To be able to obtain the number of outLInks of every page, and to efficiently find the pages that point to a given page.

#####Features:
> Utilizes an Unordered Linked List to create a sink list
> Uses the avlTree data structure mentioned previously to sort and print the pages

###Notes:
If you find a flaw, or have any comments, feel free to email me at jv.llerenas@gmail.com