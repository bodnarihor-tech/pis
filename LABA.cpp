#include <iostream>
#include <vector>
#include <string>
#include "LABA.h"

using namespace std;

struct Dish {
    string name;
    double price;
};

void restaurantSystem() {

    vector<Dish> menu = {
        {"Pizza", 150},
        {"Pasta", 120},
        {"Salad", 80},
        {"Soup", 70},
        {"Coffee", 50}
    };

    int choice;
    int quantity;
    double total = 0;

    cout << "Restaurant Menu:\n";

    for (int i = 0; i < menu.size(); i++) {
        cout << i + 1 << ". " << menu[i].name << " - " << menu[i].price << " UAH\n";
    }

    cout << "\nChoose dish (0 to finish): ";

    while (true) {

        cin >> choice;

        if (choice == 0)
            break;

        if (choice < 1 || choice > menu.size()) {
            cout << "Invalid choice. Try again: ";
            continue;
        }

        cout << "Quantity: ";
        cin >> quantity;

        total += menu[choice - 1].price * quantity;

        cout << "Added to order!\n";
        cout << "Next dish (0 to finish): ";
    }

    cout << "\nTotal price: " << total << " UAH\n";
}