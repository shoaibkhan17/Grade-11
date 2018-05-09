//Author		: Shoaib Khan
//Description	: WAR - (Card game) player vs opponent (♠) (♥) (♦) (♣)
//Date Creater	: 07/06/15
//Date Modified	: 14/06/15

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <Windows.h>
#include <math.h>

using namespace std;

//Prototypes
void assignDeck();
void displayDeck();
void shuffling();
void clearHand();
void replaceHand();
void checkWinner();

struct card
{
	int value;
	string rank;
	char suit;
};

//Declaring Variables
string ranks[13] = { "Ace","2","3","4","5","6","7","8","9","10","Jack","Qween","King" };
string userAnswer;
char suits[4] = { 3,4,5,6 }; 
int values[13] = { 14,2,3,4,5,6,7,8,9,10,11,12,13 };
int player, opponent, playerCounter, opponentCounter, roundNum;
bool winner, playAgain, notListed;
card deck[4][13], playerHand[52], opponentHand[52], playerSecondHand[52], opponentSecondHand[52];
 
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void setColour(int colourNum)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colourNum);		//Changes the colour
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void displayCardArray(card myArray[52])
{
	for (int i = 0; i < 52; i++)
	{
		if (myArray[i].value == 0)		//If the value in the array is equal to zero, break the loop
		{
			break;
		}

		cout << myArray[i].rank << " OF " << myArray[i].suit << endl;		//Display the rank and suit of the card
	}

	return;		//Close the funtion.
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void assignDeck()
{
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 13; b++)
		{
			deck[a][b].rank = ranks[b];		//Assign rank to the deck cards
			deck[a][b].suit = suits[a];		//Assign suit to the deck cards	
			deck[a][b].value = values[b];	//Assign value to the deck cards
		}
	}
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void displayDeck()
{
	setColour(10);		//Changes colour.
	cout << "---> Your Deck <---" << endl;
	setColour(11);		//Changes colour.

	int A = 0;
	int B = 0;
	for (int a = 0; a < 2; a++)
	{
		for (int b = 0; b < 13; b++)
		{
			cout << deck[a][b].rank << " OF " << deck[a][b].suit << endl;		//Displays player's deck
			playerHand[A] = deck[a][b];		//Assigns the specific card to the player 
			A++;
		}
	}

	setColour(10);
	cout << endl << "---> Opponent's Deck <---" << endl;
	setColour(11);

	for (int a = 2; a < 4; a++)
	{
		for (int b = 0; b < 13; b++)
		{
			cout << deck[a][b].rank << " OF " << deck[a][b].suit << endl;		//Displays opponent's deck.
			opponentHand[B] = deck[a][b];		//Assigns the specific card to the opponent
			B++;
		}
	}

	cout << endl;
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void clearHand()
{
	for (int i = 0; i < 52; i++)
	{
		//Clears the player's hand cards.
		playerHand[i].rank = "";		
		playerHand[i].suit = 0;
		playerHand[i].value = 0;

		//Clears the opponnets's hand cards.
		opponentHand[i].rank = "";
		opponentHand[i].suit = 0;
		opponentHand[i].value = 0;
	}
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void clearSecondHand()
{
	for (int i = 0; i < 52; i++)
	{
		//Clears the player's second hand cards.
		playerSecondHand[i].rank = "";
		playerSecondHand[i].suit = 0;
		playerSecondHand[i].value = 0;

		//Clears the opponents's second hand cards.
		opponentSecondHand[i].rank = "";
		opponentSecondHand[i].suit = 0;
		opponentSecondHand[i].value = 0;
	}
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void replaceHand()
{
	for (int i = 0; i < 52; i++)
	{
		if (playerSecondHand[i].value != 0)
		{
			playerHand[i] = playerSecondHand[i];		//Assigns the cards from player second hand to player hand.
		}

		if (opponentSecondHand[i].value != 0)
		{
			opponentHand[i] = opponentSecondHand[i];		//Assigns the cards from opponent second hand to opponent hand.
		}

	}
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void shuffling()
{
	//Declaring variables
	int random1, random2, random3, random4;
	card temp;

	for (int a = 0; a < 1000; a++)
	{
		//Genetrates 4 random numbers.
		random1 = rand() % 4;
		random2 = rand() % 13;
		random3 = rand() % 4;
		random4 = rand() % 13;

		//Replaces the two cards in the deck.
		temp = deck[random1][random2];
		deck[random1][random2] = deck[random3][random4];
		deck[random3][random4] = temp;
	}
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void shuffleHand()
{
	//Declaring variables
	int randomPlayerHand, randomPlayerHand1, randomOpponentHand, randomOpponentHand1;
	card shufflePlayer;
	card shuffleOpponent;

	for (int i = 0; i < 1000; i++)
	{
		//Generates 2 random numbers.
		randomPlayerHand = rand() % player;
		randomPlayerHand1 = rand() % player;

		//Replaces the two cards in the deck.
		shufflePlayer = playerHand[randomPlayerHand];
		playerHand[randomPlayerHand] = playerHand[randomPlayerHand1];
		playerHand[randomPlayerHand1] = shufflePlayer;

		//Generates 2 random numbers.
		randomOpponentHand = rand() % opponent;
		randomOpponentHand1 = rand() % opponent;

		//Replaces the two cards in the deck.
		shuffleOpponent = opponentHand[randomOpponentHand];
		opponentHand[randomOpponentHand] = opponentHand[randomOpponentHand1];
		opponentHand[randomOpponentHand1] = shuffleOpponent;
	}
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void shuffleHandInGame(card shuffleArray[52],int user)
{
	int randomNum1, randomNum2,traker[1000];
	card shuffler;

	for (int i = 0; i < 1000; i++)
	{
		//Generates two random numbers.
		randomNum1 = rand() % user;
		randomNum2 = rand() % user;

		if ((shuffleArray[randomNum1].value != 0) && (shuffleArray[randomNum2].value != 0))
		{
			//Replaces the two cards in the deck.
			shuffler = shuffleArray[randomNum1];
			shuffleArray[randomNum1] = shuffleArray[randomNum2];
			shuffleArray[randomNum2] = shuffler;
		}
	}
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void game()
{
	winner = false;
	playerCounter = 26;
	opponentCounter = 26;

	do
	{
		player = 0;
		opponent = 0;
		
		setColour(13);	//Changes the colour 
		cout << endl << "Round " << roundNum << endl;		//Displays the round number.
		setColour(11);	//Changes the colour

		for (int i = 0; i < 52; i++)
		{
			if ((playerHand[i].value != 0) && (opponentHand[i].value != 0))
			{
				setColour(15);		//Changes the colour
				cout << "You played " << playerHand[i].rank << " OF " << playerHand[i].suit << endl;		//Displays the cards the player plays
				cout << "Opponent played " << opponentHand[i].rank << " OF " << opponentHand[i].suit << endl;		//Displays the cards the opponent plays.
				setColour(10);		//Changes the colour 

				if (playerHand[i].value > opponentHand[i].value)		//If the player's card is greater than the opponent's card
				{
					cout << "---> You win <---" << endl;		//Displays "you win"
					playerSecondHand[player] = playerHand[i];		//Stores that card in the second hand
					player++;		//Increases player cards won by one
					opponentCounter--;		//Decreases the opponnet counter by 1
				}

				else if (playerHand[i].value < opponentHand[i].value)		//If the opponent's card is greater than the player's card
				{
					cout << "---> Opponent wins <---" << endl;		//Displays "opponent wins"
					opponentSecondHand[opponent] = opponentHand[i];		//Stores that card in the second hand
					opponent++;		//Increases opponent cards won by one
					playerCounter--;		//Decreases the player counter by 1
				}

				else if (playerHand[i].value == opponentHand[i].value)		//If the player's card is equal to the opponents's card
				{
					cout << "---> WAR <---" << endl;		//Displays "WAR"
					playerCounter--;		//Reduces the player counter by one
					opponentCounter--;		//Reduces the opponent counter by one 
				}

				cout << endl;
			}

			else if ((playerHand[i].value != 0) && (opponentHand[i].value == 0))		//If the player runs our of card
			{
				if (opponentCounter == 0)		// If the opponent counter is equal to zero
				{
					setColour(13);		//Changes colour
					cout << "---> You Win <---" << endl << endl;		//Displays "You win"
					setColour(10);		//Changes colour 
					cout << "Your card(s): " << playerCounter << endl;		//Displays the amount of player's cards remaining
					cout << "Opponnet's card(s): " << opponentCounter << endl;		//Displays the amount of opponent's cards remaining
					setColour(11);		//Changes the colour
					return;		//Closes the function
				}

				int a = i;

				for (int counterA = player; counterA < playerCounter; counterA++)
				{
					playerSecondHand[counterA] = playerHand[a];		//Stores all the remaing player's cards into player'ss second hand
					a++;
					
					if (playerHand[a].value == 0)		//If value of the player hand is equal to zero
					{
						break;		//Break the loop
					}
				}

				if (opponentCounter >= 2)		//If the opponent counter is greater or equal to 2
				{
					shuffleHandInGame(opponentSecondHand, opponent);		//Shuffle opponents hand cards
				}
				break;		//Break he loop
			}

			else if ((playerHand[i].value == 0) && (opponentHand[i].value != 0))		//If the player runs out of cards 
			{
				if (playerCounter == 0)		//If the player counter is equal to zero
				{
					setColour(13);		//Changes the colour
					cout << "---> You Lose <---" << endl << endl;		//Displays "You lose" 
					setColour(10);		//Changes the colour
					cout << "Your card(s): " << playerCounter << endl;		//Displays the amount of player's cards remaining
					cout << "Opponnet's card(s): " << opponentCounter << endl;		//Displays the amount of opponents's cards remaining
					setColour(11);		//Changes the colour
					return;		//Closes the function
				}

				else
				{
					int a = i;

					for (int counterA = opponent; counterA < opponentCounter; counterA++)
					{
						opponentSecondHand[counterA] = opponentHand[a];		//Stores all the remaing opponent's cards into opponent's second hand
						a++;

						if (opponentHand[a].value == 0)		//If value of the opponent hand is equal to zero
						{
							break;		//Break the loop
						}
					}

					if (playerCounter >= 2)		//If the player counter is greater or equal to 2
					{
						shuffleHandInGame(playerSecondHand, player);		//Shuffle player hand cards
					}
					break;		//Breaks the loop
				}
			}
		}

		cout << "Your card(s): " << playerCounter << endl;		//Displays the amount of player's cards remaining
		cout << "Opponnet's card(s): " << opponentCounter<< endl;		//Displays the amount of opponents's cards remaining

		checkWinner();		//Calls the funtion "checkWinner"

		if (winner == false)		//if bool winner is false 
		{
			setColour(11);		//Changes colour
			cout << "---> Your Hand <---" << endl;		
			displayCardArray(playerHand);			//Displays player's hand cards

			cout << endl << "---> Opponnet Hand <---" << endl;
			displayCardArray(opponentHand);			//Displays opponents's hand cards
			setColour(15);		//Changes colour

			system("pause");		//pauses the system and asks user to enter any key to continue
		}

		roundNum ++;		//Increases the round number by one after completing each round.
	} while (winner == false);
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void checkWinner()
{
	if ((opponentCounter == 0) && (playerCounter == 0))		//If opponent and player counter is equal to zero
	{
		cout << "---> Draw <---" << endl;		//Displays "draw" match
		winner = true;			
	}

	else if (opponentCounter == 0)		//If opponent counter is equal to zero.
	{
		cout << "---> You win <---" << endl;		//Displays "You win"
		winner = true;
	}

	else if (playerCounter == 0)		//If opponent counter is equal to zero.
	{
		cout << "---> You lose <---" << endl;		//Displays "You lose"
		winner = true;
	}

	else if (roundNum == 1)			//If round is equal to one.
	{
		setColour(13);		//Chnages colour
		cout << endl << "---> NO WINNER <---" << endl;		//Displays "No winner"
		cout << "---> PLAY AGAIN <--" << endl << endl;		//Diplays "Play again"
		setColour(15);		//Change colour

		//Calls other functions
		clearHand();
		replaceHand();
		shuffleHand();
		clearSecondHand();
	}

	else
	{
		setColour(13);		//Changes colour
		cout << endl << "---> NO WINNER <---" << endl;		//Displays "No winner"
		cout << "---> PLAY AGAIN <--" << endl << endl;		//Displays "Play again"
		setColour(15);		//Changes colour

		//Calls other funtions
		clearHand();
		replaceHand();
		clearSecondHand();
	}
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
int main()
{

	//cout << "♠" << endl;
	//system("PAUSE");
	do
	{
		roundNum = 1;
		playAgain = false;
		setColour(9);		//Changes colour 
		cout << "---> Welcome to WAR <---" << endl << endl;
		setColour(11);		//Changes colour

		srand(time(NULL));		//Random number is not related to time.
		rand();		//Generates a random number.

		//Call the functions
		assignDeck();
		shuffling();
		displayDeck();
		game();

		cout << endl;		//New line
		do
		{
			notListed = false;

			cout << "Do you want to play again? [Y]-yes or [N]-no" << endl;		//Asks if the user wants to play again.
			cin >> userAnswer;

			if ((userAnswer == "Y") || (userAnswer == "y"))		//If yes - restart
			{
				system("CLS");
				playAgain = true;
			}

			else if ((userAnswer == "N") || (userAnswer == "n"))		//If no - quit
			{
			}

			else
			{
				notListed = true;
				system("CLS");		//Clears the screen
			}
		} while (notListed == true);
	} while (playAgain == true);

		system("PAUSE");
		return 0;
}