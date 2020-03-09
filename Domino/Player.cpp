/* Assignment: 2
Campus: Beer-Sheva
Author1: tomer marzok, ID: 203396809
Date: 14/4/2015 */

#include "Player.h"

Player::Player(string name) :playerpile()
{						//constractor
	this->name = name;
}
Player::Player(Player & p)
{						//copy constractor
	this->name = p.name;
	playerpile = Pile(p.GetPile());
}
void Player::AddStone(Stone toadd)
{					//add stone in the end to the table or if you take from the kupa
	playerpile.AddStoneInEnd(toadd);
}

void Player::DropPlayerStone(Stone todrop)
{			// drop stone of the player
	playerpile.DropStone(todrop);
}

void Player::OpenPlayerStonePrint()
{		//print the player stone -> opeen
	playerpile.PrintOpenPile();
}
void Player::ClosePlayerStonePrint()
{			//print computer pile close
	playerpile.PrintClosePile();
}
void Player::CloseKupaPrint()
{		//print kupa close
	playerpile.PrintClosePile();
}

bool Player::WinCheck()
{						//check win if you dont have stones
	if (playerpile.GetCurr() == ZERO) return true;
	return false;
}
int Player::ReturnSum()
{					//return the sum of the dots stone for win check
	int sum = ZERO;
	for (int i = ZERO; i < GetCurr(); i++)
	{
		sum += playerpile.GetStoneFromIndex(i).Getx() + playerpile.GetStoneFromIndex(i).Gety();
	}
	return sum;
}



Player::~Player()
{
}
