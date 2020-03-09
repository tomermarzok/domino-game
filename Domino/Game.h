/* Assignment: 2
Campus: Beer-Sheva
Author1: tomer marzok, ID: 203396809
Date: 14/4/2015 */
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include <string>
#include "Pile.h"
#include "Stone.h"
#define ZERO 0
#define ONE 1
#define SEVEN 7
using namespace std;

class Game
{
private:
	Player ply1;
	Player Computer;
	Pile Kupa;
	Pile Stoneontable;
	int x;		//the first number in the stone
	int y;	//the last number of the last stone
	void TurnPlayer();	//player turn
	void ComputerTurn();	//computer turn
	bool NothingToPut(int cORp);	//check stone to put-computer or player
	bool CheckWin();	//win check
	void PrintGame();	//print screen
	void ComputerDrop();	//computer drop
public:
	Game(string name);
	void run();
	enum {COMP= ZERO, PLY=ONE };	//computer -zero,player one
	~Game();
};


#endif // !GAME_H
