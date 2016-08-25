/*********************************************************************
** Program Filename : FightSpace CPP
** Author : Tyler Forrester
** Date : 7/ 31 / 2016
* * Description: Fighting Space for Adventure game
** Input : Boffy
** Output : Fight
** Citations :
********************************************************************/


#include "FightSpace.hpp"
/*********************************************************************
** Function: constructor()
** Description: Sets practice mode along with boffy and name of level
** Parameters: boffy, name, practice
** Pre-Conditions: Practicing or ItemSpace()
** Post-Conditions: Battle (Game End) or Flee
** Citation:
*********************************************************************/
FightSpace::FightSpace(Boffy* boffy, string x, bool pract): Space(boffy, x)
{
	practice = pract;
	

}
/*********************************************************************
** Function: battle()
** Description: Has Boffy and Eyghor face off. Boffy can only win if she uses the orb of light. 
** Parameters: boffy, valid
** Pre-Conditions: fightspace special()
** Post-Conditions: game End
** Citation:
*********************************************************************/


bool FightSpace::battle(Boffy * boffy, InputValid valid)
{
	Creature * dummyB = boffy; 
	Creature * fighter2 = new DreamWalker();
	cout << "Before the round Boffy's strength is " << dummyB->getStrength() << ". Eyghor's strength is " << fighter2->getStrength() << ".\n\n"; //Dialog

	cout << "Boffy ATTACKS!!" << std::endl; // whose attack
	fighter2->defense(dummyB->attack());
	valid.continueOn();

	if (fighter2->getStrength() > 0) { // only executes if player 2 is not dead
		cout << "Player 2's ATTACK!!" << std::endl; // whose attack
		dummyB->defense(fighter2->attack()); // Player 2 attacks Player 1
		valid.continueOn();
	}
	else { // if player 2 dead then player 1 won. 

		cout << "BOFFY HAS WON!!" << std::endl;

	//	delete dummyB;
		delete fighter2;
		getBoffy()->setDead(true);
		getBoffy()->setWon(true);
		return false;


	}
	if (dummyB->getStrength() < 1) { // if player 1 dead than player 2 win 

		cout << "BOFFY HAS DIED!!!" << std::endl;
		//delete dummyB;
		delete fighter2;
		getBoffy()->setDead(true);

		return false;


	}
	cout << "After the round Boffy's strength is " << dummyB->getStrength() << ". Eyghor strength is " << fighter2->getStrength() << ".\n"; // Score Keeping
	return true;

}
/*********************************************************************
** Function: Special()
** Description: Plays level. Let's Hero fight monster or flee
** Parameters: none
** Pre-Conditions: startSpace() itemSpace() f
** Post-Conditions: whole game
** Citation:
*********************************************************************/


int FightSpace::special()
{
	text();
	do {
		getBoffy()->timer(); 
		int choice;
	
		menu();
		choice = getChoice();
		
		if (practice) {
			cout << "This is practice. Setting your selection a one.\n";
			choice = 1;  // if practice forces person into battle

		}

		switch (choice)
		{
		case 1: {

			InputValid valid = InputValid();
			while (battle(getBoffy(), valid)) { // fights battle between Boffy and Eyghor
				continueOn();
			}
			cout << "The battle has ended\n";

			break;

		}	

		case 2: {
			getBoffy()->setSpace(getBoffy()->getSpace()->getTwo());
			cout << "You have moved back to the " << getBoffy()->getSpace()->getName() << endl;
			getBoffy()->getSpace()->special();
			break;

		}
		case 3: {
			getBoffy()->setSpace(getBoffy()->getSpace()->getThree());
			cout << "You have moved back to the " << getBoffy()->getSpace()->getName() << endl;
			getBoffy()->getSpace()->special();
			break;
		}
		case 4: {
			getBoffy()->setSpace(getBoffy()->getSpace()->getFour());
			cout << "You have moved back to the " << getBoffy()->getSpace()->getName() << endl;
			getBoffy()->getSpace()->special();
			break;
		}
		case 5: {
			cout << "You dash past Eyghor!\n";  // mix up event. 
			cout << "Eyghor hurdles his axe!\n";
			continueOn();   
			cout << "It hits you in the chest. You fall to the ground.\n";
			getBoffy()->setDead(true);
			continueOn(); 
			/*	getBoffy()->setSpace(getBoffy()->getSpace()->getNext());
			std::cout << "You have discoved a secret passsageway to home square." << endl;
			getBoffy()->getSpace()->special(); */
			break;
		}

		}
	} while (getBoffy()->getDead() == false);

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

void  FightSpace::text()
{
	std::cout << "***************************************************************************\n";
	std::cout << "You strut boldly into the room. You discover an angry " << "EYGHOR THE DREAMWALKER" << ".\n";
	std::cout << "Your knees go weak. You clench the golden amulet and your pupils widen in fear.\n" << endl; 
	continueOn();
	
}
/*********************************************************************
** Function: menu()
** Description: Some menu selections for actions. Has practice mode
** Parameters: none
** Pre-Conditions: main() special()
** Post-Conditions: whole game
** Citation:
********************************************************************/



void FightSpace::menu() {



	std::cout << "Welcome to the " << getName() << std::endl;
	std::cout << "1.Fight Like a Scalded WereWolf\n";

	if(practice == false){
		
		
		std::cout << "2.Run to backwards!!\n";
		std::cout << "3.Dive through the Door on the Right!!\n";
		std::cout << "4.Crawl to the Portal on the right. !!\n";
		std::cout << "5.Dash by Eyghor to the door on the other side of the room!!\n";
	}


}