//Author: Shoaib Khan
//Description: The program gives a list of items and its prices for the user to buy and then asks for money from the user and gives him/her change
//			   in 50 dollar bills, 20 dollar bills, 10 dollar bills, 5 dollar bills, Toonie, Loonie, quarter, dime, nikel and penny.
//Date Creater: 5/03/15
//Date Modified: 12/03/15

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
	//Declaring Variables.
	float price, money, change, roundedPrice, totalPrice, penny_1;
	int fiftyDollar, twentyDollar, tenDollar, fiveDollar, toonie, loonie, quarter, dime, nickel, penny_2;
	ofstream bill;
	string platform, items, choice, choice_2, cash, billName;

	//Changes the text colour to Red and the backgroud colour to white.
	system("color F4");

	do
	{
		//Clear the system.
		system("cls");

		//Asks the user to enter their receipt name.
		cout << "ENTER RECEIPT NAME" << endl;;
		getline(cin, billName);
		cout << endl;
		system("cls");

		do
		{
			//Sets the console title to "***Game Store***".
			SetConsoleTitle(TEXT("***Game Store***"));

			//Initial value of the prie is 0
			price = 0;

			//Asks the user to choose their platform.
			cout << "JUST ENTER THE LETTER" << endl << endl;
			cout << "Select your platform" << endl;
			cout << "A) Xbox one" << endl;
			cout << "B) PC" << endl;
			cout << "C) PS4" << endl;
			getline(cin, platform);

			//If it is "A" or "a" clear the screen and move on to the list.
			if ((platform == "A") || (platform == "a"))
			{
				system("cls");
			}

			//If it is "B" or "b" clear the screen and move on to the list.
			else if ((platform == "B") || (platform == "b"))
			{
				system("cls");
			}

			//If it is "C" or "c" clear the screen and move on to the list.
			else if ((platform == "C") || (platform == "c"))
			{
				system("cls");
			}

			//If it is something else which is not displayed it will re-ask the user the question.
			else
			{
				system("cls");
				cout << "---> PLEASE ENTER A VALID LETTER <---" << endl;
			}
		} while ((platform != "A") && (platform != "a") && (platform != "b") && (platform != "B") && (platform != "C") && (platform != "c")); //re start the loop if not equal to A,B,C,a,b,c.

		do
		{
			do
			{
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

			} while ((items != "A") && (items != "B") && (items != "C") && (items != "D") && (items != "E") && (items != "a") && (items != "b") && (items != "c") && (items != "d") && (items != "e")); //re start the loop if not equal to A,B,C,D,E,a,b,c,d,e.

			do
			{
				//After choosing what they want to buy as their first object it will ask the user if they want to buy anything else.
				cout << "Do you want to buy any thing else?" << endl;
				cout << "[Y] yes or [N] no to proceed to cart" << endl;
				getline(cin, choice);


				//If it is "Y" or "y" it will display the list again.
				if ((choice == "y") || (choice == "Y"))
				{
					system("cls");
				}

				//If it is "N" or "n" it will not display the list again and will move on to the cart.
				else if ((choice == "n") || (choice == "N"))
				{
					system("cls");
				}

				//If it is something else which is not displayed it will re-ask the user the question.
				else
				{
					system("cls");
					cout << "---> PLEASE ENTER A VALID LETTER <---" << endl;
				}

			} while ((choice != "n") && (choice != "y") && (choice != "N") && (choice != "Y")); //re start the loop if not equal to Y,y,N,n.
		} while ((choice == "y") || (choice == "Y")); //re start the loop if not equal to Y,y.

		//Calculates the tax price when HST is 13%
		roundedPrice = price * 1.13;
		
		//Round up the taxed priced to 2 decimal places.
		totalPrice = roundf(roundedPrice * 100) / 100;

		do
		{
			//Creates a notepad file of the "RECEIPT NAME" entered earlier in the program.
			bill.open("C:\\notepad\\" + billName + ".txt");
			cout << endl << endl;

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
				//Displays a saved copy of your cost, HST, total cost, amount entered and change in a notepad created before.
				bill << "Cost          -----> $" << price << endl;
				bill << "HST           -----> 13%" << endl;
				bill << "Total Cost    -----> $" << totalPrice << endl;
				bill << "Money entered -----> $" << money << endl;
				bill << "Change        -----> $" << change << endl << endl;
				cout << endl << endl << "Your change is $" << change << endl << endl;

				//Calculates the change to handed back in Fifty,twenty,ten,five dollar bills, toonie, loonie, quater, dime, nickel and penny.
				
				/*change = (change * 100);
				fiftyDollar = (change / 5000);
				twentyDollar = (change - (fiftyDollar * 5000)) / 2000;
				tenDollar = (change - (fiftyDollar * 5000) - (twentyDollar * 2000)) / 1000;
				fiveDollar = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000)) / 500;
				toonie = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000) - (fiveDollar * 500)) / 200;
				loonie = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000) - (fiveDollar * 500) - (toonie * 200)) / 100;
				quarter = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000) - (fiveDollar * 500) - (toonie * 200) - (loonie * 100)) / 25;
				dime = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000) - (fiveDollar * 500) - (toonie * 200) - (loonie * 100) - (quarter * 25)) / 10;
				nickel = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000) - (fiveDollar * 500) - (toonie * 200) - (loonie * 100) - (quarter * 25) - (dime * 10)) / 5;
				penny_1 = (change - (fiftyDollar * 5000) - (twentyDollar * 2000) - (tenDollar * 1000) - (fiveDollar * 500) - (toonie * 200) - (loonie * 100) - (quarter * 25) - (dime * 10) - (nickel * 5));*/

				change = (change * 100);
				fiftyDollar = (change / 5000);
				twentyDollar = 


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

				//Displays the change in Fifty,twenty,ten,five dollar bills, toonie, loonie, quater, dime, nickel and penny in the notepad file created.
				bill << "Fifty Dollar bill(s)      : " << fiftyDollar << endl;
				bill << "Twenty Dollar bill(s)     : " << twentyDollar << endl;
				bill << "Ten Dollar bill(s)        : " << tenDollar << endl;
				bill << "Five Dollar bill(s)       : " << fiveDollar << endl;
				bill << "Toonie(s)                 : " << toonie << endl;
				bill << "Loonie(s)                 : " << loonie << endl;
				bill << "Quarter(s)                : " << quarter << endl;
				bill << "Dine(s)                   : " << dime << endl;
				bill << "Nickel(s)                 : " << nickel << endl;
				bill << "Penny(s)                  : " << penny_2 << endl << endl;

				//Closes and saves the notepad file created.
				bill.close();
			}

			//If the user enters a amound which is lower than the actual cost it will re-ask them to enter an resonable amount.
			else
			{
				system("cls");
				cout << "Please enter a reasonable amount" << endl;
			}
		} while (money < totalPrice); //Restart the loop if the money is not greator than the total cost.

		do
		{
			//Asks the user if they want to buy anyrthing else or no.
			cout << "Do you want to buy anything else?" << endl;
			cout << "[Y]yes or [N]no" << endl;
			getline(cin, choice_2);

			//If "y" or "Y" it will re-start the whole operation.
			if ((choice_2 == "y") || (choice_2 == "Y"))
			{
				system("cls");
			}

			//If "n" or "N" it will quit the operation.
			else if ((choice_2 == "N") || (choice_2 == "n"))
			{
				//Before quiting it will display a thank you for coming message.
				cout << endl << endl << "Thank you for coming. Come again" << endl << endl;
			}

			//If it is something else which is not display it will re-ask the user the question.
			else
			{
				system("cls");
				cout << "---> PLEASE ENTER A VALID LETTER <---" << endl;
			}
		} while ((choice_2 != "Y") && (choice_2 != "y") && (choice_2 != "N") && (choice_2 != "n")); //re start the loop if not equal to Y,y,N,n.
	}while ((choice_2 == "y") || (choice_2 == "Y")); //re start the loop if not equal to Y,y.

	//Quit the console application.
	return 0;
}