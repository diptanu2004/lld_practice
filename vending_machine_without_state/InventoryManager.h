#include <bits/stdc++.h>
#include <Item.h>
#include <Catalog.h>
#include <Inventory.h>
using namespace std;

class InventoryManager{
    static InventoryManager* instance;
    Inventory *inventory;
    InventoryManager(Inventory *inventory){
        this->catalog = catalog;
        this->inventory = inventory;
    }
public:

    static InventoryManager* getInstance(Inventory *inventory){
        if(instance == nullptr){
            instance = new InventoryManager(inventory);
        }
        return instance;
    }

    bool checkStock(vector<pair<int,int>> &request){
        return inventory->checkStock(request);
    }
     
    void setItem(int id, int qty){
        inventory->setItem(id,qty);
    }

    void addItem(int id, int qty){
        inventory->addItem(id,qty);
    }

    void removeItem(int id){
        inventory->removeItem(id);
    }

    bool updateStock(vector<pair<int,int>> &request){
        return inventory->updateStock(request);
    }
};