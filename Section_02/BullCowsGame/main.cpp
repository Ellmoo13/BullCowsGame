/* THis is the coonsole executable, that makes use of the BullCow class
This acts as the view in a MVC patters, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowsGames.h"

// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// function prototypes as outside a class
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayGame();
void PrintGameSummary();

FBullCowGame BCGame;   //instantiate new gejm, which we re-use across plays

// the enetry point of our application
int main()
{

	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayGame();
	} 
	while (bPlayAgain);

	//ODPOCZYNEK z pizz¹ 
	std::cout << std::endl;
	return 0;   //exit the application
}

void PrintIntro() 
{
	std::cout << "Welcone to Bulls and Cows.\n ";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " Letter isogram I'm thinking of ?\n";
	std::cout << std::endl;
	return;
}

// pleys a single game to completion
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop asking for guesses while the game is NOT won
	// is NOT won and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {    
		FText Guess = GetValidGuess(); 

		// sumbit valid quqess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bull = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();
	return;
}
// loop continually until the user gives a valid guess
FText GetValidGuess() // tak
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		//get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << " Enter your guess: ";
		std::getline(std::cin, Guess);

		//chect status and give feedback
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
			// assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK);  // keep looping until we get no error
	return Guess;
}

bool AskToPlayGame()
{
	std::cout << "Do you want to play again with the same word (y/n) ? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'y');
}

void PrintGameSummary() {
	if (BCGame.IsGameWon())
	{
		std::cout << "Well Done - You Win! \n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
}

//siabadabada ! ! !