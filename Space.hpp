/*********************************************************************
** Program Filename : Space Header
** Author : Tyler Forrester
** Date :7/31/2016
* * Description : Abstract Class for Spaces for the Boffy the Vampire Slayer
** Input : Game
** Output : Game
** Citations : 
********************************************************************/



#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "InputValid.hpp"
#include "Dice.hpp"
class Boffy; 

class Space {
private: 
	Space * next; 
	Space * two; 
	Space * three;
	Space * four; 
	Boffy * boffy; 
	std::string name; 
	InputValid valid;


public:

	Space(Boffy * x, string n);
	void setName(std::string); 
	std::string getName();
	Space * getNext();
	void setNext(Space * o);
	Space * getTwo();
	void setTwo(Space *);
	Space * getThree();
	void setThree(Space *);
	Space * getFour();
	void setFour(Space *);
	void setBoffy(Boffy *);
	Boffy * getBoffy(); 
	virtual int special() = 0;
	int getChoice();
	void continueOn();


};

#endif  //!1
