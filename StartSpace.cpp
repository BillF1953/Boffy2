/*********************************************************************
** Program Filename : Start Space CPP
** Author : Tyler Forrester
** Date : 8/ 6 / 2016
** Description: Fighting Space for Adventure game
** Input : Boffy
** Output : Game Play
** Citations :
********************************************************************/

#include "StartSpace.hpp"


/*********************************************************************
** Function: Start Space Constructor()
** Description: Initializes Space relationships and types. 
** Parameters: Boffy pointer
** Pre-Conditions: main()
** Post-Conditions: whole game
** Citation:
*********************************************************************/


StartSpace::StartSpace(Boffy * x):Space(x ,"Home")
{
	
	string second1 = "**Pit**";
	string third1 = "**Graveyard**";
	string fourth1 = "**Dismal Crypt**";
	string fifth1 = "**The Dreamwalker Throne Room**";

	Space * second = new ItemSpace(x, second1); //CHANGE TO VILLAIN TYPE
	Space * third = new ItemSpace(x, third1);
	Space * fourth = new ItemSpace(x, fourth1);
	Space * fifth = new FightSpace(x, fifth1, false);
	
	setNext(second);
	setTwo(third);
	setThree(fourth);
	setFour(fifth);

	second->setNext(this);
	second->setTwo(third);
	second->setThree(fourth);
	second->setFour(fifth);
		
	third->setNext(this);
	third->setTwo(second);
	third->setThree(fourth);
	third->setFour(fifth);

	fourth->setNext(this);
	fourth->setTwo(second);
	fourth->setThree(third);
	fourth->setFour(fifth);

	fifth->setNext(this);
	fifth->setTwo(second);
	fifth->setThree(third);
	fifth->setFour(fourth);

}

/*********************************************************************
** Function: Special()
** Description: Plays level; includes a practice fight along with ways to move other spaces
** Parameters: none
** Pre-Conditions: main()
** Post-Conditions: whole game
** Citation:
*********************************************************************/


int StartSpace::special()
{
	text();
	do {
		getBoffy()->timer(); // increment death counter
		int choice; // initialize choice
	 
		menu(); // show menue
		choice = getChoice(); // get choice
	

		switch (choice) // use switch statement to play game 
		{
		case 1: {

			string fightS = "Fight Space"; // name for new space
			Boffy * practiceBoffy = new Boffy(); // practice character
			bool practice = true;  // tell space that is a practice mode
			Space * QuestionSpace = new FightSpace(practiceBoffy, fightS, practice); // create new space in game as a practice
			QuestionSpace->setNext(NULL); // use null since practice
			QuestionSpace->setTwo(NULL); // use null since practice
			QuestionSpace->setThree(NULL); // use null since practice
			QuestionSpace->setFour(NULL); // use null since practice
			
			cout << "Welcome to practice\n"; // Let's people know its practice
			continueOn(); 
			practiceBoffy->setSpace(QuestionSpace); // stets fake boffy ishere to question space
			practiceBoffy->getSpace()->special(); // starts playing 
			
			cout << "Practice is over returning to home menu\n"; // let's player no that they are exiting practice
			continueOn();
			delete QuestionSpace;
			delete practiceBoffy;
			break;

		}
		case 2: {
			getBoffy()->setSpace(getBoffy()->getSpace()->getTwo()); //Move Buffy's spaces forward
			cout << "You creap silently forward into the " << getBoffy()->getSpace()->getName() << endl; //Let player know where they are ging
			getBoffy()->getSpace()->special(); // start game play on new space
			break;
		}
		case 3: {
			getBoffy()->setSpace(getBoffy()->getSpace()->getThree()); 
			cout << "You leap forward into " << getBoffy()->getSpace()->getName() << endl;
			getBoffy()->getSpace()->special();
			break;

		}
		case 4: {
			getBoffy()->setSpace(getBoffy()->getSpace()->getNext());
			cout << "Your nostrils tingle at the stench of iron " << getBoffy()->getSpace()->getName() << endl; // fake out for battle space
			getBoffy()->getSpace()->special();
			break;
		}
		case 5: {
			getBoffy()->setSpace(getBoffy()->getSpace()->getFour()); // this one is always a battle space. Easter Egg for testing. 
			cout << "Your nostrils tingle at the stench of iron " << getBoffy()->getSpace()->getName() << endl;
			getBoffy()->getSpace()->special();
			break;

		}
		}
	} while (!(getBoffy()->getDead()));
	
	delete getNext(); // deallocate spaces once game ends
	delete getTwo(); // deallocate spaes
	delete getFour();
	delete getThree();

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

void StartSpace::text()
{
	std::cout << "***************************************************************************\n\n\n";
	std::cout << "Your friends have been taken by a mysterious monster.\n Scared, tired, and hungry, you are searching.\n";
	std::cout << "Your search led you to this vacant graveyard in Transyl Falls.\n";
	std::cout << "You tread lightly. The power amulet feels greasy that started this quest beating against your chest.\n";
	std::cout << "A puff of smoke rises from the Gravestone.\n";
	std::cout << "You jump back and hit your head.\n\n\n" << std::endl; 
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

void StartSpace::menu() {



	std::cout << "Welcome to the " << getName() << std::endl;
	std::cout << "This is the start of the adventure\n";
	std::cout << "1.Practice Fighting\n";
	std::cout << "2.Move to new Area on Left\n";
	std::cout << "3.Move to new Area on Right.\n";
	std::cout << "4.Go into the tunnel behind you.\n";
	
	


}
