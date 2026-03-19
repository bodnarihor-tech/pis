#include <iostream>
#include <string>
#include <utility> // Для std::move

// --- Клас 1: Книга ---
class Book {
private:
    std::string title;
    std::string author;
    int year;

    // 1. Static поле: лічильник усіх створених книг (ЛР3)
    static int totalBooks;

public:
    // Конструктор з використанням this та списком ініціалізації (ЛР2 + ЛР3)
    Book(std::string title, std::string author, int year) {
        this->title = title;   // Використання this (ЛР3)
        this->author = author;
        this->year = year;
        totalBooks++;
    }

    // Параметри за замовчуванням (ЛР2)
    Book() : Book("Unknown", "None", 2026) {}

    // 2. Конструктор копіювання (Copy Constructor) (ЛР3)
    Book(const Book& other)
        : title(other.title), author(other.author), year(other.year) {
        totalBooks++;
        std::cout << "[Copy] Створено копію книги: " << title << "\n";
    }

    // 3. Конструктор переміщення (Move Constructor) (ЛР3)
    Book(Book&& other) noexcept
        : title(std::move(other.title)),
          author(std::move(other.author)),
          year(other.year) {
        other.year = 0;
        std::cout << "[Move] Ресурси книги переміщено: " << title << "\n";
    }

    // Деструктор
    ~Book() {
        std::cout << "[Destructor] Book removed: " << title << "\n";
    }

    // 4. Static метод (ЛР3)
    static int getTotalBooks() {
        return totalBooks;
    }

    // 5. Const метод (ЛР3)
    void displayInfo() const {
        std::cout << "Книга: " << title << " | Автор: " << author << " (" << year << ")\n";
    }

    // 6. Перевантаження бінарного оператора == (ЛР3)
    bool operator==(const Book& other) const {
        return (this->title == other.title && this->author == other.author);
    }

    // 7. Перевантаження унарного оператора ++ (ЛР3)
    Book& operator++() {
        this->year++;
        return *this;
    }

    // 8. Дружній оператор виведення << (ЛР3)
    friend std::ostream& operator<<(std::ostream& os, const Book& b) {
        os << "Book: '" << b.title << "' by " << b.author;
        return os;
    }
};

// Ініціалізація статичного поля
int Book::totalBooks = 0;

int main() {
    std::cout << "=== Library Management System (LR3) ===\n\n";

    // Демонстрація Static
    Book b1("1984", "George Orwell", 1949);
    Book b2("Fahrenheit 451", "Ray Bradbury", 1953);
    std::cout << "Загальна кількість книг (static): " << Book::getTotalBooks() << "\n\n";

    // Демонстрація Const об'єкта
    const Book classic("Kobzar", "T. Shevchenko", 1840);
    classic.displayInfo();

    // Демонстрація Copy Constructor
    std::cout << "\n--- Тест копіювання ---\n";
    Book b3 = b1;

    // Демонстрація Move Constructor
    std::cout << "\n--- Тест переміщення ---\n";
    Book b4 = std::move(b2);

    // Демонстрація операторів
    std::cout << "\n--- Тест операторів ---\n";
    if (b1 == b3) std::cout << "b1 та b3 однакові (operator==)\n";

    ++b1; // operator++
    std::cout << "Після ++ (рік видання змінено): " << b1 << " (operator<<)\n";

    std::cout << "\n=== Завершення програми ===\n";
    return 0;
}