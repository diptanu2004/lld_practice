#include <bits/stdc++.h>
using namespace std;

class Cashbox{
    map<int,int> cash;
public:
    void deposit(vector<pair<int,int>> &cashDenominations){
        for(auto it:cashDenominations){
            if(cash.find(it.first) != cash.end()) cash[it.first] += it.second;
            else cash[it.first] = it.second;
        }
    }

    bool checkAvailability(vector<pair<int,int>> &cashDenominations){
        for(auto it:cashDenominations){
            if(cash.find(it.first) == cash.end()) return false;
            if (cash[it.first] < it.second) return false;
        }
        return true;
    }

    bool checkAvailability(int amt){
        //long implementation
        return true;
    }

    vector<pair<int,int>> denominations(int amount){
        vector<pair<int,int>> ans;
        //logic
        return ans;
    }

    void remove(vector<pair<int,int>> &cashDenominations){
        if(checkAvailability(cashDenominations) == false){
            cout<<"Invalid Request"<<endl;
            return;
        }
        for(auto it:cashDenominations){
            cash[it.first] -= it.second;
            if(cash[it.first] == 0) cash.erase(it.first);
        }
    }
};