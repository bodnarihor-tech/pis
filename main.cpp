#include <iostream>
#include <vector>
#include "Book.h"

// Демонстрація через посилання на базовий клас (пункт №6)
void identifyItem(const BaseEntity& item) {
    item.getInfo();
}

int main() {
    system("chcp 65001"); // Виправлення ієрогліфів

    std::cout << "--- 1. Динамічний поліморфізм (Вказівник) ---\n";
    BaseEntity* itemPtr = new Book(1, "Кобзар", "Т. Шевченко");
    itemPtr->getInfo(); // Викличеться метод Book завдяки virtual

    std::cout << "\n--- 2. Поліморфізм через посилання ---\n";
    Book b2(2, "Лісова пісня", "Леся Українка");
    identifyItem(b2);

    std::cout << "\n--- 3. Статична прив'язка (Пояснення) ---\n";
    // Якщо прибрати virtual у BaseEntity, itemPtr->getInfo()
    // завжди викликав би метод BaseEntity, а не Book.

    delete itemPtr; // Перевірка віртуального деструктора
    return 0;
}