#include <iostream>
#include <string>
#include <utility>

// --- Клас 1: Книга (З усіма фішками ЛР3) ---
class Book {
private:
    std::string title;
    std::string author;
    int year;
    static int totalBooks; // Static поле

public:
    // Конструктор + this
    Book(std::string title, std::string author, int year) {
        this->title = title;
        this->author = author;
        this->year = year;
        totalBooks++;
    }

    Book() : Book("Unknown", "None", 2026) {}

    // Конструктор копіювання
    Book(const Book& other) : title(other.title), author(other.author), year(other.year) {
        totalBooks++;
        std::cout << "[Copy] Копія книги: " << title << "\n";
    }

    // Конструктор переміщення
    Book(Book&& other) noexcept : title(std::move(other.title)), author(std::move(other.author)), year(other.year) {
        other.year = 0;
        std::cout << "[Move] Ресурси переміщено: " << title << "\n";
    }

    ~Book() { std::cout << "[Destructor] Book removed: " << title << "\n"; }

    static int getTotalBooks() { return totalBooks; }

    void displayInfo() const { // Const метод
        std::cout << "Книга: " << title << " (" << year << ")\n";
    }

    bool operator==(const Book& other) const { // Оператор ==
        return (this->title == other.title);
    }

    Book& operator++() { // Оператор ++
        this->year++;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Book& b) { // Оператор <<
        os << "Book: '" << b.title << "'";
        return os;
    }
};

int Book::totalBooks = 0;

// --- Клас 2: Читач (З ЛР2) ---
class Reader {
private:
    std::string name;
    int readerID;
public:
    Reader(std::string n, int id) : name(n), readerID(id) {}
    Reader() : Reader("Guest", 0) {} // Делегування

    void display() const {
        std::cout << "Reader: " << name << " | ID: " << readerID << "\n";
    }
};

// --- Клас 3: Бібліотекар (З ЛР2) ---
class Librarian {
private:
    std::string empName;
    int accessLevel;
public:
    Librarian(std::string name, int level) : empName(name), accessLevel(level) {}

    void logAction(std::string action) const {
        std::cout << "Librarian " << empName << " виконує: " << action << "\n";
    }
};

int main() {
    std::cout << "=== Library Management System (LR3) ===\n\n";

    // Працюємо з Книгами (ЛР3)
    Book b1("1984", "George Orwell", 1949);
    Book b2("Kobzar", "T. Shevchenko", 1840);

    std::cout << "Всього книг (static): " << Book::getTotalBooks() << "\n";

    Book b3 = b1; // Тест копіювання
    ++b1;         // Тест оператора ++
    std::cout << b1 << " (через оператор <<)\n\n";

    // Повертаємо Читачів та Бібліотекарів (ЛР2)
    Reader r1("Andriy", 777);
    Librarian admin("Olena Petrivna", 5);

    r1.display();
    admin.logAction("Перевірка ЛР №3");

    return 0;
}