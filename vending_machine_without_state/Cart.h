#include <bits/stdc++.h>
#include <item.h>
#include <Catalog.h>
using namespace std;

class Cart{
    map<int, int> items;
    Catalog *catalog;
public:
    Cart(Catalog* catalog){
        this->catalog = catalog;
    }

    void addItem(int id){
        auto itemI = catalog->getItemById(id);
        if(!itemI){
            cout<<"Invalid Id"<<endl;
            return;
        }
        if(items.find(id) != items.end()) items[id]++;
        else items[id] = 1;
    }

    void removeItem(int id){
        if(items.find(id) == items.end()) {
            cout<<"Item doesn't exist"<<endl;
            return;
        }
        items[id]--;
        if(items[id] == 0) items.erase(id);
    }

    void deleteItem(int id){
        if(items.find(id) == items.end()) cout<<"Item doesn't exist"<<endl;
        else items.erase(id);
    }

    int totalCost(){
        int ans = 0;
        for(auto it:items){
            auto itemI = catalog->getItemById(it.first);
            if(!itemI){
                cout<<"Invalid Cart"<<endl;
                return 0;
            }
            int cost = itemI->getPrice();
            ans += cost*it.second;
        }
        return ans;
    }

    vector<pair<int,int>> retrieveItems(){
        vector<pair<int,int>> ans;
        for(auto it:items) ans.push_back({it.first,it.second});
        return ans;
    }
};