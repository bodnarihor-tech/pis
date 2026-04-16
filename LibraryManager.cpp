#include "LibraryManager.h"
#include <fstream>   // Робота з файловими потоками (ifstream, ofstream)
#include <iostream>
#include <stdexcept> // Підключення стандартних винятків для обробки помилок
#include <algorithm>

LibraryManager::LibraryManager() {
    loadFromFile(); // Автоматичне відновлення бази даних при ініціалізації об'єкта
}

void LibraryManager::addItem(std::shared_ptr<Book> item) {
    library.push_back(item);
    saveToFile(); // Оновлення файлу після зміни стану контейнера
}

void LibraryManager::removeItem(int id) {
    auto initialSize = library.size();

    // Ідіома Erase-Remove з використанням лямбда-виразу для пошуку за ID
    library.erase(std::remove_if(library.begin(), library.end(),
        [id](const std::shared_ptr<Book>& item) {
            return item->getId() == id;
        }), library.end());

    if (library.size() < initialSize) {
        std::cout << "Книгу видалено.\n";
        saveToFile();
    } else {
        // Генерація винятку runtime_error у разі відсутності елемента в базі
        throw std::runtime_error("Книгу з ID " + std::to_string(id) + " не знайдено.");
    }
}

void LibraryManager::borrowItem(int id) {
    bool found = false;
    for (const auto& item : library) {
        if (item->getId() == id) {
            // Режим std::ios::app для дозапису нових подій у кінець лог-файлу
            std::ofstream out(logFile, std::ios::app);
            out << "Видано: " << item->getName() << " (ID: " << id << ")\n";
            found = true;
            break;
        }
    }
    if (!found) throw std::runtime_error("Книга недоступна.");
}

void LibraryManager::saveToFile() {
    std::ofstream out(libFile); // Перезапис основного файлу бази даних
    if (!out) return;
    for (const auto& item : library) {
        out << item->getId() << " " << item->getName() << "\n";
    }
}

void LibraryManager::loadFromFile() {
    std::ifstream in(libFile); // Потік для читання даних з диска
    if (!in) return;
    int id; std::string name;
    while (in >> id >> name) {
        // Створення розумного вказівника через make_shared для оптимізації пам'яті
        library.push_back(std::make_shared<Book>(id, name, "Unknown"));
    }
}