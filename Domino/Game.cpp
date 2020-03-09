/* Assignment: 2
Campus: Beer-Sheva
Author1: tomer marzok, ID: 203396809
Date: 14/4/2015 */
#include "Game.h"

Game::Game(string name) : ply1(name), Computer("computer"), Kupa(), Stoneontable()
{						//build the game with 2 player , kupa and stone in table
	Kupa.BuildPile();	//build pile with 28 stones
	Kupa.MixStones();	//mix the pile
}
void Game::run()
{
	bool win = false;
	Kupa.MixStones();
	for (int i = ZERO ; i < SEVEN; i++)
	{			//give stones to the players
		ply1.AddStone(Kupa.DropStoneAndReturn());	//player take seven stones from the kupa 
		Computer.AddStone(Kupa.DropStoneAndReturn());	//computer take stones from kupa
	}
	PrintGame();	//print the game
	if (ply1.GetPile().CheckWhoStart() == true)	//check who start--if player start
	{
		TurnPlayer();	//player turn
		system("cls");	//clear screen
		PrintGame();	//print the game
		system("pause");
		ComputerTurn();	//computer turn
		system("cls");
		PrintGame();
	}
	else if (Computer.GetPile().CheckWhoStart() == true)	//if computer start
	{
		ComputerTurn();
		system("pause");
		system("cls");
		PrintGame();
	}

	do		//loop for the game! until the win
	{
		TurnPlayer();
		win = CheckWin();	//check win after the  move
		system("pause");		
		system("cls");
		PrintGame();
		if (win==0) ComputerTurn();	//if there is no win,computer turn
		system("cls");
		win = CheckWin();
		PrintGame();
	} while (win == ZERO);

	if (ply1.WinCheck()) cout << ply1.GetName() << " Win!!!! you win in " <<Computer.ReturnSum()<< " points"<< endl;	//if player win
	else if (Computer.WinCheck()) cout << Computer.GetName()<< " Win!!!! with :" <<ply1.ReturnSum()<<" points"<< endl;	//if computer win
	else	//if there is no moves and nothing in the kupa
	{																													//sum of computer dots
		if (Computer.ReturnSum() < ply1.ReturnSum())
		{
			cout << "nothing to put but " << Computer.GetName() << " Win!!!! by the sum of dots" << endl; //check the sum of stone dots
			cout << "point he get:" << Computer.ReturnSum() << endl;
		}
		else if (Computer.ReturnSum() > ply1.ReturnSum())
		{
			cout << "nothing to put but " << ply1.GetName() << " Win!!!! by the sum of dots" << endl;	//player sum dots
			cout << "point you get:" << ply1.ReturnSum() << endl;
		}

		else
		{
			cout << "No One Won! it is a tie!" << endl << "tie of :" << ply1.ReturnSum() << "point" << endl;	//if there is a tie in the sum of the stones dots

		}
	}
}
void Game::TurnPlayer()	//player turn
{
	int flagfirst = ZERO;	//flag for the firs move.we dont need check match of the stones
	if (Stoneontable.GetCurr() == ZERO) flagfirst = ONE;	//change the flag if its not the first move
	if ((NothingToPut(ONE)) && (flagfirst == ZERO))
	{
		do{		//loop for take from kupa until we get stone that we can put or wedont have stone in kupa
			cout << " you don't have nothing to put. you get one from the Kupa" << endl;
			if (Kupa.GetCurr()!= ZERO) ply1.AddStone(Kupa.DropStoneAndReturn());	//if there is no stone in kupa
			else return;
			system("pause");
			system("cls");
			PrintGame();
		} while ((NothingToPut(PLY)==true)||(Kupa.GetCurr()==ZERO));
		if (NothingToPut(PLY) == false)
		{		//if there is something to drop to the table
			int index;
			cout << "chose your number of the stone you wont to drop:" << endl;
			cin >> index;
			index--;	//the arr start from 0
			Stone todrop(ply1.GetPile().GetStoneFromIndex(index));//the stone we wont to drop
			ply1.GetPile().DropStoneByIndex(index);	//drop the stone from player arr
			Stoneontable.AddStoneInStart(todrop);	//add stone to table
			return;
		}
	}
	else		//if we have match stone
	{
		int index;
			cout << "chose your number of the stone you wont to drop between 1 to " << ply1.GetCurr()<<":" << endl;
			cin >> index;
			if ((0 >= index) || (index > ply1.GetCurr()))
			{
				system("cls");
				cout << "sorry, incorect index!"<<endl<<"bye bye"<<endl;
				exit(1);
			}
		index--;	//the arr start from 0,
		Stone todrop(ply1.GetPile().GetStoneFromIndex(index));
		if (flagfirst == ONE)	//the first move we can drop everything
		{
			ply1.GetPile().DropStoneByIndex(index);
			Stoneontable.AddStoneInStart(todrop);
			return;
		}
		else			//if its dont the first move
		{
			Stone startandend(Stoneontable.CreateStartAndEnd());	//the "stone" x from the start and y from the end of table arr
			while (todrop.Comparison(startandend) == false)	//ifthe stone dont match
			{
				cout << "******* stone you choose does not match*******" << endl;
				cout << "chose your number of the stone you wont to drop:" << endl;
				cin >> index;
				index--;
				todrop.SetStone(ply1.GetPile().GetStoneFromIndex(index));

			}

			if (todrop.BothSidesCheck(startandend))	//if we can put the stone in 2 sides
			{

				char side;
				do{
					cout << "Both sizes are match! which side do you want?" << endl << " right or left? Enter 'r' or 'l' " << endl;
					cin >> side;
					if (side == 'r' || side == 'R')	//right
					{
						startandend.SetX(-1);		//the s ide we dont need
						bool trash = todrop.WhichSide(startandend);
						ply1.GetPile().DropStoneByIndex(index);
						Stoneontable.AddStoneInEnd(todrop);
					}
					else if (side == 'l' || side == 'L')		//left
					{
						Stone s(startandend.Getx(), -1);		//the side we dont need
						bool trash = todrop.WhichSide(s);
						ply1.GetPile().DropStoneByIndex(index);
						Stoneontable.AddStoneInStart(todrop);
					}
				} while ((side != 'l') && (side != 'r') && (side != 'R') && (side!='L'));
			}
			else if (todrop.WhichSide(startandend))	//if only one sidematch
			{
				ply1.GetPile().DropStoneByIndex(index);
				Stoneontable.AddStoneInEnd(todrop);
			}
			else
			{
				/// switch start and end
				ply1.GetPile().DropStoneByIndex(index);
				Stoneontable.AddStoneInStart(todrop);
			}
		}
	}

}

void Game::ComputerTurn()
{
	
	int flagfirst = ZERO;		//flag to the first move
	if (Stoneontable.GetCurr() == ZERO)
	{									//random for the first computer trow
		flagfirst = ONE;
		int index = rand() % Computer.GetCurr();
		Stone todrop(Computer.GetPile().GetStoneFromIndex(index));
		Computer.GetPile().DropStoneByIndex(index);
		Stoneontable.AddStoneInEnd(todrop);
		return;
	}

	if ((NothingToPut(COMP)) && (flagfirst == ZERO))		//if the stones dont match and its not thefirst move
	{
		do{				//loop for take from kupa
			cout << "the computer doesnt have nothing to put" << endl;
			if (Kupa.GetCurr() != ZERO) Computer.AddStone(Kupa.DropStoneAndReturn());
			else return;
			system("pause");
			system("cls");
			PrintGame();
		} while ((NothingToPut(COMP) == true) || (Kupa.GetCurr() == ZERO));

		if ((Kupa.GetCurr() == ZERO) && (NothingToPut(COMP) == true))
		{
			return;
		}
	}
	
	ComputerDrop();
}

void Game::ComputerDrop()
{
	Stone st(Stoneontable.CreateStartAndEnd());	//the "stone" x from the start and y from the end of table arr
	for (int i = 0; i < Computer.GetCurr(); i++)	//loop for check all the stones
	{
		Stone todrop(Computer.GetPile().GetStoneFromIndex(i));
		if (todrop.Comparison(st))	//if the stone match
		{
			if (todrop.WhichSide(st))	//check wich side
			{
				Computer.GetPile().DropStoneByIndex(i);
			Stoneontable.AddStoneInEnd(todrop);
			}
			else		//one side match
			{
				Computer.GetPile().DropStoneByIndex(i);
				Stoneontable.AddStoneInStart(todrop);
			}
			break;
		}
	}
}

bool Game::NothingToPut(int cORp)
{				//when we dend -0 computer and- 1 player 
	Player * p;
	if (cORp == ONE) p = &ply1;
	else p = &Computer;
	Stone toCheck(Stoneontable.CreateStartAndEnd());

	for (int i = ZERO; i < p->GetCurr(); i++)
	{	//check all the stone if they match
		if (p->GetPile().GetStoneFromIndex(i).Comparison(toCheck)) return false;
	}

	return true;
}
void Game::PrintGame()
{			//screen print of the game
	cout << ply1.GetName() << "  Vs  computer" << endl;
	cout << "kupa:" << endl << "start--->";
	Kupa.PrintCloseKupa();
	cout << "<--- end" << endl;
	cout << "------------------computer stones:----------------------" << endl;
	Computer.ClosePlayerStonePrint();
	cout << "--------------------------------------------------------";
	cout << endl << endl << endl << endl;
	Stoneontable.PrintOpenTable();
	cout << endl << endl << endl << endl;
	cout << "-------------------------------" << ply1.GetName() << " stones" << "--------------------------------" << endl;
	ply1.OpenPlayerStonePrint();
	cout << "----------------------------------------------------------------" << endl;
}

bool Game::CheckWin()
{
	//check wo win
	int onkupa = Kupa.GetCurr();	//number of stone in kupa
	if ((NothingToPut(PLY) == true) && (onkupa== 0) && (NothingToPut(COMP) == true))	//the stonedont match and kupa is empty
	{
		return true;
	}
	if ((ply1.WinCheck()) || (Computer.WinCheck()))	//if player or computer win
	{
		return true;
	}
	return false;
}



Game::~Game()
{


}