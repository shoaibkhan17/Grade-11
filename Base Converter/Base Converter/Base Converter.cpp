//Author			: Shoaib Khan
//Description		: The program converts from one base to another base. (2~36)
//Date Creater		: 30/03/15
//Date Modified		: 29/04/15

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

//Prototype function
int converter(int);
int check(int);

//Declaring variables.
long int num_N, base_N, base_M, answer, base_10, checker;
const string digits("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
string result, userChoice;
bool checking = false;


int check(int number)
{
	checker = number;	//checker is assigned the same value as the binary/decimal number.

	for (int A = 0; checker > 0; A++)
	{
		//If the last digit of the number is not equal to 0 and not greator or equal to the base number. Then re-ask the question.
		if ((checker % 10 != 0) && (checker % 10 >= base_N))
		{
			checking = true;	
			break;		//Breaks the loop.
		}

		checker /= 10;		//Divide the checker by 10 to get rid of its previous digit.
	}

	return checking;
}

//Function to convert any base to base 10.
int converter(int numInt, int base_N)
{
	//Assigning answer a value of 0.
	answer = 0;
	for (int power = 0; numInt > 0; power++)	//Increases the *exponential power* everyturn.
	{
		if ((numInt % 10 != base_N) && (numInt % 10 != 0))		//If the binary/Decimal last digit number is equal to 1.
		{
			answer += (numInt % 10) * pow(base_N, power);	//Takes the last digit of the number and multiplys it with its base to the power of *expoenential power*
		}

		numInt /= 10;	//Divides the number by 10 to get rid of it's previous digit.
	}

	//return to the final answer.
	return answer;

}	//Keep repeating the loop until the number is equal to 0.

//Main file.
int main()
{
	//Changes the text colour to WHITE and the backgroud colour to BLUE.
	system("COLOR 3F");

	do
	{
		//Assigning all the variable a value of 0.
		num_N, base_N, base_M, answer, base_10, answer = 0;
		result.clear();		//Clearing the previous convertions results.

		do
		{
			//Asks the user to enter a base between 2 and 10.
			cout << "Enter Base[N] (2~10): ";
			cin >> base_N;

			//If the base if smaller that 2 or greator that 10 it will re-ask the question.
			if ((base_N < 2) || (base_N > 10))
			{
			}
		} while ((base_N < 2) || (base_N > 10));	//Restart the loop is the base is smaller that 2 or greator that 10.

		do
		{
			//Asks the user to enter the specific binary/decimal number depending on the base selected.
			cout << "Enter Base[" << base_N << "] Number: ";
			cin >> num_N;

			//If the binary/decimal number is equal to 0, it will re-ask the question.
			if (num_N == 0)
			{
				checking = true;
			}

			//If the binary/decimal number is not equal to 0, it will check if the binary/decimal number belongs to that specific base.
			else if (num_N > 0)
			{
				check(num_N);		//Calls the function to check wether the number entered belongs to that base.
			}
		} while (checking == true);		//Repeat if checking is equal to true.

		do
		{
			//Asks the user to enter a base between 2 and 36.
			cout << endl << "Convert to base[M] (2~36): ";
			cin >> base_M;

			//If the base if smaller that 2 or greator that 36 it will re-ask the question.
			if ((base_M < 2) || (base_M > 36))
			{
			}
		} while ((base_M < 2) || (base_M > 36));	//Restart the loop is the base is smaller that 2 or greator that 10.		

			converter(num_N, base_N);		//Calls the function to convert base_N to base 10.
			base_10 = answer;				//Gets the answer for the function

			for (; base_10 > 0; base_10 /= base_M)		//Loop ends when base_10 = 0. Keep dividing the base10 number by base M at the end of every loop.
			{
				result.insert(result.begin(), digits[abs(base_10 % base_M)]);		//Displays the specific digit for a specific number from the constant string digits.
			}

			//Display the M base and converted binary/decimal number (the result).
			cout << "Base[" << base_M << "] Number: " << result << endl << endl;

		do
		{
			//Asks the user to either e-try or quit the application.
			cout << "Re-try[R] or Quit[Q]?" << endl;
			cin >> userChoice;

			//If their choice is equal to R or r it will re start the application.
			if ((userChoice == "R") || (userChoice == "r"))
			{
				system("cls");		//Clear system screen.
			}

			//If their choice is not equal to the letter displayed, it will display an error message and re-ask the equestion.
			else if ((userChoice != "R") && (userChoice != "r") && (userChoice != "Q") && (userChoice != "q"))
			{
			}
		} while ((userChoice != "R") && (userChoice != "r") && (userChoice != "Q") && (userChoice != "q"));		//Repeat the loop if the choice is not equal to R, Q, r or q.
	} while ((userChoice == "R") || (userChoice == "r"));	//Repeat the loop if the choice is equal to R or r.

	return 0;

}