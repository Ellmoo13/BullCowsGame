#include <iostream>
#include <string>

using namespace std;

void PrintIntro();

// the enetry point of our application
int main()
{
	PrintIntro();

	//get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	//repeat the guess back to them
	cout << "You quess wa: " << Guess << endl;

	//get a guess from the player
	cout << "Enter your guess: ";
	getline(cin, Guess);

	//repeat the guess back to them
	cout << "You quess wa: " << Guess << endl;

	//ODPOCZYNEK z pizz¹ 

	return 0;
}

void PrintIntro() {
	//introduse the game 
	constexpr int WORLD_LENGTH = 9;

	cout << "Welcone to Bulls and Cows";
	cout << "Can you guess the " << WORLD_LENGTH;
	cout << " Letter isogram I'm thinking of \n";
	cout << endl;
	return;
}