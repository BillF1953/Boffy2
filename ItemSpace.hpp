/*********************************************************************
** Program Filename : ItemSpace Header
** Author : Tyler Forrester
** Date : 7/ 31 / 2016
* * Description: Spaces for Collecting items in game
** Input : Boffy and Name
** Output : Items and Movement
** Citations :
********************************************************************/



#ifndef ITEMSPACE_HPP
#define ITEMSPACE_HPP
#include "Space.hpp"
#include "Boffy.hpp"
#include "InputValid.hpp"


class ItemSpace : public Space {
private:


public:
	void text(); 
	void menu(); 
	ItemSpace(Boffy * n, string x);
	int special();

		

};

#endif  //!1

