#include "Book.h"

Book::Book(int id, std::string name, std::string author) 
    : LibraryItem(id, name), author(author) {}

// Динамічний поліморфізм в дії (Пункт №3)
void Book::getInfo() const {
    std::cout << "Книга: \"" << name << "\" | Автор: " << author << "\n";
}