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
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	bool ChescGuessValidity(FString) const;      //TODO make a more rich return value

	void Reset(); //TODO make a more rich return value
	FBullCowCount SumbitGuess(FString);
	

	//:> ignoruj to
private:
	// zobacz konstruktor dla inicializacji 
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};