// GAME1007_Ex_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Operators today...
// = assignment
// == equality
// % modulo
// -
// +
// >>
// <<
// Flow control statements
// if(condition)...else
// while(condition)
// do...while(condition)
// for(;;)...
// switch(
// goto


#include <iostream>

using namespace std; // Do NOT do this in large professional projects. 
//It can cause issues with namespace collisions, but for our student work it is fine

int main()
{
	string nameOfPlayer1 = "p1";
	string nameOfPlayer2 = "p2";
	int correctAnswer;
	int whoseTurnItIs;
	int playerGuess;

	//Get player names
	cout << "Hello! Welcome to the number guessing game\n";
	cout << "Player 1, what is your name?" << endl;
	cin >> nameOfPlayer1;
	cout << "Welcome, " << nameOfPlayer1 << endl;
	cout << "Player 2, what is your name?" << endl;
	cin >> nameOfPlayer2;
	cout << "Welcome, " << nameOfPlayer2 << endl;

	//Algorithm for pseudorandom number, from a seed
	// Take the seed, then multiply it by 6 and divide it by 7, and add 2
	// Every time asked again for a number, feed the last answer back as the new seed
	// 5
	// 6
	// 7

	srand(time(NULL));

	char choiceToRestart;
	do
	{
		//Generate a Number from 1 to 100 inclusive, call it "CorrectAnswer"
		correctAnswer = ((rand() % 100) + 1); // assign correctAnswer the value of a pseudorandom number, modulo 100, plus 1
		// A / B (a divided by b) tells you how many times B fits into A
		// A % B (a modulo b) tells you what the remainder is after doing A / B

		cout << correctAnswer << endl; // erase me later! For debugging purposes it's useful for us to be able to cheat....

		cout << "I'm thinking of a number from 1 to 100" << endl;

		//Generate a Number from 1 to 2, call it "WhoseTurnItIs"
		whoseTurnItIs = (rand() % 2) + 1;

		//while (playerGuess != correctAnswer) // while(condition) says check if condition is true. If yes, then do what's inside, then go back to the top, and check again.
		do //do...while(condition) says do the things first, then check the condition to determine if it should return to the top. Only difference from while is it always does what is inside first.
		{
			if (whoseTurnItIs == 1) // this is the equals operator. It will tell you if the left is equal to the right, returning true or false
			{
				cout << nameOfPlayer1;
			}
			else
			{
				cout << nameOfPlayer2;
			}
			cout << ", guess a number!" << endl;

			cin >> playerGuess;

			if (playerGuess < correctAnswer)
			{
				cout << "You guessed too low!\n";
			}
			else if (playerGuess > correctAnswer)
			{
				cout << "You guessed too high!\n";
			}

			//WhoseTurnItIs is now(1 - (WhoseTurnItIs - 1)) + 1
			whoseTurnItIs = (1 - (whoseTurnItIs - 1)) + 1; // swap turns between 1 and 2
			//loop back to the start...?
		} while (playerGuess != correctAnswer);
		cout << "Winner!" << endl;
		//If we get here, then playerGuess == correctAnswer
		cout << "Thank you for playing!\n";

		cout << "Would you like to play again? Y/N\n";

		cin >> choiceToRestart;

	} while (choiceToRestart == 'Y');


	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
