/*********************************************************************
** Program Filename : ItemSpace CPP
** Author : Tyler Forrester
** Date : 7/ 31 / 2016
* * Description: Spaces for Collecting items in game
** Input : Boffy and Name
** Output : Items and Movement
** Citations :
********************************************************************/


#include "ItemSpace.hpp"

/*********************************************************************
** Function: Items Space Constructor()
** Description: Initializes Space relationships and types.
** Parameters: Boffy pointer and name
** Pre-Conditions: startSpace() itemSpace() fightSpace()
** Post-Conditions: itemSpacE() fightSpace()
** Citation:
*********************************************************************/


ItemSpace::ItemSpace(Boffy * n, string x): Space(n , x)
{ 
	// give the space a name assign point to Boffy
}


/*********************************************************************
** Function: Special()
** Description: Plays level Lets Hero collect items for battle or move rooms
** Parameters: none
** Pre-Conditions: startSpace() itemSpace() fightSpace()
** Post-Conditions: whole game
** Citation:
*********************************************************************/


int ItemSpace::special()
{
	   text(); // story line 
	do {
		getBoffy()->timer();  // timer again
		Dice die = Dice(2); // allow for some random outcomes
		int choice;  //use choice for menu based game
		
		menu(); // player interactions
		choice = getChoice(); // get choices 1 - 5


		switch (choice)
		{
		case 1: {

			if (die.roll() == 1) {

				getBoffy()->addItem(); // add item 1/2 the time 
				continueOn(); 
			}
			else {
				cout << "It appears something was once here.\n"; // Other half nothing 
				continueOn(); 

			}

			break;
		}
		case 2: {

			if (die.roll() == 1) {

				getBoffy()->addItem();
				continueOn(); 
			// add item 1/2 the time 
				
			}
			else {
				cout << "You found a chipmunk's tooth.\n"; // other half nothing
				cout << "Nothing was added to your pack.\n";
				continueOn(); 
			}
			break;

		}
		case 3: {
			getBoffy()->setSpace(getBoffy()->getSpace()->getTwo());  //Move Buffy's spaces forward
			cout << "You creap silently forward into the c" << getBoffy()->getSpace()->getName() << endl;
			continueOn();
			getBoffy()->getSpace()->special();
			break;

		}
		case 4: {
			getBoffy()->setSpace(getBoffy()->getSpace()->getThree());
			cout << "You leap forward into the " << getBoffy()->getSpace()->getName() << endl;
			continueOn();
			getBoffy()->getSpace()->special();
			break;
		}
		case 5: {
			getBoffy()->setSpace(getBoffy()->getSpace()->getFour());
			cout << "Your nostrils tingle at the stench of iron. " << endl;  // head to battle
			continueOn(); 
			getBoffy()->getSpace()->special();
			break;
		}
		}
	} while (!(getBoffy()->getDead()));

	return 0;
	
}



/*********************************************************************
** Function: text()
** Description: Gives some context to the situation
** Parameters: none
** Pre-Conditions: main() special()
** Post-Conditions: whole game
** Citation:
*********************************************************************/



void  ItemSpace::text()
{
	std::cout << "***************************************************************************\n";
	std::cout << "You strut boldly into the room. You discover the " << getName() << ".\n\n";
	std::cout << "You breathe a sigh of relief and scan the room for interesting things.\n" << endl;
	continueOn();

}

/*********************************************************************
** Function: menu()
** Description: Some menu selections for actions
** Parameters: none
** Pre-Conditions: main() special()
** Post-Conditions: whole game
** Citation:
*********************************************************************/


void ItemSpace::menu() {



	std::cout << "Welcome to the " << getName() << std::endl;
	std::cout << "1. Open the Chest in the Corner of the "<< getName() << " .\n";
	std::cout << "2. Search the Ground\n";
	std::cout << "3. Go Right to the "<< getTwo()->getName() << ".\n";
	std::cout << "4. Go Left to the " << getThree()->getName() <<".\n";
	std::cout << "5. Sprint through the chamber to "<< getFour()->getName() << ".\n" << endl;




}
