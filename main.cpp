#include <iostream>  // Для std::cout
#include <string>    // Для std::string

// --- Клас 1: Книга ---
class Book {
private:
    std::string title;
    std::string author;
    int year;
public:
    // Конструктор з параметрами за замовчуванням
    Book(std::string t = "Default Title", std::string a = "Unknown Author", int y = 2026)
        : title(t), author(a), year(y) {}

    // Деструктор
    ~Book() {
        std::cout << "[Destructor] Book removed: " << title << "\n";
    }

    void display() const {
        std::cout << "Book: " << title << " | Author: " << author << " | Year: " << year << "\n";
    }
};

// --- Клас 2: Читач ---
class Reader {
private:
    std::string name;
    int readerID;
public:
    // Основний конструктор
    Reader(std::string n, int id) : name(n), readerID(id) {}

    // Делегування конструктора
    Reader() : Reader("Guest", 0) {
        std::cout << "[Delegation] Default reader initialized\n";
    }

    // Деструктор
    ~Reader() {
        std::cout << "[Destructor] Reader record deleted: " << name << "\n";
    }

    void display() const {
        std::cout << "Reader: " << name << " | ID: " << readerID << "\n";
    }
};

// --- Клас 3: Бібліотекар ---
class Librarian {
private:
    std::string empName;
    int accessLevel;
public:
    Librarian(std::string name, int level) : empName(name), accessLevel(level) {}
    Librarian() : empName("Staff"), accessLevel(1) {}

    // Деструктор
    ~Librarian() {
        std::cout << "[Destructor] Librarian shift ended: " << empName << "\n";
    }

    void logAction(std::string action) const {
        std::cout << "Librarian " << empName << " (Level " << accessLevel << ") performed: " << action << "\n";
    }
};

int main() {
    std::cout << "=== Library Management System Start ===\n\n";

    // 1. Створення об'єктів
    Book b1("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    Book b2; // Використає параметри за замовчуванням

    Reader r1("Andriy", 777);
    Reader r2; // Використає делегований конструктор

    Librarian admin("Olena Petrivna", 5);

    // 2. Виведення даних
    std::cout << "\n--- Current Database State ---\n";
    b1.display();
    b2.display();
    r1.display();
    r2.display();

    admin.logAction("Database Backup");

    std::cout << "\n=== Shutting Down System ===\n";

    return 0;
}