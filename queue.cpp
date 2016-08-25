/*********************************************************************
** Program Filename : Queue CPP
** Author : Tyler Forrester
** Date : 7 / 24 / 2016
* * Description : A file that creates a linked structure then removes elements in a first in first out manner
** Input : stringegers
** Output : prstringout of stringeger list
** Citations :
********************************************************************/


#include "Queue.hpp"
/*********************************************************************
** Function: isEmpty
** Description: Checks if a Node has been created
** Paramters: node * head
** Pre-Conditions: case 2 and case 3 of switch
** Post-Conditions: Rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

bool Queue::isEmpty(node * head)
{
	if (head == NULL)
		return true;
	else
		return false;

}
/*********************************************************************
** Function: insertAsFirstElement
** Description: creates node, inserts char, postrings all postringer to first node except temp->next which postrings to NULL
** Paramters: node * &head, node *&back, string item
** Pre-Conditions: Insert Node
** Post-Conditions: Rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

void Queue::insertAsFirstElement(node *& head, node *& back, string item)
{

	node *temp = new node;  // create first node for first element
	temp->item = item;  // assign value to temps char
	temp->next = NULL;   // assigns postringer to null
	head = temp;   // head (start) = temp 
	back = temp;  // back (end) = temp
	count = 1; 
}

/*********************************************************************
** Function: addBack
** Description: Adds things to pack if too many items then says pack is full. 
** sets back to new node
** Paramters: node * &head, node *&back, string item
** Pre-Conditions: Insert Node
** Post-Conditions: Rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

void Queue::addBack(node *& head, node *& back, string item)
{    

	std::cout << "YOU HAVE RECEIVED " << item << "!!!\n";
	std::cout << "Adding your item to your pack\n";
	
	if (count < 2) {

		if (isEmpty(head)) {
			insertAsFirstElement(head, back, item); // if empty calls insert As FirstElement //consider doing this in main

		}
		else {
			node *temp = new node;  // creates new node
			temp->item = item;  // assigns pass item
			temp->next = NULL;  // assigns temp->next to null (single linked list)
			back->next = temp;   // moves the last postringer to postring at the new temp
			back = temp;   //moves back forward
			count++;
		}

	}

	else {

		std::cout << "Too Bad, Pack is Full. No more Items allowed.\n";

	}


}

/*********************************************************************
** Function: removeFront
** Description: deletes head after its been displayed
** Paramters: node * &head, node *&back
** Pre-Conditions: getFront()
** Post-Conditions: 
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

void Queue::removeFront(node *& head, node *& last)
{
	if (isEmpty(head)) {
		//cout << "A node never existed" << endl;

	}
	else if (head == last) { // last delete when postringer->next postrings to itself
		delete head; // delete
		head = NULL;  // set head to Null
		last = NULL;  // set last to null

	}

	else
	{

		node *temp = head;  // set node postringer equal to head
		head = head->next;  // set move head to next node
		delete temp;  // delete old head
	

	}


	
}

/*********************************************************************
** Function:  getFront
** Description: If item has been removed, deals with empty SpaceQueue cases otherwise returns item
** Paramters: node * &head
** Pre-Conditions: case 1, case 2
** Post-Conditions: removeFront()
** Citation:
*********************************************************************/

string Queue::getFront(node *&head) { // passes head

	try {
		if(isEmpty(head)) {

		throw -65536;

	}
		return(head->item);  // Presents head as the first member of the SpaceQueue
	}
	catch (string x) {

		std::cout << "Tried to Print Out an Undefined Element\n";

	}
	
	
}

/*********************************************************************
** Function:  checkQueue
** Description: Does a basic linear search for an item
** Paramters: node * &head
** Pre-Conditions: Boffy Attack() ItemSpace Searches() 
** Post-Conditions: ItemSpace() FightSpace()
** Citation:
*********************************************************************/

bool Queue::checkQueue(node * head, string item)
{

	if (!isEmpty(head)) { // checks for queue
		node * current = head; // current = head
		while (current->next != NULL) {  // until current is null

			if (current->item == item) { // item matches return true

				return true;
			}


			current = current->next; // move current to next node

		}
		if (current->item == item) { // if last item matches return true

			return true;
		}
	}
		return false; // else return false
	
	
}
/* Unused Function could be used in a futre project
void Queue::viewQueue(node * head)
{

	if (!isEmpty(head)) {
		int count = 1; 
		node * current = head;
		std::cout << "You have these items: \n";
		std::cout << count << ". " << current->item << std::endl;
		while (current->next != NULL) {
								   
			current = current->next;
			count++; 
			std::cout << count << ". " << current->item << std::endl;
		}
		
	}
	else {
		std::cout << "You have no items." << std::endl;
	}
}
*/


