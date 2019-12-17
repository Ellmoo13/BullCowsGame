#pragma once
#include <string>

class FBullCowGame {
public:
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //todo make a more rich return value
	bool ChescGuessValidity(std::string);      // -- || --


	//:> ignoruj to
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;

};