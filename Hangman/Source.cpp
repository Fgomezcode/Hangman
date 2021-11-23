//MAIN CPP
#include"Functions.h"

int main()
{
    int length = 0;
    char again = 'Y';

    do {
        vector<Word> words = createList();

        length = words.size();

        display(words, randomNumber(length));

        cout << "\nAgain? (Y/N):\t";
        cin >> again;

        again = toupper(again);

    } while (again == 'Y');

    return 0;
}

