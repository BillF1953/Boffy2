/*********************************************************************
** Program Filename : Queue Header
** Author : Tyler Forrester
** Date : 7 / 24 / 2016
* * Description : A file that creates a linked structure then removes elements in a first in first out manner
** Input : stringegers
** Output : prstringout of stringeger list
** Citations :
********************************************************************/



#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Node.hpp"
#include <iostream>
class Queue {
private:
	void insertAsFirstElement(node *& head, node *& back, string item);
	int count; 

public:
	bool isEmpty(node *head);
	void addBack(node *& head, node *& back, string item);
	void removeFront(node *&head, node *&last);
	string getFront(node *& head);
	bool checkQueue(node *head, string item);
  //  void viewQueue(node * head);


};

#endif  //!1

