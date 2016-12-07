/*Gavin Gervais & Garrett Jones
11/18/19
Computer Science 171 C++
Rev. Dr. Mathew Bell*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include<algorithm>

using namespace std;
void username();
void roll();
void scoretable();
void introduction();
void rules();
void one();
void two();
void three();
void four();
void five();
void six();


int numrolls[5];
int runningtotal;

int main()
{
	introduction();

	char rulebook;
	cout << "Would you like to see the rulebook? y/n " << endl;
	cin >> rulebook;
	if (tolower(rulebook) == 'y')
		rules();

	username();

	const int size = 6;
	srand(time(NULL));

	for (int i = 1; i < size; i++)
	{
		int diceroll = rand() % 6 + 1;
		numrolls[i] = diceroll;
	}
	
	cout << "Here is your first roll!" << endl;
	roll();

	cout << endl;
	cout << "Which (if any) of these dice would you like to re-roll?" << endl;
	cout << "If you don't want to re-roll any of them, just enter '0': ";



	return 0;
}
void roll()
{
		for(int x=0; x<5; x++)
			cout << " ___________" << setw(13);
		cout << endl;
		for (int x = 0; x<5; x++)
			cout << "|           |" << setw(5);
		cout << endl;
		for (int x = 0; x<5; x++)
			cout << "|           |" << setw(5);
		cout << endl;
		for (int x = 1; x<6; x++)
			cout << "|     " << numrolls[x] << "     |" << setw(5);
		cout << endl;
		for (int x = 0; x<5; x++)
			cout << "|           |" << setw(5);
		cout << endl;
		for (int x = 0; x<5; x++)
			cout << "|___________|" << setw(5);
		cout << endl;
		cout << setw(8) << "(1)";
		for (int x = 2; x < 6; x++)
			cout << setw(11) << "(" << x << ")";
		cout << endl;
}
void reroll()
{

}
void username()
{
	//User will enter their name, that will then be saved as a character.
	string name;
	cout << "What is your first name? ";
	cin >> name;
	cout << "Hello, " << name << ", glad you are here!" << endl;
	cout << endl;
}
void introduction()
{
	cout << endl;
	cout << "Welcome to Yahtzee!" << endl;
	cout << "As long as you have this code, you can play this version of Yahtzee on any device!" << endl;
	cout << endl;
}
void rules()
{
	cout << endl;
	cout << "Here are the rules: " << endl;
	cout << "------------------- " << endl;
	cout << "GAME START:" << endl;
	cout << "1. You will roll 5 dice and try to get the highest score." << endl;
	cout << "2. There are a total of 13 rounds. At the end of each round,";
	cout << " you will allocate the dice roll to the desired category on the score card." << endl;
	cout << "3. For each round, you will have a total of three rolls. After the third roll ";
	cout << "you must choose a category on the score card." << endl;
	cout << "4. At the end of each roll you will be given the opportunity to keep the current roll." << endl;
	cout << endl;
	cout << "SCORING:" << endl;
	cout << "1. To score your roll of the 5 dice, you must choose the location on the score card when prompted." << endl;
	cout << "2. Our program will then add all of the points and keep a running total." << endl;
	cout << "3. There are two sections to the score card-" << endl;
	cout << "\t The upper is composed of rolls 1-6 that will be scored on the summation of the same number." << endl;
	cout << "\t The lower section is composed of various sequences that will count for a set amount." << endl;
	cout << endl;
}
void scoretable()
{
}
void one()
{
	int numones = 0;
	int onetotal;
	for (int x = 0; x < 5; x++)
	{
		if (numrolls[x] == 1)
			numones + 1;

	}
	onetotal = numones * 1;
	runningtotal = runningtotal + onetotal;
}
void two()
{
	int numtwos = 0;
	int twototal;
	for (int x = 0; x < 5; x++)
	{
		if (numrolls[x] == 2)
			numtwos + 1;

	}
	twototal = numtwos * 2;
	runningtotal = runningtotal + twototal;
}
void three()
{
	int numthrees = 0;
	int threetotal;
	for (int x = 0; x < 5; x++)
	{
		if (numrolls[x] == 3)
			numthrees + 1;

	}
	threetotal = numthrees * 3;
	runningtotal = runningtotal + threetotal;
}
void four()
{
	int numfours = 0;
	int fourtotal;
	for (int x = 0; x < 5; x++)
	{
		if (numrolls[x] == 4)
			numfours + 1;

	}
	fourtotal = numfours * 4;
	runningtotal = runningtotal + fourtotal;
}
void five()
{
	int numfives = 0;
	int fivetotal;
	for (int x = 0; x < 5; x++)
	{
		if (numrolls[x] == 5)
			numfives + 1;

	}
	fivetotal = numfives * 5;
	runningtotal = runningtotal + fivetotal;
}
void six()
{
	int numsixs=0;
	int sixtotal;
	for (int x = 0; x < 5; x++)
	{
		if (numrolls[x] == 6)
			numsixs + 1;

	}
	sixtotal = numsixs * 6;
	runningtotal = runningtotal + sixtotal;
}