/* Assignment: 2
Campus: Beer-Sheva 
Author1: tomer marzok, ID: 203396809
Date: 14/4/2015 */
#include "Game.h"
#include <string>
#include <iostream>
#include<string.h>
using namespace std;


int main()
{
	string name;
	cout << "[][]  [][] domino game!! [][]  [][]"<<endl<< "          enter your name:" << endl;
	cin >> name;
	system("cls");
	Game game(name);
	game.run();
	system("pause");
	return 0;
	
}