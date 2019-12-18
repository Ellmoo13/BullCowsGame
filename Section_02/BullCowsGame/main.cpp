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
FText GetValidGuess();
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
	std::cout << "Welcone to Bulls and Cows \n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " Letter isogram I'm thinking of \n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop for the number of turns asking for guesses
	for (int32 count = 1; count <= MaxTries; count++) {     	// TODO change for FOR to WHILE lood one we are validating tries
		FText Guess = GetValidGuess(); 

		// sumbit valid quqess to the game
		FBullCowCount BullCowCount = BCGame.SumbitGuess(Guess);

		std::cout << "Bull = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
}
// loop continually until the user gives a valid guess
FText GetValidGuess() // tak
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		//get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " Enter your guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		Status = BCGame.ChescGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word wihout reapeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letter.\n";
			break;
		default:
			return Guess;

		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);  // keep looping until we get no error
}

bool AskToPlayGame()
{
	std::cout << "Do you want to play again ? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'y');
}

//siabadabada ! ! !