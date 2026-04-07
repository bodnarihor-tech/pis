#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include "BaseEntity.h"

class LibraryItem : public BaseEntity {
public:
    LibraryItem(int id, std::string name);
    void getInfo() const override; // Перевизначення (пункт №3)
};

#endif