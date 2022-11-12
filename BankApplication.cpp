#include"BankApplication.h"
int clientnum= 0;
BankAccount arr[1000];
Client arr2[1000];
double  BankAccount::getBalance() const{
    return balance;
}
void BankAccount::setBalance(double balance){
    BankAccount::balance = balance;
}
void BankAccount::setType(char ch) {
    BankAccount::type = ch;
}
string BankAccount::getID() const {
    return ID;
}
void BankAccount::setID(string ID) {
    BankAccount::ID = ID;
}
void BankAccount:: deposit(){
    string id;
    cout << "Enter the account number: ";
    cin >> id;
    for (int i = 0; i < clientnum; i++) {
        if (arr[i].ID == id && arr[i].type == 'B') {
            double amount;
            cout << "Enter the amount to be deposited: ";
            cin >> amount;
            arr[i].balance += amount;
            cout << "Amount deposited successfully!" << endl;
            cout << "Your new balance is: " << arr[i].balance << endl;
            break;
        }
        else if (arr[i].ID == id && arr[i].type == 'S') {
            double amount;
            cout << "Enter the amount to be deposited: ";
            cin >> amount;
            if (amount < 100) {
                cout << "The amount should be >= 100 LE" << endl;
            }
            else {
                arr[i].balance += amount;
                cout << "Amount deposited successfully!" << endl;
                cout << "Your new balance is: " << arr[i].balance << endl;
                break;
            }
            arr[i].balance += amount;
            cout << "Amount deposited successfully!" << endl;
            cout << "Your new balance is: " << arr[i].balance << endl;
            break;
        }
        else if (i == clientnum - 1) {
            cout << "Account not found!" << endl;
        }
    }
}
void BankAccount:: withdraw(){
    string id;
    cout << "Enter the account number: ";
    cin >> id;
    for (int i = 0; i < clientnum; i++) {
        if (arr[i].ID == id && arr[i].type == 'B') {
            double amount;
            cout << "Enter the amount to be withdrawn: ";
            cin >> amount;
            if (amount > arr[i].balance) {
                cout << "Insufficient balance!" << endl;
            }
            else {
                arr[i].balance -= amount;
                cout << "Amount withdrawn successfully!" << endl;
                cout << "Your new balance is: " << arr[i].balance << endl;
            }
            break;
        }
        else if (arr[i].ID == id && arr[i].type == 'S') {
            double amount;
            cout << "Enter the amount to be withdrawn: ";
            cin >> amount;
            if (amount > arr[i].balance) {
                cout << "Insufficient balance!" << endl;
            }
            else if (amount > arr[i].balance - 1000) {
                cout << "You cannot withdraw more than 1000!" << endl;
            }
            else {
                arr[i].balance -= amount;
                cout << "Amount withdrawn successfully!" << endl;
                cout << "Your new balance is: " << arr[i].balance << endl;
            }
            break;
        }
    }
}
void BankAccount::display(){
    for(int i = 0; i < clientnum; i++) {
        cout << "Name: " << arr2[i].name<< endl;
        cout << "Address: " << arr2[i].address << endl;
        cout << "Phone number: " << arr2[i].phonenum << endl;
        cout << "Type: " << arr[i].type << endl;
        cout << "Balance: " << arr[i].balance << endl;
    }
}

double SavingBankAccount::getMinimumBalance() const {
    return minimum_balance;
}
void SavingBankAccount::setMinimumBalance(double minimumBalance = 1000) {
    minimum_balance = minimumBalance;
}
void SavingBankAccount::deposit() {
    string id;
    cout << "Enter the account number: ";
    cin >> id;
    for (int i = 0; i < clientnum; i++) {
        if (arr[i].getID() == id) {
            double amount;
            cout << "Enter the amount to be deposited: ";
            cin >> amount;
            if (amount < 100) {
                cout << "The amount should be >= 100 LE" << endl;
            }
            else {
                arr[i].setBalance(arr[i].getBalance() + amount);
                cout << "Amount deposited successfully!" << endl;
                cout << "Your new balance is: " << arr[i].getBalance() << endl;
            }
            break;
        }
    }
}
void SavingBankAccount::withdraw() {
    string id;
    cout << "Enter the account number: ";
    cin >> id;
    for (int i = 0; i < clientnum; i++) {
        if (arr[i].getID() == id) {
            double amount;
            cout << "Enter the amount to be withdrawn: ";
            cin >> amount;
            if (amount > arr[i].getBalance()) {
                cout << "Insufficient balance!" << endl;
            }
            else if (arr[i].getBalance() - amount < minimum_balance) {
                cout << "The amount should be >= minimum balance" << endl;
            }
            else {
                arr[i].setBalance(arr[i].getBalance() - amount);
                cout << "Amount withdrawn successfully!" << endl;
                cout << "Your new balance is: " << arr[i].getBalance() << endl;
            }
            break;
        }
    }
}


void Client:: create_account(){
    cout << "Enter the name of the account holder: ";
    cin.ignore();
    getline(cin, name);
    arr2[clientnum].name = name;
    cout << "Enter the address of the account holder: ";
    getline(cin, address);
    arr2[clientnum].address = address;
    cout << "Enter the phone number of the account holder: ";
    cin >> phonenum;
    arr2[clientnum].phonenum = phonenum;
    cout << "Enter the type of the account (B/S): ";
    char ch;
    cin >> ch;
    ch = toupper(ch);
    arr[clientnum].setType(ch);
    cout << "Enter the initial amount: ";
    int balance;
    cin >> balance;
    arr[clientnum].setBalance(balance);
    cout << "Account created successfully!" << endl;
    arr[clientnum].setID("FCAI-" + to_string(clientnum));
    cout << "Your account number is: " << arr[clientnum].getID() << endl;
    clientnum++;
}