/*********************************************************************
** Program Filename : Creature CPP
** Author : Tyler Forrester
** Date : 7 / 18 / 2016
** Description : Abstract Class for Fantasy Game
** Input : Attacks
** Output : Losses
** Citations :
********************************************************************/

#include "Creature.hpp"
/*********************************************************************
** Function: Creature Constructor
** Description: Intializes Creature Strength and Armor seed random num
** generator. 
** Parameters: int Armor, int Strength
** Pre-Conditions: pick()
** Post-Conditions: battle()
** Citation:
*********************************************************************/

Creature::Creature(int arm, int str)
{
	seed(); // seed random number generator
	setArmor(arm); // set armor
	setStrength(str); // set str
	pack = Queue(); 
	head = NULL;
	back = NULL;
	allItems[0] = "Sword of Gabriel";
	allItems[1] = "Light Orb";
	allItems[2] = "Sleeping Powder";
	count = 0;
	dead = false;
	won = false; 
}
/*********************************************************************
** Function: setStrength
** Description:  Sets Strength
** Parameters: int Strength
** Pre-Conditions: defense() and life()
** Post-Conditions: battle() main()
** Citation:
*********************************************************************/

void Creature::setStrength(int str)
{
	strength = str;

}
/*********************************************************************
** Function: getStrength
** Description:  gets Strength
** Parameters:
** Pre-Conditions: defense(), life(), battle()
** Post-Conditions: battle() main()
** Citation:
*********************************************************************/

int Creature::getStrength(void)
{
	return strength;
}
/*********************************************************************
** Function: getArmor
** Description:  gets Armor
** Parameters:
** Pre-Conditions: damage()
** Post-Conditions: damage()
** Citation:
*********************************************************************/
int Creature::getArmor(void)
{
	return armor;
}

/*********************************************************************
** Function: setArmor
** Description:  sets Armor
** Parameters:
** Pre-Conditions: damage()
** Post-Conditions: damage()
** Citation:
*********************************************************************/
void Creature::setArmor(int x)
{
	armor = x; 
}

/*********************************************************************
** Function: Creature damage()
** Description: Returns damage
** Parameters: int attack
** Pre-Conditions: battle() attack() def()
** Post-Conditions: def()
** Citation:
*********************************************************************/


int Creature::damage(int def, int attack)
{
	int tat = attack - def - getArmor(); // figures damage

	if (tat > 0) {

		return tat;  // returns damaged

	}

	else {

		return 0;  // damage negative returns 0 
	}

}

/*********************************************************************
** Function: play
** Description:  rolls x number of dies of x sides return the value
** Parameters: number of dies and number of sides
** Pre-Conditions: attack() and defense()
** Post-Conditions: battle(), defense()
** Citation:
*********************************************************************/


int Creature::play(int dies, int sides)
{
	int at = 0; // initializes variables
	setDivisor(sides); // sets number of sides
	for (int i = 0; i < dies; i++) // this determines number of dice rolls
	{ 
		at += roll(); // this sums those dice rolls
	}

	return at; // this returns dice rolls
}


/*********************************************************************
** Function: getSpace
** Description: Gets Space that creature is currently on
** Parameters: 
** Pre-Conditions: special()
** Post-Conditions: special() 
** Citation:
*********************************************************************/

Space * Creature::getSpace()
{
	return isHere;
}

/*********************************************************************
** Function: setSpace
** Description: Sets Space that creature is on 
** Parameters: Pointer to a Space
** Pre-Conditions: special()
** Post-Conditions: special()
** Citation:
*********************************************************************/

void Creature::setSpace(Space * x)
{
	isHere = x;

}

/*********************************************************************
** Function: checkItems
** Description: searchs linked queue for an items
** Parameters:  the item
** Pre-Conditions: boffy attack() 
** Post-Conditions: boffy and dreamwalker attack() def() addItem()
** Citation:
*********************************************************************/

bool Creature::checkItems(string x)
{

	return  pack.checkQueue(head, x); // looks for item

}


/*********************************************************************
** Function: addItems
** Description: adds Item to a linked queue by randomly selecting the item for an array
** Parameters:  none
** Pre-Conditions: ItemSpace() Searches
** Post-Conditions: FightSpace() and ItemSpacE()
** Citation:
*********************************************************************/

void Creature::addItem()
{
	int roll = play(1, 3) - 1; // random number for item selection

	if (!(checkItems(allItems[roll]))) { 

		pack.addBack(head, back, allItems[roll]); // if item is already in pack adds item

	}

	else {

	std::cout << "You already have " << allItems[roll] << " \n"; // tells the gamer that item is one they possess.
	std::cout << allItems[roll] << " is discarded" << " \n";

	}





}

/*********************************************************************
** Function: timer
** Description: Counts down till end of game. Game Lasts 10 moves
** Parameters:  
** Pre-Conditions: Main any Space()
** Post-Conditions: Main to for game outcome
** Citation:
*********************************************************************/

void Creature::timer()
{
	count++;

	if (count > 6 && count < 10) {

		std::cout << "The game is ending in ^^" << (10 - count) + 1 << "^^ moves.\n"; // gives a countdown till game ends


	}


	if (count == 10) {
		std::cout << "This is the last move in the game.\n";
		setDead(true); // game over after this move. 

	}




}

/*********************************************************************
** Function: getDead
** Description: If true ends game. If false loops game.
** Parameters:
** Pre-Conditions: special() 
** Post-Conditions: special()
** Citation:
*********************************************************************/

bool Creature::getDead()
{
	return dead;
}
/*********************************************************************
** Function: setDead
** Description: If true ends game. If false loops game.
** Parameters: bool now
** Pre-Conditions: timer() and battle() set Dead status
** Post-Conditions: special()
** Citation:
*********************************************************************/
void Creature::setDead(bool now)
{
	dead = now;


}

/*********************************************************************
** Function: setWon
** Description: Set after battle or timer to determine win 
** Parameters: bool yes
** Pre-Conditions: timer() and battle() 
** Post-Conditions: main()
** Citation:
*********************************************************************/



void Creature::setWon(bool yes)
{
	won = yes; 
  
}
/*********************************************************************
** Function: getWon
** Description: Tells main whether game was one or lost
** Parameters: bool yes
** Pre-Conditions: timer() and battle()
** Post-Conditions: main()
** Citation:
*********************************************************************/


bool Creature::getWon()
{
	return won;
}
/*********************************************************************
** Function: clearItems
** Description: Destroys linked list at end of game. 
** Parameters: none
** Pre-Conditions: whole game
** Post-Conditions: main()
** Citation:
*********************************************************************/


void Creature::clearItems()
{
  while (!(pack.isEmpty(head))) {
	  pack.removeFront(head, back);// frees allocated memory of queue (if any left)
	}

}
