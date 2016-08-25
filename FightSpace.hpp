/*********************************************************************
** Program Filename : FightSpace Header
** Author : Tyler Forrester
** Date : 7/ 31 / 2016
* * Description: Fighting Space for Adventure game
** Input : Boffy
** Output : Fight
** Citations :
********************************************************************/



#ifndef FIGHTSPACE_HPP
#define FIGHTSPACE_HPP
#include "Space.hpp"
#include "Boffy.hpp"
#include "InputValid.hpp"
#include "DreamWalker.hpp"


class FightSpace: public Space {
private: 
	bool practice; 

public:
	FightSpace(Boffy * boffy, string x, bool practice);
	bool battle(Boffy * boffy, InputValid valid);
	int special();
	void text();
	void menu();



};

#endif  //!1

