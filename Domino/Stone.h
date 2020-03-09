/* Assignment: 2
Campus: Beer-Sheva
Author1: tomer marzok, ID: 203396809
Date: 14/4/2015 */
#ifndef STONE_H
#define STONE_H

#include <iostream>
#define SIX 6
using namespace std;


class Stone
{
private:
	int x, y;
public:

	Stone(int x, int y) :x(x), y(y){}
	Stone(Stone& other) : x(other.x), y(other.y){ }
	void ReversStone();	//change the side of the number
	bool Comparison(Stone st_other);	//check if on side at least same
	bool WhichSide(Stone &st_other);	//check which side we need
	bool Same(Stone other){ if ((other.x == this->x) && (other.y = this->y)) return true; return false; }	//check if the both side is match
	void PrintOpenStone() { cout << " [" << x << "][" << y << "]  "; }	//print oper stone
	void PrintCloseStone(){ cout << " [ ][ ]  "; }						//print close stone
	bool CheckDouble(){ if ((this->x == SIX) && (this->y == SIX)){ return true; } return false; }	//check who start ->who have [6][6]
	bool Stone::BothSidesCheck(Stone st_other);		//check if  the stone match to the two sides 
	void SetStone(Stone other){ x = other.x; y = other.y; }	//set new stone
	void SetX(int x){ this->x = x; }
	void SetY(int Y){ this->y = y; }
	int Getx(){ return x; }
	int Gety(){ return y; }
	
};

#endif // !STONE_H