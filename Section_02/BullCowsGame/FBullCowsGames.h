/*The Game logic (no view code or direcr user interaction)
The game is a simple guess the word game based on Mastermind
*/


#pragma once
#include <string>

 // to ake syntax Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


enum class EGuessStatus 
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};


class FBullCowGame {
public:
	FBullCowGame();    //konstruktor :)

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus ChescGuessValidity(FString) const; 

	void Reset(); 
	FBullCowCount SubmitValidGuess(FString);
	

	//:> ignoruj to
private:
	// zobacz konstruktor dla inicializacji 
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};