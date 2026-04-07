#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

// Модифікатор final забороняє подальше наслідування (пункт №5)
class Book final : public LibraryItem {
private:
    std::string author;

public:
    Book(int id, std::string name, std::string author);
    void getInfo() const override; // Динамічний поліморфізм
};

#endif