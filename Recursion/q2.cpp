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

bool withdraw(int notes[], int denominations[], int used[],
              int index, int amount);

bool tryNotes(int notes[], int denominations[], int used[],
              int index, int amount, int count) {
    if (count < 0)
        return false;

    if (count * denominations[index] <= amount) {
        used[index] = count;

        if (amount - count * denominations[index] == 0) {
            for (int i = index + 1; i < 4; i++)
                used[i] = 0;
            return true;
        }

        if (index < 3 &&
            withdraw(notes, denominations, used, index + 1,
                     amount - count * denominations[index]))
            return true;
    }

    used[index] = 0;

    return tryNotes(notes, denominations, used, index,
                    amount, count - 1);
}

bool withdraw(int notes[], int denominations[], int used[],
              int index, int amount) {
    if (amount == 0)
        return true;

    if (index == 4 || amount < 0)
        return false;

    return tryNotes(notes, denominations, used, index,
                    amount, notes[index]);
}

int main() {
    int denominations[4] = {1000, 500, 100, 50};
    int notes[4] = {2, 1, 3, 2};
    int used[4] = {0, 0, 0, 0};
    int amount = 1650;

    if (withdraw(notes, denominations, used, 0, amount)) {
        cout << "Withdrawal Possible" << endl;

        for (int i = 0; i < 4; i++)
            cout << denominations[i] << " x "
                 << used[i] << endl;
    } else {
        cout << "Withdrawal Not Possible";
    }

    return 0;
}


