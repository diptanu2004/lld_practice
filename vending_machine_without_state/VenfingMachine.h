#include <bits/stdc++.h>
#include <Catalog.h>
#include <Inventory.h>
#include <InventoryManager.h>
#include <Cashbox.h>
#include <CashPayment.h>
#include <Order.h>

using namespace std;

class VendingMachine {
    Catalog catalog;
    Inventory inventory;
    InventoryManager* inventoryManager;
    Cashbox cashbox;
    CashPayment* cashPayment;
    Order* currentOrder;

public:

    VendingMachine()
        : inventoryManager(InventoryManager::getInstance(&inventory)),
          cashPayment(new CashPayment(&cashbox)),
          currentOrder(nullptr)
    {
    }

    void startOrder() {
        if(currentOrder != nullptr) {
            cout << "Order already in progress" << endl;
            return;
        }

        currentOrder = new Order(
            inventoryManager,
            cashPayment,
            &catalog
        );
    }

    void addItem(int id, int qty) {
        if(currentOrder == nullptr) {
            cout << "No active order" << endl;
            return;
        }

        currentOrder->addToCart(id, qty);
    }

    void removeItem(int id) {
        if(currentOrder == nullptr) {
            cout << "No active order" << endl;
            return;
        }

        currentOrder->removeFromCart(id);
    }

    void deleteItem(int id) {
        if(currentOrder == nullptr) {
            cout << "No active order" << endl;
            return;
        }

        currentOrder->deleteFromCart(id);
    }

    int getTotal() {
        if(currentOrder == nullptr) {
            cout << "No active order" << endl;
            return 0;
        }

        return currentOrder->getTotal();
    }

    void insertCash(vector<pair<int,int>>& cash) {
        if(currentOrder == nullptr) {
            cout << "No active order" << endl;
            return;
        }

        cashPayment->insertCash(cash);
    }

    bool processOrder() {
        if(currentOrder == nullptr) {
            cout << "No active order" << endl;
            return false;
        }

        bool success = currentOrder->processOrder();

        if(success) {
            delete currentOrder;
            currentOrder = nullptr;
        }

        return success;
    }

    void restock(int id, int qty) {
        inventoryManager->addItem(id, qty);
    }

    void setStock(int id, int qty) {
        inventoryManager->setItem(id, qty);
    }

    void modifyCashbox(vector<pair<int,int>>& cash) {
        cashbox.deposit(cash);
    }

    void addCatalogItem(Item item) {
        catalog.addItem(item);
    }
};