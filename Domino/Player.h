/* Assignment: 2
Campus: Beer-Sheva
Author1: tomer marzok, ID: 203396809
Date: 14/4/2015 */
#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <cstring>
#include "Pile.h"
#include "Stone.h"
#define ZERO 0
using namespace std;
class Player
{
private:
	string name;
	Pile playerpile;	//number of stone in the begin
public:
	Player(string name);	//name of the playrt
	Player(Player & p);		//player pile
	string GetName(){ return name; }	
	void AddStone(Stone toadd);			//add stone in the end to the table or if you take from the kupa
	void DropPlayerStone(Stone todrop);		// drop stone of the player
	void OpenPlayerStonePrint();	//print the player pile-open
	void ClosePlayerStonePrint();	//print computer pile close
	void CloseKupaPrint();			//print kupa-close
	Pile & GetPile() { return playerpile; }
	int GetCurr(){ return playerpile.GetCurr(); }	//get the curr number
	int ReturnSum();			//return the sum of the stones dots
	bool WinCheck();			//check if there is no stone in the player pile
	~Player();
};

#endif // !Player