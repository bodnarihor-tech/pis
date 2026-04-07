#include "BaseEntity.h"

BaseEntity::BaseEntity(int id, std::string name) : id(id), name(name) {
    std::cout << "[BaseEntity] Створено сутність: " << name << "\n";
}

// Віртуальний деструктор (Пункт №4)
BaseEntity::~BaseEntity() {
    std::cout << "[BaseEntity] Видалено сутність: " << name << "\n";
}

// Віртуальна функція (Пункт №2)
void BaseEntity::getInfo() const {
    std::cout << "Це базова сутність бібліотеки: " << name << "\n";
}