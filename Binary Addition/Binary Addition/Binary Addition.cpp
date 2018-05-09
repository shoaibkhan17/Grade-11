//Author			: Shoaib Khan
//Description		: The program converts from one base to another base. (2~36)
//Date Creater		: 30/03/15
//Date Modified		: 09/04/15

#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib>
#include <math.h>

using namespace std;

int main()
{
	string number_1, number_2;
	int digit_1, digit_2, exit, checker, bitSize, size;

	do
	{
		cout << "Enter bit size(4/6/8/10): ";
		cin >> size; 
	} while ((size != 4) && (size != 6) && (size != 8) && (size != 10));

			do
			{
				cout << "Enter first " << size << " bit binary number: ";
				cin >> number_1;

				digit_1 = atoi(number_1.c_str());

				if (number_1.size() == size)
				{
					checker = digit_1;	//checker is assigned the same value as the binary/decimal number.

					for (int A = 0; checker > 0; A++)
					{
						//If the last digit of the number is not equal to 0 and not greator or equal to the base number. Then re-ask the question.
						if (checker % 10 >= 2)
						{
							checker = 1000;		//Assign a value of 0 to the binary/decimal number.
							break;				//Break/quit the loop.
						}

						checker /= 10;		//Divide the checker by 10 to get rid of its previous digit.
					}
				}
			} while ((number_1.size() != size) || (checker > 10));

	do
	{
		cout << "Enter second " << size << " bit binary number: ";
		cin >> number_2;

		digit_2 = atoi(number_2.c_str());

		if (number_2.size() == size)
		{
			checker = digit_2;	//checker is assigned the same value as the binary/decimal number.

			for (int A = 0; checker > 0; A++)
			{
				//If the last digit of the number is not equal to 0 and not greator or equal to the base number. Then re-ask the question.
				if (checker % 10 >= 2)
				{
					checker = 1000;		//Assign a value of 0 to the binary/decimal number.
					break;				//Break/quit the loop.
				}

				checker /= 10;		//Divide the checker by 10 to get rid of its previous digit.
			}
		}
	} while ((number_2.size() != size) || (checker > 10));

	if (size == 4)
	{
		bitset<4> const a(number_1);
		bitset<4> const b(number_2);
		bitset<4> const m("1");
		bitset<4> result;
		for (auto i = 0; i < result.size(); ++i)
		{
			bitset<4> const diff(((a >> i)&m).to_ullong() + ((b >> i)&m).to_ullong() + (result >> i).to_ullong());
			result ^= (diff ^ (result >> i)) << i;
		}
		cout << result << endl;
	}

	else if (size == 6)
	{
		bitset<6> const a(number_1);
		bitset<6> const b(number_2);
		bitset<6> const m("1");
		bitset<6> result;
		for (auto i = 0; i < result.size(); ++i)
		{
			bitset<6> const diff(((a >> i)&m).to_ullong() + ((b >> i)&m).to_ullong() + (result >> i).to_ullong());
			result ^= (diff ^ (result >> i)) << i;
		}
		cout << result << endl;
	}

	else if (size == 8)
	{
		bitset<8> const a(number_1);
		bitset<8> const b(number_2);
		bitset<8> const m("1");
		bitset<8> result;
		for (auto i = 0; i < result.size(); ++i)
		{
			bitset<8> const diff(((a >> i)&m).to_ullong() + ((b >> i)&m).to_ullong() + (result >> i).to_ullong());
			result ^= (diff ^ (result >> i)) << i;
		}
		cout << result << endl;
	}

	else if (size == 10)
	{
		bitset<10> const a(number_1);
		bitset<10> const b(number_2);
		bitset<10> const m("1");
		bitset<10> result;
		for (auto i = 0; i < result.size(); ++i)
		{
			bitset<10> const diff(((a >> i)&m).to_ullong() + ((b >> i)&m).to_ullong() + (result >> i).to_ullong());
			result ^= (diff ^ (result >> i)) << i;
		}
		cout << result << endl;
	}
	return 0;
}
//
//	addition(digit_1, digit_2);
//
//
//	//cout << number_1 << " + " << number_2 << " = " << answer_1 << answer_2 << endl;
//	
//		return 0;
//}

//int main()
//{
//	int a[4];
//	int b[4];
//	int carry = 0;
//	int number1, number2;
//	int result[5];
//
//	cin >> number1;
//	cin >> number2;
//
//	for (int counter = 0; counter >= 10; counter++)
//	{
//		if (number1 % 10 >= 0)
//		{
//			a[counter] = number1 % 10;
//			cout << a[counter] << "N[1]";
//		}
//
//		if (number2 % 10 >= 0)
//		{
//			b[counter] = number2 % 10;
//			cout << b[counter] << "N[2]";
//		}
//
//		number1 /= 10;
//		number2 /= 10;
//	}



	//a[0] = 1;
	//a[1] = 0;
	//a[2] = 1;
	//a[3] = 1;

	//b[0] = 0;
	//b[1] = 1;
	//b[2] = 1;
	//b[3] = 1;

	//for (int i = 0; i<4; i++)
	//{

	//	if (a[i] + b[i] + carry == 3)
	//	{
	//		result[i] = 1;
	//		carry = 1;
	//	}
	//	if (a[i] + b[i] + carry == 2)
	//	{
	//		result[i] = 0;
	//		carry = 1;
	//	}
	//	if (a[i] + b[i] + carry == 1)
	//	{
	//		result[i] = 1;
	//		carry = 0;
	//	}
	//	if (a[i] + b[i] + carry == 0)
	//	{
	//		result[i] = 0;
	//		carry = 0;
	//	}


	//}
	//result[4] = carry;
	//for (int j = 4; j >= 0; j--)
	//{
	//	cout << result[j];

	//}
	//cout << endl;
//
//	return 0;
//}