#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <vector>
#include <memory>    // Використання бібліотеки для роботи з std::shared_ptr
#include <string>
#include <algorithm>
#include "Book.h"

class LibraryManager {
private:
    // Контейнер shared_ptr забезпечує автоматичне керування життєвим циклом об'єктів
    std::vector<std::shared_ptr<Book>> library;

    // Константи для роботи з файловою системою (збереження даних та логів)
    const std::string libFile = "library_data.txt";
    const std::string logFile = "borrow_history.txt";

    void saveToFile(); // Інкапсуляція логіки серіалізації даних у файл
    void loadFromFile();

public:
    LibraryManager();
    // Передача об'єктів через розумні вказівники для спільного володіння ресурсом
    void addItem(std::shared_ptr<Book> item);
    void removeItem(int id);
    void displayAll() const;
    void borrowItem(int id);
    void showLog() const;
};

#endif