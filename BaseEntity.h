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
    // Конструктор ініціалізації базових полів
    BaseEntity(int id, std::string name);

    // Віртуальний деструктор для коректного видалення об'єктів через вказівники
    virtual ~BaseEntity();

    // Геттери для доступу до приватних полів (необхідні для пошуку та збереження у файл)
    int getId() const { return id; }
    std::string getName() const { return name; }

    // Віртуальні методи для реалізації поліморфізму
    virtual void getInfo() const;

    // Реалізація методу інтерфейсу IPrintable
    void printTechnicalInfo() const override {
        std::cout << "[ID: " << id << "] Назва: " << name << "\n";
    }
};

#endif