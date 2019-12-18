#include "FBullCowsGames.h"

using int32 = int;

//konstruktor xD
FBullCowGame::FBullCowGame() {
	Reset(); }

int32 FBullCowGame::GetMaxTries() const {
	return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const {
	return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const {
	return MyHiddenWord.length();
}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const 
{
	return false;
}

EGuessStatus FBullCowGame::ChescGuessValidity(FString Guess) const
{
	if (false) // if the guess isnt an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if the guess isnt all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	} 
	else if (Guess.length() != GetHiddenWordLength()) // if the guess length is weong
	{
		return EGuessStatus::Wrong_Length;
	}
	else 
	{
		return EGuessStatus::OK;

	}
}

// recieves a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SumbitGuess(FString Guess)
{
	// incriment the return number
	MyCurrentTry++;

	// setup a return variablel
	FBullCowCount BullCowCount;
	
	// lood through all letters in the guess
	int32 HiddenWordLenght = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLenght; MHWChar++) {
		// copare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLenght; GChar++) {
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) {    //incriment bulls if they are iiin the smae plays
					BullCowCount.Bulls++;  // incriment bulls
				}
				else
				{
					BullCowCount.Cows++; // musi byæ krow¹
				}
			}
		}
	}

	return BullCowCount;
}
