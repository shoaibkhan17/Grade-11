//Author		: Shoaib Khan
//Description	: Slot Machines.
//Date Creater	: 18/05/15
//Date Modified	: 05/06/15

#include<iostream>
#include <string>

using namespace std;

//Declaring variables.
int money, plays;
bool again, run;
string choice;

//Constructs a structure.
struct slotMachine
{
	int play = 0;
	int pay = 0;
	int playedBefore = 0;
};

//Prototype.
void slot_Machine(slotMachine*);

//===================================================================================================================================
void slot_Machine(slotMachine *machine)
{
	if (((*machine).playedBefore % (*machine).play == 0) && ((*machine).playedBefore != 0))		//If the machine played before equals to its amount.
	{
		money += (*machine).pay;		//Increases the money by the amount assigned.
	}

	(*machine).playedBefore++;		//Increases the amount of time that machine was been played by one.
	money--;		//Decreases the money by one.
	plays++;		//Increases the total plays by one.
}

void slot_Machine_Test(slotMachine machine)
{
	if (((machine).playedBefore % (machine).play == 0) && ((machine).playedBefore != 0))		//If the machine played before equals to its amount.
	{
		money += (machine).pay;		//Increases the money by the amount assigned.
	}

	(machine).playedBefore++;		//Increases the amount of time that machine was been played by one.
	money--;		//Decreases the money by one.
	plays++;		//Increases the total plays by one.
}

//===================================================================================================================================
int main()
{
	do
	{
		plays = 0;		//Default plays is equal to 0.
		run = false;

		cout << "Enter the number of quaters you have: ";		//Asks the user to enter their money.
		cin >> money;

		cout << "\nEnter the amount of times the slot machines have already been played\n\n";		//Asks the user how many times was the machines played before.


		////Structure of machines.
		//slotMachine *machine1 = new slotMachine;	//Pointers
		//(*machine1).pay = 30;		//Assigning the pay value of machine 1 equals to 30.
		//(*machine1).play = 35;		//Assigning the play value of machine 1 equals to 35.

		//slotMachine *machine2= new slotMachine;		//Pointes
		//(*machine2).pay = 60;		//Assigning the pay value of machine 2 equals to 60.
		//(*machine2).play = 100;		//Assigning the play value of machine 2 equals to 100.

		//slotMachine *machine3= new slotMachine;		//pointes
		//(*machine3).pay = 9;		//Assigning the pay value of machine 3 equals to 9.
		//(*machine3).play = 10;		//Assigning the play value of machine 3 equals to 10.

		slotMachine mach1;
		mach1.pay = 30;
		mach1.play = 35;

		slotMachine mach2;
		mach2.pay = 60;
		mach2.play = 100;

		slotMachine mach3;
		mach3.pay = 9;
		mach3.play = 10;

		cout << "Machine[1]: ";
		cin >> mach1.playedBefore;		//Stores the value of how many times machine 1 was played before. 

		cout << "Machine[2]: ";
		cin >> mach2.playedBefore;		//Stores the value of how many times machine 2 was played before. 

		cout << "Machine[3]: ";
		cin >> mach3.playedBefore;		//Stores the value of how many times machine 3 was played before. 

		do
		{
			if (money > 0)
			{
				slot_Machine_Test(mach1);
			}

			if (money > 0)
			{
				slot_Machine_Test(mach2);
			}

			if (money > 0)
			{
				slot_Machine_Test(mach3);
			}
		} while (money > 0);

		cout << "\nNumber of plays: " << plays << endl << endl;
		
		do
		{
			cout << "Want to try again? [Y] or [N]: ";
			cin >> choice;

			if ((choice == "Y") || (choice == "y"))
			{
				system("cls");
				run = true;
			}

			else if ((choice == "N") || (choice == "n"))
			{
			}

			else
			{
				again = true;
			}
		} while (again == true);
	} while (run == true);

	system("PAUSE");
	return 0;
}