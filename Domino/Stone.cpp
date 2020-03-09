/* Assignment: 2
Campus: Beer-Sheva
Author1: tomer marzok, ID: 203396809
Date: 14/4/2015 */
#include "Stone.h"

void Stone::ReversStone()
{			// switch the sides of the stone
	int temp = this->x;
	this->x = this->y;
	this->y = temp;
}
bool Stone::Comparison(Stone st_other)
{					//check if on side at least same
	if ((this->x == st_other.x) || (this->x == st_other.y) || (this->y == st_other.x) || (this->y == st_other.y)){
		return true;
	}
	return false;
}

bool Stone::BothSidesCheck(Stone st_other)
{					//check if  the stone match to the two sides 
	if ((((this->x == st_other.x) && (this->x == st_other.y)) || ((this->y == st_other.x) && (this->y == st_other.y))) || (((this->y == st_other.x) && (this->x == st_other.y)) || ((this->x == st_other.x) && (this->y == st_other.y)))){
		return true;
	}
	return false;
}

bool Stone::WhichSide(Stone &st_other)	//check which side we need
{
	if (this->x == st_other.y)	//drop in the end
		return true;
	if (this->y == st_other.x)	//drop in the start
		return false;
	if (this->x == st_other.x)
	{							//drop in the end after revers
		this->ReversStone();
		return false;
	}
	else if (this->y == st_other.y)
	{								//drop in the start after revers
		this->ReversStone();
		return true;
	}
	return true;
}

