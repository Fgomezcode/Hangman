#pragma once
#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Word.h"
#include <cstring>
#include <ctime>
using namespace std;



//--------------------------------------PROTOTYPES
int randomNumber(int length);

bool checkList(vector<char> correctLetter, char temp);

vector<Word> createList();

void showHangman(int incorrect, bool gameOver);

void display(vector<Word> word, int index);


/*
this function will check the usedLetters vector and compare it to the user input
if the values are a match it will set a flag and return true, if the values do not match it will return false.
*/
bool checkList(vector<char> usedLetters, char temp) {
    // linear search used because the vector is not sorted.
    bool result = false;

    for (int i = 0; i < usedLetters.size(); i++) {
        if (usedLetters[i] == temp) {
            // once there is a match the result is true and it will return/ break the search
            result = true;
            return result;
        }
        else {
            //set result to false if there is no match
            //does not return as it needs to proceed to check the remainder of the list
            result = false;
        }
    }

    //once the list has been checked, if there were no matches the result is returned.
    return result;
}


/*
this function will return a random number based on the length of the list,
*/
int randomNumber(int length) {
    int number = 0;

    srand(time(NULL));

    number = (rand() % length) + 1;
    cout << number << endl << endl << endl;

    return number;
}



/*
This function will create a vector of wordToGuess objects.
It reads from two texts files, Words.txt, and Hints.txt.
Words.txt has the words that the player will guess
hints.txt contains hints for the player.

They must be of equal length, and be in sequential order.
*/

vector<Word> createList() {
    ifstream words;
    ifstream hints;

    string tempWord;
    string tempHint;

    vector<Word> wordVector;
    wordVector.clear();

    words.open("Words.txt");
    hints.open("Hints.txt");


    while (getline(words, tempWord) && getline(hints, tempHint)) {

        Word hangmanWord;

        hangmanWord.word = tempWord;

        hangmanWord.hint = tempHint;

        wordVector.push_back(hangmanWord);
    }

    words.close();
    hints.close();

    return wordVector;
}

void showHangman(int incorrect, bool gameOver) {

    const int ROWS = 8;
    const int COLS = 10;
    char person[ROWS][COLS] = {
          {' ','#','#','#','#','#','#','#'},
          {' ','#','#',' ',' ',' ',' ',' '},
          {' ','#','#',' ',' ',' ',' ',' '},
          {' ','#','#',' ',' ',' ',' ',' '},
          {' ','#','#',' ',' ',' ',' ',' '},
          {' ','#','#',' ',' ',' ',' ',' '},
          {'#','#','#','#','#','#','#','#'}
    };

    switch (incorrect)
    {
    case 1:
        person[1][6] = '@';
        break;
    case 2:
        person[1][6] = '@';
        person[2][6] = '|';
        break;
    case 3:
        person[1][6] = '@';
        person[2][6] = '|';
        person[2][5] = '/';
        break;
    case 4:
        person[1][6] = '@';
        person[2][6] = '|';
        person[2][5] = '/';
        person[2][7] = '\\';
        break;
    case 5:
        person[1][6] = '@';
        person[2][6] = '|';
        person[2][5] = '/';
        person[2][7] = '\\';
        person[3][5] = '/';
        break;
    case 6:
        person[1][6] = '@';
        person[2][6] = '|';
        person[2][5] = '/';
        person[2][7] = '\\';
        person[3][5] = '/';
        person[3][7] = '\\';
        break;
    default:
        break;
    }

    for (int i = 0; i < ROWS; i++) {
        cout << '\t';
        for (int j = 0; j < COLS; j++) {
            cout << person[i][j];
        }
        cout << endl;
    }

}

void display(vector<Word> word, int index) {

    // assign hint value from object to local string
    string hint = word[index].hint;

    // assign word value from object to local string
    string guessWord = word[index].word;

    // vector to hold user input - will be used to prevent user from repeatedly entering the same letter to score
    vector<char> usedLetters;

    //value used for loop control
    int wordSize = guessWord.length();

    //char array to display temporary values
    char hiddenWord[20] = { '*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*','*', '*', '*', '*', '*', '*', '*', '*', '*' };

    //charr array will be assigned the value of guessword, used to compare user input
    char displayWord[20] = {};

    //used to meet win-lose conditions. 
    int incorrect = 0, correct = 0;

    //store user  input
    char userInput = ' ';


    //boolean values, used for game control, and conditional flags.
    bool gameOver = false, correctGuess = false, isOnList = false, hasSpace = false, isValid = false;


    system("Cls");

    usedLetters.clear();

    strcpy_s(displayWord, guessWord.c_str());


    usedLetters.push_back(' ');


    while (gameOver == false) {

        correctGuess = false;


        //display the hang man
        showHangman(incorrect, gameOver);
        cout << endl << endl;

        // display the starred characters, and proper spaces for letters.
        for (int i = 0; i < wordSize; i++) {
            //check if there is a space in the word
            if (displayWord[i] == ' ') {
                hiddenWord[i] = ' ';
                hasSpace = true;
            }
            cout << hiddenWord[i] << ' ';
        }

        //prompt the user if the letter has already been used.
        if (isOnList == true) {
            cout << "\n\n** You have already guess that letter, please enter a new guess.**\n";
        }

        cout << "\n\nenter a letter to guess:\t\n" << "or enter '1' for a hint : \t";

        cin >> userInput;



        //validate the user input
        if (!isalnum(userInput)) {

            cin.ignore();
            cout << "\n\nPlease enter letters A-Z, a-z , or 1 for a hint:\t";
            cin >> userInput;
            system("cls");
        }

        if (gameOver == false)
            system("CLS");

        // check if user input was previously used. 
        isOnList = checkList(usedLetters, userInput);


        // add the user input to the vector that will keep track of 
        //letters previously input by the user, unless they were asking for a hint.
        if (userInput != '1') {
            usedLetters.push_back(userInput);
        }

        //check to see if the user input matches a letter in the guess.
        for (int j = 0; j < wordSize; j++)
        {
            if (userInput == displayWord[j]) {
                hiddenWord[j] = userInput;
                correctGuess = true;

                //if user input is correct, and it has not already been used (scored) 
                // add 1 to correct value
                if (correctGuess == true && isOnList == false) {
                    correct++;
                }
            }
        }

        if (!usedLetters.empty()) {
            //display the letters previously entered.
            cout << "Previuously used letters:\t";
            for (vector<char>::iterator it = usedLetters.begin() + 1; it != usedLetters.end(); it++) {
                cout << *it << ", ";
            }
            cout << endl << endl;
        }


        //==================== CHECK AND SET FLAGS / CONDITIONALS

        if (userInput == '1') {
            cout << "\nHint:\t" << hint << endl;
            correctGuess = true;
        }

        //if the user is wrong and the user did not already try the same letter, only mark them wrong once
        if (correctGuess != true && isOnList == false) {
            incorrect++;
        }

        // if the user has guess correctly enough times to match the length of the word they have won.
        if (correct == wordSize || (correct == wordSize - 1 && hasSpace == true)) {
            gameOver = true;
            system("cls");
            showHangman(incorrect, gameOver);

            cout << '\t' << guessWord << '\n' << "\n\tYOU WIN!\n\n";
        }

        else if (incorrect > 6) {

            //display the hang man
            gameOver = true;
            system("cls");
            showHangman(incorrect, gameOver);

            cout << '\t' << guessWord;
            cout << "\n\tYOU ARE A LOSER!\n\n\n\a";
        }

      // Used to check if score was properly tracked, uncomment to see score 
      //  cout << "\tcorrect:\t" << correct << endl << "\tincorrect:\t" << incorrect << endl;

    }

}

