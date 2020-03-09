/* Assignment: 2
Campus: Beer-Sheva
Author1: tomer marzok, ID: 203396809
Date: 14/4/2015 */
#include "Pile.h"

Pile::Pile()
{
	curr = ZERO;
}
void Pile::PrintOpenTable()		//print the stone in the table
{
	for (int i = ZERO; i < curr; i++)
	{							//send the stones in the arr to open print  in stone.cpp
		(*(arr + i))->PrintOpenStone();
	}
	cout<<endl;
}

Pile::Pile( Pile & p)
{						//build dinamic arr by curr and his player
	this->arr = new Stone*[p.curr];
	assert(this->arr);
	int i = ZERO;
	for (i = ZERO; i < curr; i++)
	{
		arr[i] = new Stone(*(arr[i]));
		assert(arr[i]);
	}
}


void Pile::BuildPile()
{								//build pile with 28 stone
	curr = TWENTYEIGHT;
	arr = new Stone*[TWENTYEIGHT];
	assert(arr);
	int counter = ZERO;
	for (int i = ZERO; i <= SIX; i++){		//set the stone numbers
		for (int j = ZERO; j <= i; j++){	//in counter place
			arr[counter] = new Stone(i, j);
			assert(arr[counter]);
			counter++;
		}
	}
}
								
void Pile::PrintOpenPile()
{								//print our pile with numbers of the stone
	for (int i = ZERO; i < curr; i++)
	{							//send the stones in the arr to open print  in stone.cpp
		(*(arr + i))->PrintOpenStone();
	}
	cout << endl;
	for (int i = ZERO; i < curr; i++)
	{									//send the stones in the arr to close print in stone.cpp
		cout << "  [" << i + ONE << "]    ";
	}
	cout << endl;
}

void Pile::PrintClosePile()
{								//print computer pilr
	for (int i = ZERO; i < curr; i++)
	{									//send the stones in the arr to close print in stone.cpp
		(*(arr + i))->PrintCloseStone();
	}
	cout << endl;
	for (int i = ZERO; i <curr; i++)
	{									//send the stones in the arr to close print in stone.cpp
		cout << "   [" << i + ONE << "]   ";
	}
	cout << endl;

}
void Pile::PrintCloseKupa()
{								//print the stone in the kupa
	for (int i = ZERO; i < curr; i++)
	{									//send the stones in the arr to close print in stone.cpp
		(*(arr + i))->PrintCloseStone();
	}
	cout << endl;
}

void Pile::MixStones()
{				//mix ths stone. all the place in new arr=null and then we put there stone until we dont have a null place
	Stone **newpile;
	int num;
	newpile = new Stone*[curr];
	assert(newpile);
	for (int i = ZERO; i < curr; i++)
	{
		newpile[i] = NULL;
	}
	int flag;
	srand((unsigned int)(time(NULL)));
	for (int i = ZERO; i < curr; i++)
	{

		flag = ONE;
		do{		//loop if the arr in place num= number
			num = rand() % curr;
			if (newpile[num] == NULL)
			{
				newpile[num] = arr[i];
				flag = ZERO;
			}
		} while (flag == ONE);

	}
	delete[] arr;
	arr = newpile;		//copy the new arr to the old
}

void Pile::AddStoneInStart(Stone st)
{				//add stone to the table in the start
	curr++;
	Stone **newpile = new Stone*[curr];
	int i = ZERO;
	newpile[i] = new Stone(st);		//copy constractore- put the stone in [0] place
	for (i = ONE; i < curr; i++)
	{
		newpile[i] = arr[i - ONE];
	}
	delete[] arr;
	arr = newpile;
}

void Pile::AddStoneInEnd(Stone st)
{				//add stone in the end of the table stone
	Stone **newpile = new Stone*[curr + ONE];
	for (int i = ZERO; i < curr; i++)
	{
		newpile[i] = arr[i];
	}
	newpile[curr] = new Stone(st);	//copy constractoe-put the stone in the [curr] place
	curr++;
	delete []arr;
	arr = newpile;

}

void Pile::DropStoneByIndex(int index)
{						//drop the players stone by index we choose
		Stone **newpile = new Stone*[curr - ONE];		//creat new arr	whithout the stone we choose
		for (int j = ZERO; j < index; j++)
		{
			newpile[j] = arr[j];
		}

		for (int j = index; j < curr; j++)
		{
			newpile[j] = arr[j + ONE];
		}
		curr--;
		delete arr[index];
		delete[] arr;
		arr = newpile;	
}

void Pile::DropStone(Stone st)
{		//computer drop stone
	int index = -1;		//we dont have -1 index-> its for check
	for (int i = ZERO; i < curr; i++)
	{					//check similar stone
		if (arr[i]->Same(st) == true)
		{
			index = i;
		}
	}
	if (index != -1)
	{
		Stone **newpile = new Stone*[curr - 1];		//creat new arr
		for (int j = ZERO; j < index; j++)
		{
			newpile[j] = arr[j];
		}
		
		for (int j = index; j < curr; j++)
		{
			newpile[j] = arr[j + ONE];
		}
		curr--;
		delete arr[index];
	    delete [] arr;
		arr = newpile;
	}

}



bool Pile::CheckWhoStart()
{					//check who start with [6][6]
	for (int i = ZERO; i < curr; i++)
	{
		if (arr[i]->CheckDouble() == true) return true;
	}
	return false;
}

Stone Pile::DropStoneAndReturn() //drop and return the last element in the pile
{								//to the players
	Stone tosend(*arr[curr - ONE]);
	int j = ZERO;
	curr--;
	Stone **newpile = new Stone*[curr];		//creat new arr

	for (int i = ZERO; i < curr; i++)
	{
		newpile[j] = arr[i];
		j++;

	}
	delete [] arr;
	arr = newpile;

	return tosend;
}

Stone Pile::CreateStartAndEnd()
{		//create "stone" for check. the end and the start of the arr in the table
	if (curr != ZERO)
	{
		Stone toreturn(arr[0]->Getx(), arr[curr - ONE]->Gety());
		return toreturn;

	}
	Stone rturn(ZERO, ZERO);	//if we dont have stone in the table-->the first stone trow
	return rturn;
}

Pile::~Pile()
{
	for (int i = ZERO; i < curr; i++)
	{
		delete arr[i];
	}
	delete [] arr;
	arr = NULL;
	curr = ZERO;
}
