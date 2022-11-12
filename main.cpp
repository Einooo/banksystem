#include"BankApplication.h"
#include<bits/stdc++.h>
using namespace std;;
int main(){
    int choice;
    do {
        cout << "1. Create an account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                arr2[clientnum].create_account();
                break;
            case 2:
                arr[clientnum].deposit();
                break;
            case 3:
                arr[clientnum].withdraw();
                break;
            case 4:
                arr[clientnum].display();
                break;
            case 5:
                cout << "Thank you for using our services!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 5);
    return 0;

}
