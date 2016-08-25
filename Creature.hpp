/*********************************************************************
** Program Filename : Creature Header
** Author : Tyler Forrester
** Date : 7 / 18 / 2016
** Description : Abstract Class for Fantasy Game
** Input : Attacks
** Output : Losses
** Citations : 
********************************************************************/



#ifndef CREATURE_HPP
#define CREATURE_HPP
#include "Dice.hpp"
#include <string>
#include "Queue.hpp"
class Space;
using std::string;

class Creature: private Dice{

private:
	Space * isHere;
	Queue pack;
	node * head;
	node * back;
	string allItems[3];
	int count;
	bool dead;
	int armor;
	int strength; 
	bool won; 
public:
	Creature(int, int); 
	virtual int attack() = 0; 
	virtual void defense(int) = 0; 
	int play(int, int);
	void setStrength(int);
	int getStrength(void);
	int getArmor(void);
	void setArmor(int x);
	int damage(int def, int attack);
	Space * getSpace();
	void setSpace(Space *);
	bool checkItems(string);
	void addItem();
	void timer();
	bool getDead();
	void setDead(bool);
	void setWon(bool);
	bool getWon();
	void clearItems(); 
};

#endif  //!1

