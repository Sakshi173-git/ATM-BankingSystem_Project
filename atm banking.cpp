
#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int main() {
    system("color 3F");
    int pin = 1234, option, enteredPin, count = 0, amount = 0;
    float balance = 5000;
    int continueTransaction = 1;

    time_t now;
    time(&now);
    cout << "\n\t\t\t\t\t     " << ctime(&now);
    cout << "\n\t\t\t==================*ATM Banking System*===================";

    while (pin != enteredPin) {
        cout << "\nPlease enter your PIN: ";
        cin >> enteredPin;

        if (enteredPin != pin) {
            Beep(610, 500);
            cout << "Invalid PIN!!!" << endl;
            count++;
        }

        if (count == 3) {
            cout << "Too many incorrect attempts. Exiting..." << endl;
            exit(0);
        }
    }

    do {
        cout << "\n\t\t\t===============*Available Transactions*================";
        cout << "\n\n\t\t1. Withdraw";
        cout << "\n\t\t2. Deposit";
        cout << "\n\t\t3. Check Balance";
        cout << "\n\n\tPlease select an option: ";
        cin >> option;

        switch (option) {
        case 1:
            do {
                cout << "\n\t\tEnter the amount to withdraw (multiple of 500): ";
                cin >> amount;

                if (amount % 500 != 0) {
                    cout << "\n\tThe amount should be a multiple of 500.";
                } else if (amount > balance) {
                    cout << "\n\tSorry, insufficient balance.";
                    amount = 0;
                }
            } while (amount % 500 != 0 || amount > balance);

            if (amount != 0) {
                balance -= amount;
                cout << "\n\t\tYou have withdrawn Rs. " << amount << ". Your new balance is Rs. " << balance;
            }
            break;

        case 2:
            cout << "\n\t\tPlease enter the amount to deposit: ";
            cin >> amount;
            if (amount > 0) {
                balance += amount;
                cout << "\n\t\tYou have deposited Rs. " << amount << ". Your new balance is Rs. " << balance;
            } else {
                cout << "\n\t\tInvalid deposit amount!";
            }
            break;

        case 3:
            cout << "\n\t\tYour current balance is Rs. " << balance;
            break;

        default:
            Beep(610, 500);
            cout << "\n\t\tInvalid Option!!!";
        }

        cout << "\n\n\t\tDo you want to perform another transaction? Press 1[Yes], 0[No]: ";
        cin >> continueTransaction;

    } while (continueTransaction == 1);

    cout << "\n\t\t====================*Thank You for Banking with Us!!!*================\n";
    return 0;
}

