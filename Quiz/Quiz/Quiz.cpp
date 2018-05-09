//Author: Shoaib Khan
//Description: The program will ask the user 5 multiple choice questions and then give them their mark as well as their percentage after the test.
//Date Creater: 10/02/15
//Date Modified: 2/03/15

#include<iostream>
#include<string>
#include<math.h>
#include<cstdlib>
#include<cstdint>

using namespace std;

//Declaring variables
int usermark;
bool ask = true;
bool run = true;
float result;
string answer, question, answer_1, answer_2, option_1, option_2, option_3, option_4, option_5, option_6, choice;


int genericQuestion(string, string, string, string, string, string, string, string, string);
int resultCalc(int);

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int genericQuestion(string question, string answer_1, string answer_2, string option_1, string option_2, string option_3, string option_4, string option_5, string option_6)
{
	do
	{
		cout << question << endl;
		getline(cin, answer);

		if ((answer == answer_1) ||(answer == answer_2))
		{	
			cout << "\nCORRECT\n" << endl;
			return 1;
		}

		else if ((answer == option_1) || (answer == option_2) || (answer == option_3) || (answer == option_4) || (answer == option_5) || (answer == option_6))
		{
			cout << "\nINCORRECT\n" << endl;
			return 0;
		}

		else
		{
			cout << "\nINVALID \"TRY AGAIN\"\n" << endl;
		}
	} while (ask == true);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int resultCalc(int mark)
{
	result = ((mark / 5.00) * 100.00);
	return result;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{ 
	//Changes the text colour to Aqua.
	system("color 3");

	do
	{
		//The user begins with a score 0
		usermark = 0;

		//Asking the user their first question.
		usermark += genericQuestion("What is the biggest planet in our solar system? \nA) Saturn \nB) Earth \nC) Jupiter \nD) Venus", "C", "c", "A", "a", "B", "b", "D", "d");

		system("COLOR 4");
		//Asking the user their second question.
		usermark += genericQuestion("Pure water has a pH level of? \nA) 0 \nB) 9 \nC) 14 \nD) 7", "D", "d", "A", "a", "B", "b", "C", "c");


		//Asking the user their third question.
		usermark += genericQuestion("How many bones do sharks have in their bodies? \nA) 293 \nB) 0 \nC) 300 \nD) 197", "B", "b", "A", "a", "D", "d", "C", "c");


		//Asking the user their fourth question.
		usermark += genericQuestion("Common name for dihydrogen monoxide is? \nA) Water \nB) Baking soda \nC) Limestone \nD) Aspirin", "A", "a", "B", "b", "D", "d", "C", "c");


		//Asking the user their fifth question.
		usermark += genericQuestion("The hardest substance available on earth? \nA) Boron Carbide \nB) Titanium Diboride \nC) Rock \nD) Diamond", "D", "d", "B", "b", "A", "a", "C", "c");

		resultCalc(usermark);

		//Display user's marks and thier percentage
		cout << endl << "You got " << usermark << " out of 5" << endl << result << "%" << endl;

			do
			{
				//Will ask the user if they want to either quit or re-do their test.
				cout << endl << "Press {R} to retry or {Q} to exit." << endl;
				getline(cin,choice);

				//If they choose to re-try.
				if ((choice == "R") || (choice == "r"))
				{
					system("CLS");
					ask = false;
				}

				//If they choose to quit.
				else if ((choice == "Q") || (choice == "q"))
				{
					ask = false;
					run = false;
				}

				//Invalid answer re-ask.
				else
				{
				}
			} while (ask == true);
	} while (run == true);

	return 0;
}
