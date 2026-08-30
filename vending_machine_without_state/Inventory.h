#include <bits/stdc++.h>
using namespace std;

class Inventory{
    map<int,int> items;
public:
    void setItem(int id, int qty){
        items[id] = qty;
    }
    void addItem(int id, int qty){
        items[id] += qty;
    }
    bool checkStock(vector<pair<int,int>> &request){
        for(auto it:request){
            if(items.find(it.first) == items.end()) return false;
            if(items[it.first] < it.second) return false;
        }
        return true;
    }
    void removeItem(int id){
        if(items.find(id) == items.end()) cout<<"No item with that id"<<endl;
        else items.erase(id);
    }
    bool updateStock(vector<pair<int,int>> &request){
        if(checkStock(request) == false) return false;
        for(auto it:request){
            items[it.first] -= it.second;
        }
        return true;
    }
};