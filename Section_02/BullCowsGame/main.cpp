#include <iostream>
#include <string>

using namespace std;

int main()
{
	//introduse the game 
	constexpr int WORLD_LENGTH = 9;

	cout << "Welcone to Bulls and Cows";
	cout << "Can you guess the " << WORLD_LENGTH;
	cout << " Letter isogram I'm thinking of \n";
	cout << endl;

	//get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	cin >> Guess;
	
	//repeat the guess back to them
	cout << "You quess wa: " << Guess << endl;

	//ODPOCZYNEK z pizz¹ 

	return 0;
}
