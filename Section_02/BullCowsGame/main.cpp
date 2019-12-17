#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();

// the enetry point of our application
int main()
{
	PrintIntro();

	PlayGame();

	//ODPOCZYNEK z pizz¹ 
	//to ni¿ej nie jestem pewien
	cout << endl;
	return 0;   //exit the application
}



//introduse the game 
void PrintIntro() 
{
	constexpr int WORLD_LENGTH = 9;
	cout << "Welcone to Bulls and Cows";
	cout << "Can you guess the " << WORLD_LENGTH;
	cout << " Letter isogram I'm thinking of \n";
	cout << endl;
	return;
}

void PlayGame()
{
	//loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {
		string Guess = GetGuess();
		cout << "You quess wa: " << Guess << endl;
		cout << endl;
	}
}

string GetGuess() 
{
	//get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}