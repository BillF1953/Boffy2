/*********************************************************************
** Program Filename : DreamWalker CPP 
** Author : Tyler Forrester
** Date : 7 / 18 / 2016
** Description : DreamWalker Class for Fantasy Game
** Input : Attacks
** Output : Losses
** Citations :
********************************************************************/

#include "DreamWalker.hpp"

/*********************************************************************
** Function: DreamWalker Constructor
** Description: Intializes DreamWalker Strength and Armor in Creature Class
** Parameters: void and Creature(Armor, Strength)
** Pre-Conditions: pick()
** Post-Conditions: battle()
** Citation:
*********************************************************************/


DreamWalker::DreamWalker(): Creature(1200, 2000) // passes armor and strength to creature class constructor
{

	 
}

/*********************************************************************
** Function: DreamWalker attack()
** Description: Calls Play in Creature Class to get Attack
** Parameters: void
** Pre-Conditions: battle()
** Post-Conditions: def()
** Citation:
*********************************************************************/


int DreamWalker::attack()
{
	int at = play(2, 6); // use play function to roll die and return number
	std::cout << "DreamWalker has a rolled a " << at << " in Attack.\n";  // user output so game is fun. Also good testing
	std::cout << "Vapors fill the room. Boffy can't breath! Eyghor total attack is 20,000!\n"; // auto kill. 
	at = 20000;  
	
	return (at); 
}

/*********************************************************************
** Function: DreamWalker defense()
** Description: takes attack and returns DreamWalker health
** Parameters: int attack
** Pre-Conditions: battle() attack()
** Post-Conditions: damage() then battle() or main()
** Citation:
*********************************************************************/

 void DreamWalker::defense(int attack)
{
	//std::cout << "DreamWalker's Strength before Attack is " << getStrength() << ".\n"; // used for testing
	int def = play(1,6); // calls play function to roll dies
	
	std::cout << "DreamWalker has rolled a " << def << " in Defence.\n";
	
	int health = getStrength() - damage(def, attack); // gets health after attack
	
	std::cout << "DreamWalker's total damage is " << damage(def, attack) << ".\n\n"; // output to play along
	
	setStrength(health); // sets creatures strength in creature class

	// std::cout << "DreamWalker's strength is " << getStrength() << ".\n\n"; // output for testing
	
	
}
