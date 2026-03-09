#include <iostream>
#include <string>

// --- Клас 1: Книга (Використовуємо параметри за замовчуванням) ---
class Book {
private:
std::string title;
std::string author;
int year;

public:
// Конструктор із параметрами за замовчуванням та списком ініціалізації
Book(std::string t = "Default Title", std::string a = "Unknown Author", int y = 2026)
: title(t), author(a), year(y) {
std::cout << "[Constructor] Book created: " << title << "\n";
}

// Деструктор
~Book() {
std::cout << "[Destructor] Book removed: " << title << "\n";
}

void display() const {
std::cout << "Book: " << title << " | Author: " << author << " | Year: " << year << "\n";
}
};

// --- Клас 2: Читач (Використовуємо делегування конструкторів) ---
class Reader {
private:
std::string name;
int readerID;

public:
// Головний конструктор
Reader(std::string n, int id) : name(n), readerID(id) {
std::cout << "[Constructor] Reader added: " << name << "\n";
}

// Делегування: цей конструктор викликає головний
Reader() : Reader("Guest", 0) {
std::cout << "[Delegation] Default reader initialized\n";
}

~Reader() {
std::cout << "[Destructor] Reader record deleted: " << name << "\n";
}

void display() const {
std::cout << "Reader: " << name << " | ID: " << readerID << "\n";
}
};

// --- Клас 3: Бібліотекар (Перевантажений конструктор) ---
class Librarian {
private:
std::string empName;
int accessLevel;

public:
// Список ініціалізації
Librarian(std::string name, int level) : empName(name), accessLevel(level) {
std::cout << "[Constructor] Librarian assigned: " << empName << "\n";
}

// Перевантажений конструктор
Librarian() : empName("Staff"), accessLevel(1) {}

~Librarian() {
std::cout << "[Destructor] Librarian shift ended: " << empName << "\n";
}

void logAction(std::string action) const {
std::cout << "Librarian " << empName << " (Level " << accessLevel << ") performed: " << action << "\n";
}
};

// Головна функція програми
int main() {
std::cout << "=== Library Management System Start ===\n\n";

// 1. Створення книги (використання параметрів за замовчуванням)
Book b1("The Great Gatsby", "F. Scott Fitzgerald", 1925);
Book b2; // Будуть використані значення за замовчуванням

// 2. Створення читача (через делегування)
Reader r1("Andriy", 777);
Reader r2; // Викличе делегований конструктор

// 3. Створення бібліотекаря
Librarian admin("Olena Petrivna", 5);

std::cout << "\n--- Current Database State ---\n";
b1.display();
b2.display();
r1.display();
r2.display();
admin.logAction("Database Backup");

std::cout << "\n=== Shutting Down System ===\n";
// Об'єкти знищуються автоматично, спрацюють деструктори
return 0;
}