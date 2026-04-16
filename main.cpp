#include <iostream>
#include <limits>
#include "LibraryManager.h"

void userSession(LibraryManager& lib) {
    int choice;
    do {
        std::cout << "\n--- ПАНЕЛЬ ЧИТАЧА ---\n1. Список\n2. Взяти\n0. Назад\nВибір: ";
        if (!(std::cin >> choice)) break;
        try {
            // Обробка коду, що може згенерувати виняток (Exception Handling)
            if (choice == 1) lib.displayAll(); // Користувач лише переглядає те, що вже є в системі
            else if (choice == 2) {
                int id; std::cin >> id;
                lib.borrowItem(id); // Користувач взаємодіє з книгою, але не видаляє її з бази
            }
        } catch (const std::exception& e) {
            // Перехоплення помилки та виведення її повідомлення без зупинки програми
            std::cerr << "Помилка: " << e.what() << "\n";
        }
    } while (choice != 0);
}

void adminSession(LibraryManager& lib) {
    // Реалізація розмежування прав доступу (Роль Адміністратора)
    std::string pass;
    std::cout << "Пароль: "; std::cin >> pass;
    if (pass != "admin") { std::cout << "Відмовлено!\n"; return; }

    // ... логіка додавання/видалення з обробкою try-catch ...
}

int main() {
    system("chcp 65001"); // Встановлення кодування UTF-8 для коректного виведення тексту

    LibraryManager manager; // Об'єкт менеджера, що ініціалізує базу при створенні

    int role;
    while (true) {
        // Вибір ролі користувача (User/Admin separation)
        std::cout << "\n1. Читач\n2. Бібліотекар\n0. Вихід\nВибір: ";
        if (!(std::cin >> role) || role == 0) break;
        if (role == 1) userSession(manager);
        else if (role == 2) adminSession(manager);
    }
    return 0;
}