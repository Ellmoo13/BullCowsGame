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
	return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const {
	return bGameIsWon; }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}



EGuessStatus FBullCowGame::ChescGuessValidity(FString Guess) const
{
	if (false) // if the guess isnt an isogram
	{
		return EGuessStatus::Not_Isogram; // TODO write function 
	}
	else if (false) // if the guess isnt all lowercase 
	{
		return EGuessStatus::Not_Lowercase;  // TODO write function 
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
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLenght = MyHiddenWord.length(); // assuming same length as guess

	// lood through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLenght; MHWChar++) {
		// copare letters against the guess
		for (int32 GChar = 0; GChar < WordLenght; GChar++) {
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
	if (BullCowCount.Bulls == WordLenght) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}
