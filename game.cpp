
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int number, guess, attempts;
    char playAgain;

    srand(time(0)); // seed for random number

    do {
        number = rand() % 100 + 1; // random number between 1 and 100
        attempts = 0;

        cout << "\n🎯 Welcome to the Number Guessing Game!" << endl;
        cout << "Guess a number between 1 and 100." << endl;

        do {
            cout << "Enter your guess: ";
            cin >> guess;

            // Input validation
            if (cin.fail()) {
                cin.clear(); // clear error flag
                cin.ignore(10000, '\n'); // discard input
                cout << "⚠️ Please enter a valid number!\n";
                continue;
            }

            attempts++;

            if (guess > number)
                cout << "📉 Too high! Try again.\n";
            else if (guess < number)
                cout << "📈 Too low! Try again.\n";
            else
                cout << "🎉 Correct! You guessed it in " << attempts << " tries.\n";

        } while (guess != number);

        cout << "🔁 Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "👋 Thanks for playing! Goodbye!\n";
    return 0;
}
