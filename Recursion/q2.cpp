/*
**Q2. ATM Cash Withdrawal System**
Scenario: An ATM has a limited number of banknotes of different denominations. The system needs to determine whether a requested amount can be withdrawn using the available notes.
Task:
Write a recursive C++ function that determines whether the requested amount can be formed using the available banknotes.
Available denominations: 1000, 500, 100, 50.
Requirements:
- Use recursion to explore possible combinations of notes.
- Do not use loops for the recursive search.
- Return true if the amount can be formed; otherwise, return false.
Example:
Available notes:
1000: 2
500: 1
100: 3
50: 2
Withdrawal Amount: 1650
Expected Output:
Withdrawal Possible
Notes: 1000 x 1, 500 x 1, 100 x 1, 50 x 1
*/
#include <iostream>
using namespace std;

bool withdraw(int notes[], int denominations[], int index, int amount) {
    if (amount == 0) {
        return true;
    }

    if (index == 4 || amount < 0) {
        return false;
    }

    for (int i = notes[index]; i >= 0; i--) {
        if (withdraw(notes, denominations, index + 1,
                     amount - i * denominations[index])) {
            notes[index] = i;
            return true;
        }
    }

    return false;
}

int main() {
    int denominations[4] = {1000, 500, 100, 50};
    int notes[4] = {2, 1, 3, 2};
    int amount = 1650;

    int used[4] = {0, 0, 0, 0};

    if (withdraw(used, denominations, 0, amount)) {
        cout << "Withdrawal Possible" << endl;
        cout << "Notes: ";

        for (int i = 0; i < 4; i++) {
            cout << denominations[i] << " x " << used[i];
            if (i < 3) {
                cout << ", ";
            }
        }
    } else {
        cout << "Withdrawal Not Possible";
    }

    return 0;
}
