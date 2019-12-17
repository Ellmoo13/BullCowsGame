#include "FBullCowsGames.h"

using int32 = int;

//konstruktor xD
FBullCowGame::FBullCowGame() {
	Reset(); }

int32 FBullCowGame::GetMaxTries() const {
	return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const {
	return MyCurrentTry; }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
		MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const {
	return false;
}

bool FBullCowGame::ChescGuessValidity(FString)
{
	return false;
}

// recieves a VALID guess, incriments turn, and returns count
BullCowCount FBullCowGame::SumbitGuess(FString)
{
	// incriment the return number
	MyCurrentTry++;

	// setup a return variablel
	BullCowCount BullCowCount;
	
	// lood through all letters in the guess


		// copare letters against the hidden word

	return BullCowCount;
}
