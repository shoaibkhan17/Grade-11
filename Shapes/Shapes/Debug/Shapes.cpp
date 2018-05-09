//Author: Shoaib Khan
//Description: The program draws shapes by using various codes. It will ask the user for a particular shape, its length/width and its character.
//Date Creater: 19/02/15
//Date Modified: 25/02/15

#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <math.h>

using namespace std;

//Declaring variables
string color, userChoice, userPreference, size, size_2;
char userCharacter, userCharacter_2, trunkSize;
int length, width, userSize, userSize_2, builder, area, trunkArea, leafArea, trunkHeight;

int main()
{
	do
	{
		builder = 1; //Helps in building semetrical triangle as well as the tree.
		do
		{
			//Asks the user to choose their prefered text colour.
			cout << "Choose the text colour:" << endl;
			cout << "A) Red" << endl;
			cout << "B) Blue" << endl;
			cout << "C) Green" << endl;
			cout << "D) Yellow" << endl;
			cout << "E) White" << endl;
			cout << "F) Aqua" << endl;
			cin >> color;

			//If they choose "a" or "A" the text colour will change to red.
			if ((color == "a") || (color == "A"))
			{
				system("Color 4");
				system("cls");
			}

			//If they choose "b" or "B" the text colour will change to blue.
			else if ((color == "b") || (color == "B"))
			{
				system("Color 1");
				system("cls");
			}

			//If they choose "c" or "C" the text colour will change to green.
			else if ((color == "c") || (color == "C"))
			{
				system("Color 2");
				system("cls");
			}

			//If they choose "d" or "D" the text colour will change to yellow.
			else if ((color == "d") || (color == "D"))
			{
				system("Color 6");
				system("cls");
			}

			//If they choose "e" or "E" the text colour will change to white.
			else if ((color == "e") || (color == "E"))
			{
				system("Color 7");
				system("cls");
			}

			//If they choose "e" or "E" the text colour will change to aqua.
			else if ((color == "f") || (color == "F"))
			{
				system("Color 3");
				system("cls");
			}

			//If they type in any other letter it will re-ask the question of chosing the text colour.
			else
			{
				system("cls");
				cout << "---> ENTER A VALID LETTER <---" << endl << endl;
			}
		} while ((color != "A") && (color != "a") && (color != "B") && (color != "b") && (color != "C") && (color != "c") && (color != "D") && (color != "d") && (color != "E") && (color != "e") && (color != "F") && (color != "f"));


		//Will ask the user a character to display it for the formation of the shapes
		cout << "Enter a *SINGLE* character that you would prefer to be used for " << endl << "the formation of the shapes." << endl;
		cin >> userCharacter;
		system("cls");

		do
		{
			//Asks the user what shape they whould prefer
			cout << "What shape whould you prefer:" << endl;
			cout << "A) Square" << endl;
			cout << "B) Rectangle" << endl;
			cout << "C) Right triangle" << endl;
			cout << "D) Other right triangle" << endl;
			cout << "E) Symmetrical triangle" << endl;
			cout << "F) Tree" << endl;
			cin >> userChoice;
			system("cls");

			//If they choose "a" or "A" they will be asked some questions as followed below.
			if ((userChoice == "A") || (userChoice == "a"))
			{
				//Checks if the user types in a string instead of an int, if they do it will request then to re-type a number.
				do
				{
					//Asks the user what length they would prefer for thier square.
					cout << "What length would you prefer for your square?" << endl << "ENTER A NUMBER" << endl;
					cin >> size;

					//Converts string to int.
					length = atoi(size.c_str());
					system("cls");

					//If the length is 0 it will ask the user to re-enter the length of the square.
					if (length == 0)
					{
						cout << "---> PLEASE ENTER A VALID NUMBER <---" << endl << endl;
					}

				} while (length == 0);

						//Calculating the area of the square.
						area = (length * length);
						cout << endl << endl;

						//Creates a particlar square with a specific length and character.
						for (int a = 0; a < length; a++)
						{

							cout << " " << userCharacter << " ";

							for (int b = 0; b < (length - 1); b++)
							{
								cout << userCharacter << " ";
								Sleep(6);

							}
							cout << endl;
						}

						cout << endl;

						//Displays the area for the user's square.
						cout << "Area of your square is " << area << " characters" << endl << endl;

						//Asks the user either they want to quit or redo the program.
						do
						{
							cout << "Enter [Q] to quit or [R] to redo" << endl;
							cin >> userPreference;

							//If they enter "Q" or "q" it will quit the program. 
							if ((userPreference == "Q") || (userPreference == "q"))
							{
							}

							//If they enter "R" or "r" it will restart the program. 
							else if ((userPreference == "R") || (userPreference == "r"))
							{
								system("cls");
							}

							//If they enter anything else it will re-ask the question to either quit or redo.
							else
							{
								system("cls");
								cout << "---> ENTER A VALID LETTER <---" << endl << endl;
							}

						} while ((userPreference != "R") && (userPreference != "r") && (userPreference != "Q") && (userPreference != "q"));
					}

			//If they choose "b" or "B" they will be asked some questions as followed below.
			else if ((userChoice == "b") || (userChoice == "B"))
			{
				//Checks if the user types in a string instead of an int, if they do it will request then to re-type a number.
				do 
				{
					//Asks the user what length they would prefer for thier rectangle.
					cout << "What length would you prefer for your rectangle?" << endl << "ENTER A NUMBER" << endl;
					cin >> size;

					//Converts string to int.
					length = atoi(size.c_str());
					system("cls");

					//If the length is 0 it will ask the user to re-enter the length of the rectangle.
					if (length == 0)
					{
						cout << "---> PLEASE ENTER A VALID NUMBER <---" << endl << endl;
					}

				} while (length == 0);

				//Checks if the user types in a string instead of an int, if they do it will request then to re-type a number.
				do
				{
					//Asks the user what width they would prefer for thier rectangle.
					cout << "What width would you prefer for your rectangle?" << endl << "ENTER A NUMBER" << endl;
					cin >> size_2;

					//Converts string to int.
					width = atoi(size_2.c_str());
					system("cls");

					//If the width is 0 it will ask the user to re-enter the width of the rectangle.
					if (width == 0)
					{
						cout << "---> PLEASE ENTER A VALID NUMBER <---" << endl << endl;
					}

				} while (width == 0);

				//Calculating the area of the rectangle.
				area = (length * width);
				cout << endl << endl;

				//Creates a particlar rectnagle with a specific length, width and character.
				for (int a = 0; a < length; a++)
				{
					cout << "    " << userCharacter << " ";

					for (int b = 1; b < width; b++)
					{
						cout << userCharacter << " ";
						Sleep(6);
					}

					cout << endl;
				}

				cout << endl;

				//Displays the area for the user's rectangle.
				cout << "Area of your rectangle is " << area << " characters" << endl << endl;

				//Asks the user either they want to quit or redo the program.
				do
				{
					cout << "Enter [Q] to quit or [R] to redo" << endl;
					cin >> userPreference;

					//If they enter "Q" or "q" it will quit the program. 
					if ((userPreference == "Q") || (userPreference == "q"))
					{
					}

					//If they enter "R" or "r" it will restart the program. 
					else if ((userPreference == "R") || (userPreference == "r"))
					{
						system("cls");
					}

					//If they enter anything else it will re-ask the question to either quit or redo.
					else
					{
						system("cls");
						cout << "---> ENTER A VALID LETTER <---" << endl << endl;
					}

				} while ((userPreference != "R") && (userPreference != "r") && (userPreference != "Q") && (userPreference != "q"));
			}

			//If they choose "c" or "C" they will be asked some questions as followed below.
			else if ((userChoice == "c") || (userChoice == "C"))
			{
				//Checks if the user types in a string instead of an int, if they do it will request then to re-type a number.
				do
				{
					//Asks the user what length they would prefer for thier right triangle.
					cout << "What length would you prefer for your right triangle?" << endl << "ENTER A NUMBER" << endl;
					cin >> size;

					//Converts string to int.
					length = atoi(size.c_str());
					system("cls");

					//If the length is 0 it will ask the user to re-enter the length of the right triangle.
					if (length == 0)
					{
						cout << "---> PLEASE ENTER A VALID NUMBER <---" << endl << endl;
					}

				} while (length == 0);

				//Calculating the area of the right triangle.
				area = ((length * length) / 2);
				cout << endl << endl;

				//Creates a particlar right triangle with a specific length/width and character.
				for (int a = 0; a < length + 1; a++)
				{
					for (int b = 0; b < a; b++)
					{
						cout << userCharacter;
					}
					cout << endl;
					cout << "  ";
					Sleep(16);
				}

				cout << endl;

				//Displays the area for the user's right triangle.
				cout << "Area of your right triangle is " << area << " characters" << endl << endl;

				//Asks the user either they want to quit or redo the program.
				do
				{
					cout << "Enter [Q] to quit or [R] to redo" << endl;
					cin >> userPreference;

					//If they enter "Q" or "q" it will quit the program. 
					if ((userPreference == "Q") || (userPreference == "q"))
					{
					}

					//If they enter "R" or "r" it will restart the program. 
					else if ((userPreference == "R") || (userPreference == "r"))
					{
						system("cls");
					}

					//If they enter anything else it will re-ask the question to either quit or redo.
					else
					{
						system("cls");
						cout << "---> ENTER A VALID LETTER <---" << endl << endl;
					}

				} while ((userPreference != "R") && (userPreference != "r") && (userPreference != "Q") && (userPreference != "q"));
			}

			//If they choose "d" or "D" they will be asked some questions as followed below.
			else if ((userChoice == "d") || (userChoice == "D"))
			{
				//Checks if the user types in a string instead of an int, if they do it will request then to re-type a number.
				do
				{
					//Asks the user what length they would prefer for thier other right triangle.
					cout << "What length would you prefer for your other right triangle?" << endl << "ENTER A NUMBER" << endl;
					cin >> size;

					//Converts string to int.
					length = atoi(size.c_str());
					system("cls");

					//If the length is 0 it will ask the user to re-enter the length of the other right triangle.
					if (length == 0)
					{
						cout << "---> PLEASE ENTER A VALID NUMBER <---" << endl << endl;
					}

				} while (length == 0);

				//Calculating the area of the other right triangle.
				area = ((length * length) / 2);
				cout << endl << endl;

				//Creates a particlar other right triangle with a specific length/width and character.
				for (int a = 0; a < length + 1; a++)
				{
						for (int s = length - a; s > 0; s--)
							cout << "  ";

						for (int x = 1; x <= a; x++)
						{
							cout << userCharacter << " ";
						}
						cout << endl;
						Sleep(16);
				}

				cout << endl;

				//Displays the area for the user's other right triangle.
				cout << "Area of your other right triangle is " << area << " characters" << endl << endl;

				//Asks the user either they want to quit or redo the program.
				do
				{
					cout << "Enter [Q] to quit or [R] to redo" << endl;
					cin >> userPreference;

					//If they enter "Q" or "q" it will quit the program. 
					if ((userPreference == "Q") || (userPreference == "q"))
					{
					}

					//If they enter "R" or "r" it will restart the program. 
					else if ((userPreference == "R") || (userPreference == "r"))
					{
						system("cls");
					}

					//If they enter anything else it will re-ask the question to either quit or redo.
					else
					{
						system("cls");
						cout << "---> ENTER A VALID LETTER <---" << endl << endl;
					}

				} while ((userPreference != "R") && (userPreference != "r") && (userPreference != "Q") && (userPreference != "q"));
			}

			//If they choose "e" or "E" they will be asked some questions as followed below.
			else if ((userChoice == "E") || (userChoice == "e"))
			{
				//Checks if the user types in a string instead of an int, if they do it will request then to re-type a number.
				do
				{
					//Asks the user what length they would prefer for thier symetrical triangle.
					cout << "What length would you prefer for your symetrical triangle?" << endl << "ENTER A NUMBER" << endl;
					cin >> size;

					//Converts string to int.
					length = atoi(size.c_str());
					system("cls");

					//If the length is 0 it will ask the user to re-enter the length of the symetrical triangle.
					if (length == 0)
					{
						cout << "---> PLEASE ENTER A VALID NUMBER <---" << endl << endl;
					}

				} while (length == 0);

				//Calculating the area of the symetrical triangle.
				area = (length * length);
				cout << endl << endl;

				//Creates a particlar symetrical triangle with a specific length and character.
				for (int a = 1; a <= length; a++)
				{
					for (int b = length - 1; b >= a; b--)
					{
						cout << " ";
					}
					for (int c = 0; c < builder; c++)
					{
						cout << userCharacter;
					}
					cout << "    " << endl;
					builder = builder + 2;
					Sleep(16);
				}

				cout << endl;

				//Displays the area for the user's symetrical triangle.
				cout << "Area of your symetrical triangle is " << area << " characters" << endl << endl;

				//Asks the user either they want to quit or redo the program.
				do
				{
					cout << "Enter [Q] to quit or [R] to retry" << endl;
					cin >> userPreference;

					//If they enter "Q" or "q" it will quit the program. 
					if ((userPreference == "Q") || (userPreference == "q"))
					{
					}

					//If they enter "R" or "r" it will restart the program. 
					else if ((userPreference == "R") || (userPreference == "r"))
					{
						system("cls");
					}

					//If they enter anything else it will re-ask the question to either quit or redo.
					else
					{
						system("cls");
						cout << "---> ENTER A VALID LETTER <---" << endl << endl;
					}

				} while ((userPreference != "R") && (userPreference != "r") && (userPreference != "Q") && (userPreference != "q"));
			}

			//If they choose "f" or "F" they will be asked some questions as followed below.
			else if ((userChoice == "f") || (userChoice == "F"))
			{
				//Checks if the user types in a string instead of an int, if they do it will request then to re-type a number.
				do
				{
					//Asks the user what length they would prefer for thier tree.
					cout << "What length would you prefer for your tree?" << endl << "ENTER A NUMBER" << endl;
					cin >> size;

					//Converts string to int.
					length = atoi(size.c_str());
					width = length / 2;
					system("cls");

					//If the length is 0 it will ask the user to re-enter the length of the tree.
					if (length == 0)
					{
						cout << "---> PLEASE ENTER A VALID NUMBER <---" << endl << endl;
					}

				} while (length == 0);
				
				//Makes the height of the trunk proportional to the tree.
				trunkHeight = length / 2;

				//Will ask the user a character to display it for the formation of the shapes
				cout << "Enter a *SINGLE* character for the trunk of the tree" << endl;
				cin >> userCharacter_2;
				system("cls");

				//Calculating the area of the trunk of the tree.
				trunkSize = (length - (width / 2));

				//Calculating the area of the leaf of the tree.
				leafArea = (length *  length);
				trunkArea = (width * trunkHeight);

				//Calculating the total area of the tree.
				area = leafArea + trunkArea;
				cout << endl << endl;

				//Creates a particlar tree with a specific length and character.
				for (int a = 1; a <= length; a++)
				{
					for (int b = length; b >= a; b--)
					{
						cout << " ";
					}
					for (int c = 0; c < builder; c++)
					{
						cout << userCharacter;
					}
					cout << "    " << endl;
					builder = builder + 2;
					Sleep(16);
				}

				//Creates the trunk of the tree proportional to the length of the tree while using a specific character.
				for (int a = 0; a < trunkHeight; a++)
				{
					//Spacing for the trunk to be proportional to the tree
					for (int c = 0; c < trunkSize; c++)
					{
						cout << " ";
					}
					cout << userCharacter_2;
					for (int b = 1; b < width; b++)
					{
						cout << userCharacter_2;
						Sleep(6);
					}
					cout << endl;
				}

				cout << endl << endl;

				//Displays the area for the user's tree.
				cout << "Area of your tree is " << area << " characters" << endl << endl;

				//Asks the user either they want to quit or redo the program.
				do
				{
					cout << "Enter [Q] to quit or [R] to redo" << endl;
					cin >> userPreference;

					//If they enter "Q" or "q" it will quit the program. 
					if ((userPreference == "Q") || (userPreference == "q"))
					{
					}

					//If they enter "R" or "r" it will restart the program. 
					else if ((userPreference == "R") || (userPreference == "r"))
					{
						system("cls");
					}

					//If they enter anything else it will re-ask the question to either quit or redo.
					else
					{
						system("cls");
						cout << "---> ENTER A VALID LETTER <---" << endl << endl;
					}

				} while ((userPreference != "R") && (userPreference != "r") && (userPreference != "Q") && (userPreference != "q"));
			}

			//If they enter anything else it will re-ask the question of chosing a shape.
			else
			{
				system("cls");
				cout << "---> ENTER A VALID LETTER <---" << endl << endl;
			}

		} while ((userChoice != "A") && (userChoice != "a") && (userChoice != "B") && (userChoice != "b") && (userChoice != "C") && (userChoice != "c") && (userChoice != "D") && (userChoice != "d") && (userChoice != "E") && (userChoice != "e") && (userChoice != "F") && (userChoice != "f"));

		cout << endl;
	} while ((userPreference == "R") || (userPreference == "r"));


	return 0;
}