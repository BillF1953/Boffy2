/*********************************************************************
** Program Filename : Final Project
** Author : Tyler Forrester
** Date : 7 / 24 / 2016
** Description : A fantasy game 
** Input : user Input
** Output : Battles between nums
** Citations: 
*********************************************************************/


#include "InputValid.hpp"
#include "DreamWalker.hpp"
#include "Boffy.hpp"
#include "StartSpace.hpp"
#include <string>


using std::cout;
using std::endl;
void menu();
void displayMenu(string);
int getChoice(InputValid);
void continueOn(InputValid);
char playAgain(InputValid valid);

int main() {
	InputValid valid = InputValid();
	char quit;
	int choice; 
	cout << "Welcome to final project." << "\n\n";
	
	do {
		menu();
		choice = getChoice(valid);

		switch (choice) {
		case 1:  cout << "The goal of this game is to obtain and then use an item to kill Eyghor the Dreamwalker.\n";
				valid.continueOn(); 
				break;
		case 2: {
			do {

			
				Boffy * boffy = new Boffy();
				Space * first = new StartSpace(boffy);
				boffy->setSpace(first);
				boffy->getSpace()->special();


				if (boffy->getWon() == false) {

					cout << "Boffy has died a dastardly death. There are no more vampire slayers.\n";
					cout << "Would you like to play again?\n";
					quit = playAgain(valid);

				}

				else {

					cout << "Buffy has vanquished Eyghor, the maze vanishes. You've won and your friends are free!\n";
					cout << "Would you like to play again?\n";
					quit = playAgain(valid);


				}
				boffy->clearItems();
				delete first;
				delete boffy;

			} while (quit == 'y');
			break;
		}

		}
	} while (quit == 'y' || choice != 3);
	return 0;

} 


/*********************************************************************
** Function: displayMenu
** Description: Displays Menu of Options
** Parameters: void
** Pre-Conditions: Start of Program
** Post-Conditions: getChoice()
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
*********************************************************************/


void menu(){

	cout << "Welcome to Main Menu." << "\n";
	cout << "1. Read a Synposis of the Game\n";
	cout << "2. Play the Game.\n";
	cout << "3. Quit the Program.\n\n";

}
/*********************************************************************
** Function:  getChoice
** Description: gets number of Choice
** Parameters:  InputValid
** Pre-Conditions: DisplayMenu()
** Post-Conditions: Switch and Array Entry
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
*********************************************************************/


int getChoice(InputValid valid) {
  
	int choice;
	choice = valid.validateInt();
	while (choice < 1 || choice > 3) {

		cout << "The only valid choices are 1 or 2. Please re-enter.\n";
		choice = valid.validateInt();

	}

	return choice;



}



/*********************************************************************
** Function:  Play Again
** Description: y for yes, all else no
** Parameters: InputValid
** Pre-Conditions: switch case 1, case 2 and case 3
** Post-Conditions: displaymenu()
** Citation:
*********************************************************************/

char playAgain(InputValid valid) {
	char entry = '0';
	


		cout << "Please enter y to continue. All other characters quit.\n";
		entry = valid.validateChar();


	return entry; 
}

