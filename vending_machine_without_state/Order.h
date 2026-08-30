#include <bits/stdc++.h>
#include <Item.h>
#include <InventoryManager.h>
#include <Inventory.h>
#include <PaymentProcessor.h>
#include <Cashbox.h>
#include <Cart.h>
#include <Catalog.h>

class Order{
    InventoryManager *inventoryManager;
    PaymentProcessor *processor;
    Cart cart;

public:
    Order(InventoryManager *iv, PaymentProcessor *paymentMethod, Catalog *catalog): cart(catalog){
        this->inventoryManager = iv;
        this->processor = paymentMethod;
    }

    void addToCart(int id, int qty){
        while(qty--) cart.addItem(id);
    }

    void removeFromCart(int id){
        cart.removeItem(id);
    }

    void deleteFromCart(int id){
        cart.deleteItem(id);
    }

    int getTotal(){
        //So that user knows how much cash to insert before process order is executed
        return cart.totalCost();
    }


    bool processOrder(){
        vector<pair<int,int>> items = cart.retrieveItems();
        bool checkStock = inventoryManager->checkStock(items);
        if(checkStock == false) {
            cout<<"Out of stock"<<endl;
            return false;
        }

        int total = cart.totalCost();
        bool paymentDone = processor->processPayment(total);

        if(!paymentDone){
            cout<<"Payment Failed"<<endl;
            return false;
        }

        bool updateInventory = inventoryManager->updateStock(items);

        if(!updateInventory){
            cout<<"Failed updating inventory. Rolling back payment"<<endl;
            processor->rollbackPayment();
            return false;
        }

        return true;
    }
};