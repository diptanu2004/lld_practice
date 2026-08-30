#include <bits/stdc++.h>
#include <PaymentProcessor.h>
#include <Cashbox.h>
using namespace std;

class CashPayment: public PaymentProcessor{
    Cashbox *cashbox;
    vector<pair<int,int>> insertedCash;
    vector<pair<int,int>> changeGiven;

public:

    CashPayment(Cashbox* cashbox) {
        this->cashbox = cashbox;
    }

    void insertCash(vector<pair<int,int>> cashDenominations){
        insertedCash = cashDenominations;
    }
    bool processPayment(int amount) override{
        int total = 0;
        for(auto it:insertedCash) total += it.first*it.second;
        if(total < amount){
            cout<<"Please pay full amount"<<endl;
            return false;
        }
        int change = total - amount;
        if(change > 0){
            if(!cashbox->checkAvailability(change)) return false;

            changeGiven = cashbox->denominations(change);
        }
        cashbox->deposit(insertedCash);
        if(change>0) cashbox->remove(changeGiven);

        return true;
    }

    bool rollbackPayment() override{
        cashbox->deposit(changeGiven);
        cashbox->remove(insertedCash);
        
        return true;
    }
};