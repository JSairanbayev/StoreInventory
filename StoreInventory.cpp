#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    double price;

    virtual string getType() = 0;
    virtual string getInfo() = 0;
};

class Food : public Product {
public:
    int expiryDays;

    string getType() override {
        return "Food";
    }
    string getInfo() override {
        return "Expires in " + to_string(expiryDays) + " days";
    }
};

class Electronics : public Product {
public:
    int warrantyMonths;

    string getType() override {
        return "Electronics";
    }
    string getInfo() override {
        return "Warranty: " + to_string(warrantyMonths) + " months";
    }
};

class Clothing : public Product {
public:
    string size;

    string getType() override {
        return "Clothing";
    }
    string getInfo() override {
        return "Size: " + size;
    }
};
int main()
{
    vector<Product*>products;
    int choice;

    while (true) {
        cout << "\n==== StoreInventory  ====" << endl;
        cout << "1. Add Food" << endl;
        cout << "2. Add Electronics" << endl;
        cout << "3. Add Clothing" << endl;
        cout << "4. Show all products" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (choice == 1) {
            Food* f = new Food();
            cout << "Name: ";
            cin.ignore();
            getline(cin, f->name);
            cout << "Price: ";
            cin >> f->price;
            cout << "Expiry days: ";
            cin >> f->expiryDays;
            products.push_back(f);
            cout << "Food added!" << endl;
        }
        else if (choice == 2) {
            Electronics* e = new Electronics();
            cout << "Name: ";
            cin.ignore();
            getline(cin, e->name);
            cout << "Price: ";
            cin >> e->price;
            cout << "warrantyMonths: ";
            cin >> e->warrantyMonths;
            products.push_back(e);
            cout << "Electronics added!" << endl;
        }
        else if (choice == 3) {
            Clothing* c = new Clothing();
            cout << "Name: ";
            cin.ignore();
            getline(cin, c->name);
            cout << "Price: ";
            cin >> c->price;
            cout << "size: ";
            cin >> c->size;
            products.push_back(c);
            cout << "Clothing added!" << endl;
        }
        else if (choice == 4) {
            if (products.empty()) {
                cout << "No products yet." << endl;
            }
            else {
                for (int i = 0; i < products.size(); i++) {
                    cout << i + 1 << ". " << products[i]->name
                        << " | " << products[i]->getType()
                        << " | Info: " << products[i]->getInfo() << endl;
                }
            }
        }
        else if (choice == 0) {
            cout << "Bye!" << endl;
            break;
        }
    }
    for (int i = 0; i < products.size(); i++) delete products[i];
    return 0;
}
