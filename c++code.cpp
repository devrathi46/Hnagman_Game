#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class HangmanGame {
private:
    int maxTries;
    int remainingTries;
    string secretWord;
    char* guessWord;

public:
    HangmanGame(int maxTries) : maxTries(maxTries), remainingTries(maxTries) {
        srand(time(NULL));
        string animals[] = {"puppy", "turtle", "rabbit", "raccoon", "kitten", "hamster",
                            "sheep", "turkey", "chicken", "horse", "chimpanzee", "kangaroo", "koala",
                            "elephant", "leopard", "hippopotamus", "giraffe", "crocodile", "alligator",
                            "hedgehog"
        };
        int randomIndex = (rand() % 20);
        secretWord = animals[randomIndex];
        guessWord = new char[secretWord.length() + 1];
        replaceDashes();
    }

    ~HangmanGame() {
        delete[] guessWord;
    }

    void displayGameDetails() {
        cout << "\n"
             << "        .-------------------------------------------------------------------------------.\n"
             << "        |      _      _                                                                  |\n"
             << "        |     | |    | |   _ _    _ _      _ _        /\\/\\      _ _    _ __          |\n"
             << "        |     | |----| |  / _  |  |  _ \\    / _` |      /    \\    / _  |  |  _  \\        |\n"
             << "        |     | |----| | | (| |  | | | |  | (| |     / /\\/\\ |  | (_| |  | | | |        |\n"
             << "        |     ||    ||  \\ _ |  || ||   \\_, |     \\/    \\/   \\ _ |  || |_|        |\n"
             << "        |                                    |_/                                       |\n"
             << "        .--------------------------------------------------------------------------------.\n";

        cout << "The purpose of this game is to guess an animal name, secretly chosen by the application\n\n";
        cout << "You have to guess one letter at a time and you can have " << maxTries << " wrong attempts\n\n";
        cout << "Enter a lower-case letter and don't forget to press enter after each guess\n\n";
        cout << "Let's play the game!\n\n";
    }

    void replaceDashes() {
        for (int i = 0; i < secretWord.length(); i++) {
            guessWord[i] = '-';
        }
        guessWord[secretWord.length()] = '\0';
    }

    void displayWord() {
        cout << guessWord << endl;
    }

    int isGuessTrue(char letter) {
        int flag = 0;
        for (int i = 0; i < secretWord.length(); i++) {
            if (secretWord[i] == letter && guessWord[i] != letter) {
                guessWord[i] = letter;
                flag = 1;
            } else if (secretWord[i] == letter && guessWord[i] == letter) {
                flag = 2;
            }
        }
        return flag;
    }

   void displayMan(int remainingGuess) {

    string part[4];
    switch (remainingGuess) {
    case 0:
        part[3] = "|";
    case 1:
        part[2] = "/|\\";
    case 2:
        part[1] = "/|\\";
    case 3:
        part[0] = "( )";
        break;
    }

    cout << "--------------\n";
    cout << "  |       " << part[3] << endl;
    cout << "  |       " << part[3] << endl;
    cout << "  |      " << part[0] << endl;
    cout << "  |      " << part[1] << endl;
    cout << "  |      " << part[2] << endl;
    cout << "  |\n";
    cout << "  |\n";
    cout << "--------------\n";
}

    bool isGameOver() {
        return secretWord == guessWord || remainingTries == 0;
    }

    void playGame() {
        displayGameDetails();

        cout << "Your guess word is:";
        displayWord();

        while (!isGameOver()) {
            char guessLetter;
            cout << "Enter your guess letter:" << endl;
            cin >> guessLetter;

            int guess = isGuessTrue(guessLetter);

            if (guess == 0) {
                remainingTries--;
                cout << "\nWhoops! That letter is not present in the word" << endl;
                displayMan(remainingTries);
            } else if (guess == 1) {
                cout << "\nYay! You have found the letter" << endl;
            } else {
                cout << "\nYou have already guessed this letter. Try something else!" << endl;
            }

            cout << "You can have " << remainingTries << " more wrong attempts" << endl;
            cout << "Your guess word is:";
            displayWord();
            cout << endl;
        }

        if (secretWord != guessWord) {
            cout << "\nToo many guesses! You have been hanged." << endl;
            cout << "\nThe secret word was: " << secretWord << endl;
        } else {
            cout << "\nCongratulations! You won." << endl;
        }
    }
};

int main() {
    int maxTries = 5;
    HangmanGame game(maxTries);
    game.playGame();
    return 0;
}