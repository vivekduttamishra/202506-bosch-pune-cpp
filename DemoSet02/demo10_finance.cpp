
#include <iostream>
using namespace std;


class BankAccount{
    double balance;
    static int  _lastId;
    int id;
    public:
    BankAccount(double initialBalance)  {
        this->balance = initialBalance;
        this->id = ++_lastId; // Increment lastId and assign to id
    }
    BankAccount &getBigAccount(BankAccount &other){
        if(other.balance > balance){
            return other;
        } else{
            return *this;
        }
    }

    void show() {
        cout << "Account ID: " << id << ", Balance: " << balance << endl;
    }

    
};


class CreditCard{
    double creditLimit;
    string cardNumber;
    public: 
    CreditCard( string number, double limit) : creditLimit(limit), cardNumber(number) {}
    void show() {
        cout << "Credit Card Number: " << cardNumber << ", Credit Limit: " << creditLimit << endl;
    }
};



int BankAccount::_lastId = 0; // Initialize static member variable

int main(){
    BankAccount account1(1000);
    BankAccount account2(2000);
    
    BankAccount &biggerAccount = account1.getBigAccount(account2);
    
    biggerAccount.show();
  
    return 0;
}