#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame();    //konstruktor :)
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value
	bool ChescGuessValidity(FString);      //TODO  -- || --
	// provide a method for cunting bulls & cows, and increasing turn#


	//:> ignoruj to
private:
	// zobacz konstruktor dla inicializacji 
	int MyCurrentTry;
	int32 MyMaxTries;

};