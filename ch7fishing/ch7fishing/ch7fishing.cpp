// ch7fishing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
unsigned seed;
int dice;
class RandomNumberGenerator // class definition
{ // class body
public: // access specifier
	//constructor
	RandomNumberGenerator()
	{
		seed = time(0);
		srand(seed);
		int seedValue = seed;
	}
	
	//member function
	int rollDice()
	{
		int dice = rand() % 6;
		return dice;
	}
};

int main()
{
    cout << "Chapter 7 Fishing Game by Kevin Bell\n\n";
	cout << "Let's play a fishing game and see what you catch!\n\n";
	RandomNumberGenerator random_number;
	string continueProgram, dayType;
	int fish, points=0;
	unsigned seed;
	seed = time(0);
	srand(seed); //seed the random number generator
	cout << "Enter f to start fishing: ";
	cin >> continueProgram;
	while (continueProgram == "f" || continueProgram == "F") {
		dice = random_number.rollDice();
		switch (dice) {
		case 0:
			cout << "You caught an old shoe, no points\n\n";
			break;
		case 1:
			cout << "You caught a small fish! 2 points\n\n";
			points += 2;
			break;
		case 2:
			cout << "You caught a medium fish! 4 points\n\n";
			points += 4;
			break;
		case 3:
			cout << "You caught a big fish! 6 points!\n\n";
			points += 6;
			break;
		case 4:
			cout << "The fish took the bait and ran away! Lose 2 points\n\n";
			points -= 2;
			break;
		case 5:
			cout << "Your line got tangled and broke. Lose 1 point\n\n";
			points -= 1;
			break;
		} // end switch
		cout << "Enter f to continue fishing, or press any other key to quit: ";
		cin >> continueProgram;
	} // end while	
	if (points < 0) {
		dayType = "bad";
	}
	else if (points >= 0 && points < 8) { 
		dayType = "day that was not the worst, but it was also not the best";
	}
	else if (points >= 8 && points < 20) {
		dayType = "fair";
	}
	else if (points >= 20) {
		dayType = "great";
	}
	cout << "You had a " << dayType << " day, you earned " << points << " points\n";
	system("pause");
	return 0;
} // end main
