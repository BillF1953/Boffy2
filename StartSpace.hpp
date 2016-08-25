/*********************************************************************
** Program Filename : Start Space Header
** Author : Tyler Forrester
** Date : 7/ 31 / 2016
* * Description: Fighting Space for Adventure game
** Input : Boffy
** Output : Gameplay
** Citations :
********************************************************************/



#ifndef STARTSPACE_HPP
#define STARTSPACE_HPP
#include "Space.hpp"
#include "Boffy.hpp"
#include "InputValid.hpp"
#include "ItemSpace.hpp"
#include "FightSpace.hpp"
#include "DreamWalker.hpp"

class StartSpace : public Space {
private:


public:
	StartSpace(Boffy * x);
	int special();
	void text();
	void menu(); 
	



};

#endif  //!1