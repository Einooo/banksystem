//
// Created by muhan on 11/12/2022.
//

#ifndef UNTITLED36_BANKAPPLICATION_H
#define UNTITLED36_BANKAPPLICATION_H
#include<bits/stdc++.h>
using namespace std;
static int clientnum = 0;
class BankApplication {


};
class Client;
class BankAccount {
private:
    string ID = "FCAI-";
    double balance;

public:
    Client *client;

    double getBalance() const;

    void setBalance(double balance);

    virtual void deposit();

    virtual void withdraw();

    void display();

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
    void deposit() override;
    void withdraw() override;
};

BankAccount arr[1000];





#endif //UNTITLED36_BANKAPPLICATION_H
