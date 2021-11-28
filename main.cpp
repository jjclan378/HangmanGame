#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// The maximum number of times that we will prompt the user
// for new input after they give us invalid input
int MAX_NUM_ITERATIONS = 5;

// The maximum number of wrong guesses that the user can make
// before they lose the game
int MAX_NUM_GUESSES = 8;

// returns a random word that is not the same as last game's word
string generateRandomWord(string wordFromLastGame) {
    srand((unsigned) time(NULL));
    const string LIST_OF_WORDS[10] = {"pit", "bake", "pizza", "launch",
                                      "chicken", "dynamite", "lifestyle",
                                      "experiment", "development",
                                      "intelligence"};
    string newRandomWord;

    do {
        newRandomWord = LIST_OF_WORDS[rand() % 10];
    } while (newRandomWord == wordFromLastGame);

    return newRandomWord;
}

bool doesUserWantToPlayAgain() {
    string userStringInput;

    for (unsigned int i = 0; i < MAX_NUM_ITERATIONS; i++) {
        cout << "Do you want to play again?" << endl;
        cout << "Y or N: ";
        cin >> userStringInput;
        cout << endl;

        if (userStringInput == "Y" || userStringInput == "y") {
            return true;
        }
        else if (userStringInput == "N" || userStringInput == "n") {
            return false;
        }

        cout << userStringInput << " is invalid input" << endl << endl;
    }

    cout << "Alright, we will just assume that ";
    cout << "you don't want to play again..." << endl;
    return false;
}

// This replaces dashes with correctly guessed characters
string updateUserFacingString(string stringToBeUpdated,
                            string answerString,
                            char userGuess) {
    for (unsigned int i = 0; i < answerString.size(); i++) {
        if (answerString[i] == userGuess) {
            stringToBeUpdated[i] = userGuess;
        }
    }
    return stringToBeUpdated;
}

// checks string for dashes. If there are no dashes, the user has won
bool checkIfTheyWon(string stringToCheck) {
    if (stringToCheck.find('-') != string::npos) {
        return false;
    }
    return true;
}

// will return 0 if we receive too much invalid input
// otherwise, it will return the input character
char getUserGuess() {
    char userGuess;
    for (unsigned int i = 0; i < MAX_NUM_ITERATIONS; i++) {
        cout << "enter a single character a-z as a guess:" << endl;
        cin >> userGuess;
        userGuess = char(tolower(userGuess));

        if (!isalpha(userGuess)) {
            cout << userGuess << " is invalid input, try again" << endl;
        }
        else {
            return userGuess;
        }
    }

    cout << "Alright, something appears to have gone wrong";
    cout << ", we will just assume that you lost" << endl;
    return 0;
}

bool playHangmanGame() {
    string userFacingString;
    string answerWord;
    string guessedLetters;
    char userGuess;
    bool hasWon = false;
    int numberOfUsedGuesses = 0;

    answerWord = generateRandomWord(answerWord);

    // makes a string of underscores that is the same length as the answer word
    userFacingString = userFacingString.append(answerWord.size(), '-');

    cout << "The word you are trying to guess has ";
    cout << answerWord.size() << " letters" << endl << endl;

    while (numberOfUsedGuesses < MAX_NUM_GUESSES && !hasWon) {
        userGuess = getUserGuess();

        if(userGuess == 0) { // tells game to exit if there was an error
            numberOfUsedGuesses = MAX_NUM_GUESSES;
        }
        else if (guessedLetters.find(userGuess) != string::npos) { // if repeat guess
            cout << "You have already guessed this letter, try another" << endl;
        }
        else if (answerWord.find(userGuess) != string::npos) { // If guess is correct
            guessedLetters.push_back(userGuess);
            userFacingString = updateUserFacingString(userFacingString,
                                                      answerWord,
                                                      userGuess);

            hasWon = checkIfTheyWon(userFacingString);
            numberOfUsedGuesses++;

            cout << "You guessed correctly!" << endl;
            cout << userFacingString << endl;
        }
        else { // if guess is incorrect
            guessedLetters.push_back(userGuess);
            cout << "you guessed wrong try again" << endl;
            numberOfUsedGuesses++;
        }

        cout << endl << "Guessed Letters: " << guessedLetters << endl;
    }
    return hasWon;
}

int main() {
    cout << "Welcome to Nathan Johnson's Hangman Game!" << endl << endl;

    bool userWantsToPlayAgain = true;
    int score = 0;

    while (userWantsToPlayAgain) {
        if(playHangmanGame()) {
            score++;
        }
        else {
            cout << endl << "You lost, but don't give up yet!" << endl;
        }

        cout << endl << "your current score is: " << score << endl;

        userWantsToPlayAgain = doesUserWantToPlayAgain();
    }

    system("pause");

    return 0;
}

