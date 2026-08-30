#include <bits/stdc++.h>
#include <Item.h>
using namespace std;

class Catalog{
    map<int, Item> itemMap;
public:

    void addItem(Item item){
        if(itemMap.find(item.id) != itemMap.end()) cout<<"Item with similar Id already exists"<<endl;
        else itemMap[item.id] = item;
    }

    void removeItem(int id){
        if(itemMap.find(id) == itemMap.end()) cout<<"Item doesn't exist"<<endl;
        else itemMap.erase(id);
    }

    optional<Item> getItemById(int id){
        if(itemMap.find(id) == itemMap.end()) {
            cout<<"Item doesn't exist"<<endl;
            return nullptr;
        }
        else return itemMap[id];
    }
};