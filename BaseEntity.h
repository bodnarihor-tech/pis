#ifndef BASEENTITY_H
#define BASEENTITY_H

#include <string>
#include <iostream>
#include "IPrintable.h"

class BaseEntity : public IPrintable {
protected:
    int id;
    std::string name;

public:
    BaseEntity(int id, std::string name);
    virtual ~BaseEntity(); // Віртуальний деструктор (пункт №4)

    virtual void getInfo() const; // Віртуальна функція (пункт №2)
    
    // Реалізація інтерфейсу (пункт №7)
    void printTechnicalInfo() const override {
        std::cout << "[ID: " << id << "] Назва сутності: " << name << "\n";
    }
};

#endif