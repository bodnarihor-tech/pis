#include "LibraryItem.h"

LibraryItem::LibraryItem(int id, std::string name) : BaseEntity(id, name) {}

// Перевизначення (Пункт №3)
void LibraryItem::getInfo() const {
    std::cout << "Бібліотечний об'єкт: " << name << " (ID: " << id << ")\n";
}