#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all integers, initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame();    //konstruktor :)
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value
	bool ChescGuessValidity(FString);      //TODO  -- || --

	// cunting bulls & cows, and increases try # assuming valid quess
	FBullCowCount SumbitGuess(FString);

	//:> ignoruj to
private:
	// zobacz konstruktor dla inicializacji 
	int MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};