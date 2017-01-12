#=======================================================
#
#  Simple makefile
#
#  Note: The reason the dependencies are so long
#        is because most header files are template
#        classes, thus they need to be included as
#        dependencies for each file that includes them.
#
#========================================================

OBJS	= pageRank.o webGraph.o avlWeb.o
CC		= g++
CFLAGS	= -Wall -g -pedantic -c -std=c++11
LFLAGS	= -Wall -g

out: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o out

pageRank.o: pageRank.cpp
	$(CC) $(CFLAGS) pageRank.cpp

webGraph.o: webGraph.h webGraph.cpp unorderedLinkedList.h unorderedLinkedList.cpp linkedListIterator.h linkedListIterator.cpp
	$(CC) $(CFLAGS) webGraph.cpp 


avlWeb.o: avlWeb.cpp avlWeb.h avlTree.h avlTree.cpp tree.h tree.cpp
	$(CC) $(CFLAGS) avlWeb.cpp


#------------------------
# Clean Utility

clean:
	rm $(OBJS) out
