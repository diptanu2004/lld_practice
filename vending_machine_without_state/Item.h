#include <bits/stdc++.h>
using namespace std;

class Item{
    int price = 0;
public:
    int id;
    string name;

    item(string name, int id){
        this->name = name;
        this->id = id;
    }
    void setPrice(int price){
        this->price = price;
    }
    const int getPrice(){
        if(this->price == 0) cout<<"Price not set"<<endl;
        return this->price;
    }
};