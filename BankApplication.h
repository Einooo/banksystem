//
// Created by muhan on 11/12/2022.
//

#ifndef UNTITLED36_BANKAPPLICATION_H
#define UNTITLED36_BANKAPPLICATION_H
#include<bits/stdc++.h>
using namespace std;

extern int clientnum;

class Client;
class BankAccount {
protected:
    char type;
    string ID = "FCAI-";
    double balance;
public:
    Client *client;
    double getBalance() const;
    void setBalance(double balance);
    virtual void deposit();
    virtual void withdraw();
    void display();
    void setType(char);
    string getID() const;
    void setID(string);
};

class Client{
public:
    BankAccount *account;
    string name;
    string address;
    string phonenum;
    void create_account();

};

class SavingBankAccount:public BankAccount{
private:
    double minimum_balance ;
public:
    SavingBankAccount(double minimum_balance = 1000){
        this->minimum_balance = minimum_balance;
    }

    double getMinimumBalance() const;

    void setMinimumBalance(double minimumBalance);
    void deposit() ;
    void withdraw();
};

extern BankAccount arr[1000];
extern Client arr2[1000];

class BankApplication {
public:
    BankApplication(){
        int clientnum= 0;
    }
    bool addclient(){
        arr2[clientnum].create_account();
        return true;
    }
    void run() {
        int choice;
        do {
            cout<<"Welcome to FCAI Banking Application"<<endl;
            cout << "1. Create a New Account" << endl;
            cout << "2. List Clients and Accounts" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Deposit Money" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    addclient();
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

    }
};

#endif //UNTITLED36_BANKAPPLICATION_H