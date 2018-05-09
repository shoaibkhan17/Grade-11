//Author: Shoaib Khan
//Description: The program will ask the user 10 numbers and will sort them(ascending or decending) order. Displays the number list, average number,
//			   largest number and the smallest number.
//Date Creater: 10/05/15
//Date Modified: 05/06/15

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>

using namespace std;

//Declaring varaibles.
int number[10], average, singleNumber, largestNumber, secondLargestNumber, total;
string option, choice;
bool ask2, again, ask;

//Prototypes
void numberlist(int);
void averageCal(int);
void totalCal(int);
void largestNumberCal(int);
void secondLargestNumberCal(int);
void ascendingOrder(int);
void descendingOrder(int);
void arrangeNumbers(int);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void largestNumberCal(int number[])
{
	largestNumber = 0;

	for (int A = 0; A < 10; A++)
	{
		singleNumber = number[A];	//stores the numbers in an another variable.

		while (singleNumber > largestNumber)	//checks if the stored variable is greater than the largest number.
		{
			largestNumber = singleNumber;		//If it is, it makes that number the largest number.
		}
	}

	cout << "Largest Number: " << largestNumber << endl;		//Displays the largest number.
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void numberlist(int number[])
{
	cout << "Number List: ";

	for (int A = 0; A < 10; A++)
	{
		cout << number[A];		//Displays the number of the array one by one.

		if (A != 9)
		{
			cout << ", ";	//Adds a comma after ever number displayed except the last number. 
		}
	}

	cout << endl;

	largestNumberCal(number);		//Calls an another function.
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void averageCal(int number[])
{
	average = 0;	

	for (int A = 0; A < 10; A++)
	{
		average += number[A];	//Keeps adding the numbers one by one.
	}

	average /= 10;		//Divids the number by 10 (To get the average.)

	cout << "Average: " << average << endl;		//Displays the average number.
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void totalCal(int number[])
{
	total = 0;

	for (int A = 0; A < 10; A++)
	{
		total += number[A];		//Keeps adding the numbers one by one.
	}

	cout << "Total: " << total << endl;		//Displays the total.
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void secondLargestNumberCal(int largestNumber)
{
	secondLargestNumber = 0;

	for (int A = 0; A < 10; A++)
	{
		singleNumber = number[A];	//stores the numbers in an another variable.

		while ((singleNumber > secondLargestNumber) && (singleNumber != largestNumber))  //checks if the stored variable is greater than the second largest number -
		{																				//And is not equal to the largest number.
			secondLargestNumber = singleNumber;	    //If it is, it makes that number the second largest number.
		}
	}

	cout << "Second Largest Number: " << secondLargestNumber << endl;	//Displays the second largest number.
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void arrangeNumbers(int array[])
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10 - 1; y++)
		{
			if (array[y] > array[y + 1])		//If the previous number in the array is greater than the next number.
			{
				int temp = array[y + 1];		//Stores the value in an another variable.
				array[y + 1] = array[y];		//Makes the next number the first number (swap the two number.)
				array[y] = temp;				//Assigns the value of the next number to the previous number.
			}
		}
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ascendingOrder(int array[])
{
	cout << "Asceding order: ";	

	for (int i = 0; i < 10; i++)
	{
		cout << array[i];		//Displays the array in ascending order.

		if (i != 9)
		{
			cout << ", ";		//Adds a comma after ever number displayed except the last number. 
		}
	}

	cout << endl;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void descendingOrder(int array[])
{
	cout << "Descending order: ";

	for (int i = 10 - 1; i >= 0; i--)
	{
		cout << array[i];		//Displays the array in decending order.

		if (i != 0)
		{
			cout << ", ";		//Adds a comma after ever number displayed except the last number. 
		}
	}

	cout << endl;
}

void menuList(int number[])
{
	do
	{
		ask = false;

		cout << endl;							//Displays bunch of options to choose from. 
		cout << "Choose an option" << endl;
		cout << "A) Average" << endl;
		cout << "B) Total" << endl;
		cout << "C) Ascending Order" << endl;
		cout << "D) Descening Order" << endl;
		cin >> option;

		//If it equals to A.
		if ((option == "A") || (option == "a"))
		{
			cout << endl;
			averageCal(number);		//Calls another function.
		}

		//If it equals to B.
		else if ((option == "B") || (option == "b"))
		{
			cout << endl;
			totalCal(number);		//Calls another function.
		}

		//If it equals to C.
		else if ((option == "C") || (option == "c"))
		{
			cout << endl;
			arrangeNumbers(number);		//Calls another function.
			ascendingOrder(number);		//Calls another function.

		}

		//If it equals to D.
		else if ((option == "D") || (option == "d"))
		{
			cout << endl;
			arrangeNumbers(number);		//Calls another function.
			descendingOrder(number);		//Calls another function.
		}
		
		//If it does not matches one of the options.
		else
		{
			ask = true;
		}
	} while (ask == true);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{
	system("COLOR 1F");		//Changes the text and background colour.

	do
	{
		for (int A = 0; A < 10; A++)
		{
			cout << "Enter number [" << A + 1 << "] : ";	//Asks the user to enter a number.
			cin >> number[A];		//Stores that specific number.
		}

		cout << endl;

		numberlist(number);		//Calls an another function.
		secondLargestNumberCal(largestNumber);		//Calls an another function.
		menuList(number);		//Calls an another function.
		cout << endl;

		do
		{
			ask2, again = false;
			cout << "Do you want to try again? [Y] or [N]: ";		//Asks the user if they want to quit. 
			cin >> choice;

			//If yes
			if ((choice == "Y") || (choice == "y"))
			{
				system("cls");
				again = true;		//exit the loop.
			}

			//If no
			else if ((choice == "N") || (choice == "n"))
			{
			}

			//If it does not match with either yes or no.
			else
			{
				ask2 = true;
			}
		} while (ask2 == true);		
	} while (again == true);

	cout << endl;

	return 0;
	system("PAUSE");
}