#include<bits/stdc++.h>
using namespace std;

class PaymentProcessor{
public:
    virtual bool processPayment(int amount) = 0;
    virtual bool rollbackPayment() = 0;
};