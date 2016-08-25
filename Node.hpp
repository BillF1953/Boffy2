/*********************************************************************
** File: Node Structure Header file
** Description: vessel carrying a char with the ability to link
**Initializes char and * to node to NULL
** Pre-Conditions: Creation of SpaceQueue, main()
** Post-Conditions: rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/


#ifndef NODE_HPP
#define NODE_HPP
#include <string>
#include <stddef.h>
using std::string; 


struct node {

	node() : item("Empty"), next(NULL) {}  // node constructor
	string item;  // item contained
	node *next; // postringer to next node in list

};


#endif  //!1

