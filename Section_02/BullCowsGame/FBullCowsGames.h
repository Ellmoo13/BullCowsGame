#pragma once

class FBullCowGame {
public:
	void Reset(); //todo make a more rich return value
	int GetMaxTries();
	int GetCurrentTry;
	bool IsGameWon();
	bool ChescGuessValidity(string); // -- || --


	//:> ignoruj to

private:
	int MyCurrentTry;
	int MyMaxTries;

};