#include"BankApplication.h"

double  BankAccount::getBalance() const{
    return balance;
}
void BankAccount::setBalance(double balance){
    BankAccount::balance = balance;
}
void BankAccount:: deposit(){
    string id;
    cout << "Enter the account number: ";
    cin >> id;
    for (int i = 0; i < clientnum; i++) {
        if (arr[i].ID == id) {
            double amount;
            cout << "Enter the amount to be deposited: ";
            cin >> amount;
            arr[i].balance += amount;
            cout << "Amount deposited successfully!" << endl;
            cout << "Your new balance is: " << arr[i].balance << endl;
            break;
        }
    }
}
void BankAccount:: withdraw(){
    string id;
    cout << "Enter the account number: ";
    cin >> id;
    for (int i = 0; i < clientnum; i++) {
        if (arr[i].ID == id) {
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

void  SavingBankAccount::setMinimumBalance(double minimumBalance) {
    minimum_balance = minimumBalance;
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
    cin >> type;
    type = toupper(type);
    arr2[clientnum].type = type;
    cout << "Enter the initial amount: ";
    cin >> balance;
    arr[clientnum].balance = balance;
    cout << "Account created successfully!" << endl;
    ID = ID + to_string(clientnum);
    arr[clientnum].ID = ID;
    cout << "Your account number is: " << ID << endl;
    clientnum++;
    cout << "Press any key to continue..." << endl;
}