#include <iostream>
#include <string>
#include <utility>

// --- 1. БАЗОВИЙ КЛАС (Вгору по ієрархії) ---
class Person {
protected:
    std::string name;
public:
    Person(std::string n) : name(n) {
        std::cout << "[Constructor] Person: " << name << "\n";
    }
    virtual ~Person() {
        std::cout << "[Destructor] Person: " << name << "\n";
    }
};

// --- 2. НАСЛІДУВАННЯ "Is-A" (Reader є Person) ---
class Reader : public Person {
private:
    int readerID;
public:
    Reader(std::string n, int id) : Person(n), readerID(id) {
        std::cout << "[Constructor] Reader ID: " << readerID << "\n";
    }

    void show() const {
        std::cout << "Читач: " << name << " | ID: " << readerID << "\n";
    }
};

// --- 3. КЛАС КНИГА ---
class Book {
protected:
    std::string title;
    std::string author;
public:
    Book(std::string t, std::string a) : title(t), author(a) {}
    virtual ~Book() {}

    virtual void display() const {
        std::cout << "Книга: " << title << " | Автор: " << author << "\n";
    }
};

// --- 4. НАСЛІДУВАННЯ "Is-A" (Вниз по ієрархії: Електронна книга) ---
class EBook : public Book {
private:
    double fileSize;
    std::string format;
public:
    EBook(std::string t, std::string a, double size, std::string fmt)
        : Book(t, a), fileSize(size), format(fmt) {}

    // ПУНКТ 6: Copy Constructor
    EBook(const EBook& other) : Book(other), fileSize(other.fileSize), format(other.format) {
        std::cout << "[Copy] Копіювання EBook: " << title << "\n";
    }

    // ПУНКТ 6: Move Constructor (ДОДАНО)
    EBook(EBook&& other) noexcept
        : Book(std::move(other)), fileSize(other.fileSize), format(std::move(other.format)) {
        other.fileSize = 0;
        std::cout << "[Move] Переміщення EBook: " << title << "\n";
    }

    // ПУНКТ 6: Operator=
    EBook& operator=(const EBook& other) {
        if (this != &other) {
            Book::operator=(other); // Копіюємо частину базового класу
            this->fileSize = other.fileSize;
            this->format = other.format;
            std::cout << "[Operator=] Присвоєння EBook: " << title << "\n";
        }
        return *this;
    }

    void display() const override {
        std::cout << "Е-Книга: " << title << " [" << format << ", " << fileSize << "MB]\n";
    }
};

// --- 5. КОМПОЗИЦІЯ "Has-A" ---
class Library {
private:
    std::string libName;
    Book* featuredBook; // Бібліотека МАЄ книгу (агрегація/композиція)
public:
    Library(std::string name, Book* b) : libName(name), featuredBook(b) {}

    void info() const {
        std::cout << "\nБібліотека: " << libName << "\nРекомендована книга: ";
        if (featuredBook) featuredBook->display();
    }
};

int main() {
    std::cout << "=== Лабораторна робота №4 (Наслідування) ===\n\n";

    // Демонстрація ієрархії
    Reader student("Bodnar Ihor", 101);
    student.show();

    std::cout << "\n--- Робота з EBook (Copy/Move/Assign) ---\n";
    EBook eb1("Kobzar", "T. Shevchenko", 15.5, "PDF");

    EBook eb2 = eb1;               // Copy
    EBook eb3 = std::move(eb1);    // Move (тепер eb1 порожня в плані ресурсів)

    eb2.display();
    eb3.display();

    std::cout << "\n--- Композиція (Has-A) ---\n";
    Library myLib("Zentral Library", &eb3);
    myLib.info();

    std::cout << "\n=== Завершення програми ===\n";
    return 0;
}