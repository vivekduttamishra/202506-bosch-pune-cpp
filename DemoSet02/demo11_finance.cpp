
#include <iostream>
using namespace std;

class CreditCard; // Forward declaration;

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

    friend int findMaxPurchasePower(BankAccount &account, CreditCard &card);
};


class CreditCard{
    friend int findMaxPurchasePower(BankAccount &account, CreditCard &card);
    double creditLimit;
    string cardNumber;
    public: 
    CreditCard( string number, double limit) : creditLimit(limit), cardNumber(number) {}
    void show() {
        cout << "Credit Card Number: " << cardNumber << ", Credit Limit: " << creditLimit << endl;
    }
};






int findMaxPurchasePower(BankAccount &account, CreditCard &card) {


    return (account.balance > card.creditLimit) ? 1 : 2;
}



int BankAccount::_lastId = 0; // Initialize static member variable

int main(){
    BankAccount account1(1'00'000);
    CreditCard card1("1234-5678-9012-3456", 5'00'000);


    //how do I find out which has more purchase power?
    int result = findMaxPurchasePower(account1, card1);
    if(result == 1){
        cout << "Bank Account has more purchase power." << endl;
        account1.show();
    } else {
        cout << "Credit Card has more purchase power." << endl;
        card1.show();
    }
  
    return 0;
}