#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <math.h>

using namespace std;

int main()
{
	float price, money, change, roundedPrice, totalPrice, penny_1;
	int fiftyDollar, twentyDollar, tenDollar, fiveDollar, toonie, loonie, quarter, dime, nickel, penny_2;
	string items, choice, choice_2, cash;

	price = 0;
	//Give the user the list of games and its prices to buy.
	cout << "THE LIST:" << endl << endl;
	cout << "ITEM" << "                                    PRICE" << endl;
	cout << "A) Call of Duty: Advanced Warfare" << "       $35.76" << endl;
	cout << "B) Grand Theft Auto V" << "                   $50.45" << endl;
	cout << "C) Destiny" << "                              $45.32" << endl;
	cout << "D) Minecraft" << "                            $20.65" << endl;
	cout << "E) Assassin's Creed Unity" << "               $25.99" << endl;
	getline(cin, items);

	//If it is "A" or "a" it will add up the price of that object.
	if ((items == "A") || (items == "a"))
	{
		system("cls");
		price = price + 35.76;
	}

	//If it is "B" or "b" it will add up the price of that object.
	else if ((items == "B") || (items == "b"))
	{
		system("cls");
		price = price + 50.45;
	}

	//If it is "C" or "c" it will add up the price of that object.
	else if ((items == "C") || (items == "c"))
	{
		system("cls");
		price = price + 45.32;
	}

	//If it is "D" or "d" it will add up the price of that object.
	else if ((items == "D") || (items == "d"))
	{
		system("cls");
		price = price + 20.65;
	}

	//If it is "E" or "e" it will add up the price of that object.
	else if ((items == "E") || (items == "e"))
	{
		system("cls");
		price = price + 25.99;
	}

	//If it is something else which is not displayed it will re-ask the user the question.
	else
	{
		system("cls");
		cout << "---> ENTER A VALID LETTER <---" << endl;
	}
	//Calculates the tax price when HST is 13%
	roundedPrice = price * 1.13;

	//Round up the taxed priced to 2 decimal places.
	totalPrice = roundf(roundedPrice * 100) / 100;
	//Displays user their cost, HST and total cost.
	cout << "Cost       -----> $" << price << endl;					//ACTUAL COST 
	cout << "HST        -----> 13%" << endl;						//HST %
	cout << "Total Cost -----> $" << totalPrice << endl << endl;	//TOTAL COST

																	//Asks user to enter their money.
	cout << "Please enter your money." << endl;
	cout << "$";
	getline(cin, cash);

	//converts string to float.
	money = atof(cash.c_str());
	system("cls");

	//Calculates the change to hand back.
	change = money - totalPrice;

	//If money entered is greator that or equal to the total cost, then it will proceed to the change.
	if (money >= totalPrice)
	{
		//Calculates the change to handed back in Fifty,twenty,ten,five dollar bills, toonie, loonie, quater, dime, nickel and penny.

		change = (change * 100);
		fiftyDollar = (change / 5000);
		twentyDollar = (change - (fiftyDollar * 5000)) / 2000;
		tenDollar = (change - (fiftyDollar * 5000) - (twentyDollar * 2000)) / 1000;
		fiveDollar = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000)) / 500;
		toonie = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000) - (fiveDollar * 500)) / 200;
		loonie = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000) - (fiveDollar * 500) - (toonie * 200)) / 100;
		quarter = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000) - (fiveDollar * 500) - (toonie * 200) - (loonie * 100)) / 25;
		dime = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000) - (fiveDollar * 500) - (toonie * 200) - (loonie * 100) - (quarter * 25)) / 10;
		nickel = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000) - (fiveDollar * 500) - (toonie * 200) - (loonie * 100) - (quarter * 25) - (dime * 10)) / 5;
		penny_1 = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000) - (fiveDollar * 500) - (toonie * 200) - (loonie * 100) - (quarter * 25) - (dime * 10) - (nickel * 5));
	}

	//Rounds up the penny to avoid short chnaging the customers.
		penny_2 = roundf(penny_1 * 100) / 100;

	//Displays the change in Fifty,twenty,ten,five dollar bills, toonie, loonie, quater, dime, nickel and penny.
	cout << "Fifty Dollar bill(s)      : " << fiftyDollar << endl;
	cout << "Twenty Dollar bill(s)     : " << twentyDollar << endl;
	cout << "Ten Dollar bill(s)        : " << tenDollar << endl;
	cout << "Five Dollar bill(s)       : " << fiveDollar << endl;
	cout << "Toonie(s)                 : " << toonie << endl;
	cout << "Loonie(s)                 : " << loonie << endl;
	cout << "Quarter(s)                : " << quarter << endl;
	cout << "Dine(s)                   : " << dime << endl;
	cout << "Nickel(s)                 : " << nickel << endl;
	cout << "Penny(s)                  : " << penny_2 << endl << endl;
	return 0;


}