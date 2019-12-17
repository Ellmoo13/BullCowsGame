/* THis is the coonsole executable, that makes use of the BullCow class
This acts as the view in a MVC patters, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowsGames.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayGame();

FBullCowGame BCGame;   //instantiate new gejm

// the enetry point of our application
int main()
{

	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		// TODO add a game summary
		bPlayAgain = AskToPlayGame();
	} 
	while (bPlayAgain);


	//ODPOCZYNEK z pizz¹ 
	std::cout << std::endl;
	return 0;   //exit the application
}



//introduse the game 
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcone to Bulls and Cows \n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " Letter isogram I'm thinking of \n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop for the number of turns asking for guesses
	// TODO change for FOR to WHILE lood one we are validating tries
	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetGuess(); // TODO make loop checing validation

		// sumbit valid quqess to the game
		// print number of bulls and cows

		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

FText GetGuess() 
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	//get a guess from the player
	std::cout << "Try " << CurrentTry << " Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayGame()
{
	std::cout << "Do you want to play again ? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'y');
}

