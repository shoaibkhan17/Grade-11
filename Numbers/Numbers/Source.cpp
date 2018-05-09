#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int number[10], average, singleNumber, largestNumber, secondLargestNumber;

void numberlist(int);
void averageCal(int);
void largestNumberCal(int);
void secondLargestNumberCal(int);
void ascending(int);
void decending(int);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void numberlist(int number[])
{
	cout << "Number List: ";

	for (int A = 0; A < 10; A++)
	{
		cout << number[A];

		if (A != 9)
		{
			cout << ", ";
		}
	}

	cout << endl;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void averageCal(int number[])
{
	average = 0;

	for (int A = 0; A < 10; A++)
	{
		average += number[A];
	}
	
	average /= 10;
	
	cout << "Average: " << average << endl;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void largestNumberCal(int number[])
{
	largestNumber = 0;

	for (int A = 0; A < 10; A++)
	{
		singleNumber = number[A];

			while (singleNumber > largestNumber)
			{
				largestNumber = singleNumber;
			}
	}

	cout << "Largest Number: " << largestNumber << endl;
	secondLargestNumberCal(largestNumber);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void secondLargestNumberCal(int largestNumber)
{
	secondLargestNumber = 0;

	for (int A = 0; A < 10; A++)
	{
		singleNumber = number[A];

		while ((singleNumber > secondLargestNumber) && (singleNumber != largestNumber))
		{
			secondLargestNumber = singleNumber;
		}
	}

	cout << "Second Largest Number: " << secondLargestNumber << endl;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void numberOrders(int array[])
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10 - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				int temp = array[y + 1];
				array[y + 1] = array[y];
				array[y] = temp;
			}
		}
	}
	cout << "Asceding order: ";

	for (int i = 0; i < 10; i++)
	{
		cout << array[i];

		if (i != 9)
		{
			cout << ", ";
		}
	}

	cout << endl;

	cout << "Decending order: ";

	for (int i = 10 - 1; i >= 0; i--)
	{
		cout << array[i];

		if (i != 0)
		{
			cout << ", ";
		}
	}

	cout << endl;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{
	system("COLOR 1F");
	for (int A = 0; A < 10; A++)
	{
		cout << "Enter number [" << A + 1 << "] : ";
		cin >> number[A];
	}

	cout << endl; 

	numberlist(number);
	numberOrders(number);
	largestNumberCal(number);
	averageCal(number);

	cout << endl;

	return 0;
	system("PAUSE");
}