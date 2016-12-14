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
int upper(int selection);
void reroll();
void categories();

int numrolls[6];
int upperboard[7];

int runningtotal = 0; 
string numreroll;
int selection;
int game = 3;

int main()
{
	introduction();

	char rulebook;
	cout << "Would you like to see the rulebook? y/n " << endl;
	cin >> rulebook;
	if (tolower(rulebook) == 'y')
		rules();

	username();

	for (int z = 1; z < game; z++)
	{
		const int size = 6;
		srand(time(NULL));

		for (int i = 1; i < size; i++)
		{
			int diceroll = rand() % 6 + 1;
			numrolls[i] = diceroll;
		}

		cout << "Here is your 1 roll!" << endl;
		roll();

		for (int x = 2; x < 4; x++)
		{
			cout << endl;
			cout << "Which (if any) of these dice would you like to re-roll?" << endl;
			cout << "If you don't want to re-roll any of them, just enter '0': ";
			cin >> numreroll;

			if (numreroll[0] != '0')
			{
				reroll();
				cout << endl;
				cout << "Here is your " << x << " roll!" << endl;
				cout << endl;
				roll();
			}
			else if (numreroll[0] == '0')
				break;
		}

		cout << endl;
		categories();

		cout << endl;
		scoretable();
		cout << endl;
	}

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
	for (int x = 0; x < numreroll.length(); x++)
	{
		if (numreroll[x] == '1')
		{
			int diceroll = rand() % 6 + 1;
			numrolls[1] = diceroll;
		}
		else if (numreroll[x] == '2')
		{
			int diceroll = rand() % 6 + 1;
			numrolls[2] = diceroll;
		}
		else if (numreroll[x] == '3')
		{
			int diceroll = rand() % 6 + 1;
			numrolls[3] = diceroll;
		}
		else if (numreroll[x] == '4')
		{
			int diceroll = rand() % 6 + 1;
			numrolls[4] = diceroll;
		}
		else if (numreroll[x] == '5')
		{
			int diceroll = rand() % 6 + 1;
			numrolls[5] = diceroll;
		}
	}	
	

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
	cout << "UPPER SECTION" << endl;
	cout << "------------------- " << endl;
	cout << "One: " << upperboard[1] << setw(10) << "Two: " << upperboard[2] << setw(13) << "Three: " << upperboard[3] << endl;
	cout << "Four: " << upperboard[4] << setw(10) << "Five: " << upperboard[5] << setw(10) << "Six: " << upperboard[6] << endl;
	cout << endl;
	cout << "LOWER SECTION" << endl;
	cout << "------------------- " << endl;
	cout << "Total Points: " << runningtotal << endl;

}
void categories()
{
	cout << "Which category would you like to score these rolls in?" << endl;
	cout << endl;
	cout << "1. Ones" << endl;
	cout << "2. Twos" << endl;
	cout << "3. Threes" << endl;
	cout << "4. Fours" << endl;
	cout << "5. Fives" << endl;
	cout << "6. Sixes" << endl;
	cout << "7. 3 of a kind" << endl;
	cout << "8. 4 of a kind" << endl;
	cout << "9. Full House" << endl;
	cout << "10. Small Straight" << endl;
	cout << "11. Large Straight" << endl;
	cout << "12. Yahtzee" << endl;
	cout << "13. Chance" << endl;

	cout << endl;

	cout << "Please enter in the number that corresponds to the category: ";
	cin >> selection;

	if (selection == 1)
	{
		upperboard[1] = upper(1);
	}
	else if (selection == 2)
	{
		upperboard[2] = upper(2);
	}
	else if (selection == 3)
	{
		upperboard[3] = upper(3);
	}
	else if (selection == 4)
	{
		upperboard[4] = upper(4);
	}
	else if (selection == 5)
	{
		upperboard[5] = upper(5);
	}
	else if (selection == 6)
	{
		upperboard[6] = upper(6);
	}

}

int upper(int selection)
{
	int num = 0;
	for (int x = 1; x < 6; x++)
	{
		if (numrolls[x] == selection)
			num++;

	}
	int total = num * selection;
	runningtotal = runningtotal + total;

	return total;
}
int threekind()
{
	
}
int fourkind()
{

}
int fullhouse()
{

}
int smstraight()
{

}
int lgstraight()
{

}
int yahtzee()
{

}

