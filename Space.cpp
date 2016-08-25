#include "Boffy.hpp"
#include "Space.hpp"

/*********************************************************************
** Function:  Constructor
** Description: Pointer to Boffy and Sets name of Game
** Parameters:
** Pre-Conditions:  game play
** Post-Conditions: more game play
** Citation:
*********************************************************************/

Space::Space(Boffy * x, string n)
{
	setBoffy(x);
	setName(n);
}

/*********************************************************************
** Function: setName
** Description: Gives Space a name
** Parameters: string n 
** Pre-Conditions: space initialization
** Post-Conditions: Any level movement
** Citation:
*********************************************************************/


void Space::setName(std::string n)
{
	name = n; 
}

/*********************************************************************
** Function: getName
** Description: Returns Spaces a name
** Parameters: string n
** Pre-Conditions:  Returns on menu when moving spaces
** Post-Conditions: Returns on menu when moving spaces
** Citation:
*********************************************************************/

std::string Space::getName()
{
	return name;
}
/*********************************************************************
** Function: getNext
** Description: returns Pointer to new space
** Parameters: 
** Pre-Conditions:  Space construction
** Post-Conditions: Space Pointer
** Citation:
*********************************************************************/


Space * Space::getNext()
{
	return next;
}
/*********************************************************************
** Function: setNext
** Description: sets Pointer to new space
** Parameters:
** Pre-Conditions:  Space construction
** Post-Conditions: Space Pointer
** Citation:
*********************************************************************/

void Space::setNext(Space * o)
{
	next = o; 
}
/*********************************************************************
** Function: getTwo
** Description: returns Pointer to new space
** Parameters:
** Pre-Conditions:  Space construction
** Post-Conditions: Space Pointer
** Citation:
*********************************************************************/
Space * Space::getTwo()
{
	return two;
}
/*********************************************************************
** Function: setTwo
** Description: sets Pointer to new space
** Parameters:
** Pre-Conditions:  Space construction
** Post-Conditions: Space Pointer
** Citation:
*********************************************************************/

void Space::setTwo(Space * t)
{
	two = t; 
}
/*********************************************************************
** Function: getThree
** Description: returns Pointer to new space
** Parameters:
** Pre-Conditions:  Space construction
** Post-Conditions: Space Pointer
** Citation:
*********************************************************************/

Space * Space::getThree()
{
	return three;
}
/*********************************************************************
** Function: setThree
** Description: sets Pointer to new space
** Parameters:
** Pre-Conditions:  Space construction
** Post-Conditions: Space Pointer
** Citation:
*********************************************************************/
void Space::setThree(Space * th)
{
	three = th; 
}
/*********************************************************************
** Function: getFour
** Description: returns Pointer to new space
** Parameters:
** Pre-Conditions:  Space construction
** Post-Conditions: Space Pointer
** Citation:
*********************************************************************/
Space * Space::getFour()
{
	return four;
}

/*********************************************************************
** Function: setFour
** Description: sets Pointer to new space
** Parameters:
** Pre-Conditions:  Space construction
** Post-Conditions: Space Pointer
** Citation:
*********************************************************************/
void Space::setFour(Space * f)
{
	four = f;

}

/*********************************************************************
** Function: setBoffy
** Description: sets boffy pointer for space object
** Parameters: Boffy * boff
** Pre-Conditions:  Space construction
** Post-Conditions:  Game play
** Citation:
*********************************************************************/

void Space::setBoffy(Boffy * boff)
{
	boffy = boff; 
	
}

/*********************************************************************
** Function: getBoffy
** Description: returns boffy pointer from space object
** Parameters: Boffy * boff
** Pre-Conditions:  Space construction
** Post-Conditions: Special() functions all movement all actions
** Citation:
*********************************************************************/

Boffy * Space::getBoffy()
{
	return boffy;
}



/*********************************************************************
** Function:  getChoice
** Description: returns Integer for menu seleciton
** Parameters: 
** Pre-Conditions:  game play
** Post-Conditions: more game play
** Citation:
*********************************************************************/


int Space::getChoice() {
	 
	

		int choice;
		choice = valid.validateInt();
		while (choice < 1 || choice > 5) {

			cout << "The only valid choices are 1 - 5. Please re-enter.\n";
			choice = valid.validateInt();

		}
	

		return choice;



	


}


/*********************************************************************
** Function:  continueOn
** Description: Pauses program after tasks
** Parameters: InputValid
** Pre-Conditions:  game play
** Post-Conditions: more game play
** Citation:
*********************************************************************/

void Space::continueOn() {
	char entry = '0';
	do {


		cout << "Please enter 'c' to continue.\n";
		entry = valid.validateChar();



	} while (entry != 'c');

}