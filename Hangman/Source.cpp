//MAIN CPP
#include"Functions.h"

int main()
{
    int length = 0;
    char again = 'Y';
    bool isValid = false;

    do {
        vector<Word> words = createList();

        length = words.size();

        display(words, randomNumber(length));

        // prompt the user for valid input, and limit the input to two valid choices
        do {
            cout << "\nAgain? (Y/N):\t";
            cin >> again;

            again = toupper(again);

            if (again == 'Y' || again == 'N') {
                isValid = true;
            }
            else {
                isValid = false;
            }
        } while (isValid== false);


    } while (again == 'Y');

    return 0;
}

