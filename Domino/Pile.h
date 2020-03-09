/* Assignment: 2
Campus: Beer-Sheva
Author1: tomer marzok, ID: 203396809
Date: 14/4/2015 */
#ifndef PILE_H
#define PILE_H

#include "Stone.h"
#include<string.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#define ZERO 0
#define ONE 1
#define SIX 6
#define TWENTYEIGHT 28
using namespace std;

class Pile
{
private:
	Stone **arr;
	int curr;
public:
	Pile();
	Pile( Pile & p);
	void BuildPile();	//built pile of 28 stone
	void PrintOpenPile();	//print player pile
	void PrintOpenTable();	//print stones in the table
	void PrintClosePile();	//print computer pile
	void PrintCloseKupa();	//print the kupa
	void MixStones();		//mix the first pile of stone
	void AddStoneInStart(Stone st);	//add stone in the start of the table pile
	void AddStoneInEnd(Stone st);	//add stone in the end of the table pile
	void DropStone(Stone st);			//computer drop stone
	Stone DropStoneAndReturn();			//kupa drp stone to the player
	void DropStoneByIndex(int index);		//drop stone from our pile by index 
	bool CheckWhoStart();					//look for [6][6] stone all over the pile
	Stone GetStoneFromIndex(int index){ return *(arr[index]); }	//get the x,y from the stone to the sum
	Stone GetStone(){ return **arr; }
	int GetCurr(){ return curr; }
	Stone CreateStartAndEnd();	//built "Stone" from the start of the pile of table->x  and the end ->y
	~Pile();
};

#endif // !PILE_H