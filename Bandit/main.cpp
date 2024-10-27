#include <iostream>
#include <ctime>
using namespace std;

void spinSlot(char& slot1, char& slot2, char& slot3) 
{
    char symbols[] = {'A', 'B', 'C', '7', '$'};
    int numSymbols = sizeof(symbols) / sizeof(symbols[0]);
    slot1 = symbols[rand() % numSymbols];
    slot2 = symbols[rand() % numSymbols];
    slot3 = symbols[rand() % numSymbols];
}

bool checkWin(char slot1, char slot2, char slot3)
{
    return (slot1 == slot2 && slot2 == slot3);
}

int main() 
{
    srand(static_cast<unsigned int>(time(0)));
    char slot1, slot2, slot3;
    char playAgain;

    do 
    {
        cout << "Press Enter to spin the slot machine...";
        cin.ignore();
        spinSlot(slot1, slot2, slot3);
        cout << "Results: " << slot1 << " | " << slot2 << " | " << slot3 << endl;

        if (checkWin(slot1, slot2, slot3)) 
        {
            cout << "Congratulations! You win!" << endl;
        } else {
            cout << "Try again!" << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore();

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}

