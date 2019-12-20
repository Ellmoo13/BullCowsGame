#pragma once
#include "FBullCowsGames.h"
#include <map>
#define TMap std::map  //to make syntax Unreal friendly

using int32 = int;

//konstruktor xD
FBullCowGame::FBullCowGame() {
	Reset(); } // default konstruktor


int32 FBullCowGame::GetCurrentTry() const {
	return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const {
	return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const {
	return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ {3,5}, {4,7}, {5,10}, {6,16}, {7,20}, {8,20}, {9,20}, {10,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()]; 
}


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "pietruszka";  //  this MUST be an isogram
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}



EGuessStatus FBullCowGame::ChescGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // if the guess isnt an isogram
	{
		return EGuessStatus::Not_Isogram; 
	}
	else if (!IsLowercase(Guess)) // if the guess isnt all lowercase 
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

bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;   //setup map
	for (auto Letter : Word)		// for all letters of the word
	{
		Letter = tolower(Letter);	// handle mixed case
		if (LetterSeen[Letter]) { // if the letter is in the map 
			return false;	// we do NOT have an isogram
		} else {
			LetterSeen[Letter] = true; 	// ass the letter to the map as seen

		}
	}
	return true; // for example in cases whee /0 is intered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word) {
		
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}
