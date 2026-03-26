#include <iostream>
#include <string>
#include <vector>
#include <utility>

// ==========================================
// ЛАБ 5: ІНТЕРФЕЙС
// ==========================================
class IPrintable {
public:
    virtual void printStatus() const = 0;
    virtual ~IPrintable() {}
};

// ==========================================
// ЛАБ 4: КОМПОЗИЦІЯ (Has-A Relationship)
// ==========================================
class ContactInfo {
public:
    std::string email;
    ContactInfo(std::string e = "no-email") : email(e) {}
};

// ==========================================
// ЛАБ 5: АБСТРАКТНИЙ БАЗОВИЙ КЛАС
// ==========================================
class Entity {
protected:
    std::string name;
    // ЛАБ 3: STATIC поле
    static int totalEntities;

public:
    // ЛАБ 2: Конструктор з параметром за замовчуванням
    // ЛАБ 2: Список ініціалізації
    Entity(std::string n = "Unknown") : name(n) {
        totalEntities++;
        std::cout << "[Constructor] Entity: " << name << "\n";
    }

    // ЛАБ 5: ВІРТУАЛЬНИЙ ДЕСТРУКТОР
    virtual ~Entity() {
        totalEntities--;
        std::cout << "[Destructor] Entity: " << name << "\n";
    }

    // ЛАБ 3: STATIC метод
    static int getTotalCount() { return totalEntities; }

    // ЛАБ 5: Статична прив'язка (Static Binding)
    void identify() const {
        std::cout << "Базовий Entity: " << name << " (Static Binding)\n";
    }

    virtual void performAction() const {
        std::cout << name << " виконує базову дію.\n";
    }

    // ЛАБ 5: Чисто віртуальна функція
    virtual void getRole() const = 0;

    // ЛАБ 3: Перевантаження оператора << (Friend)
    friend std::ostream& operator<<(std::ostream& os, const Entity& e) {
        os << "Entity Name: " << e.name;
        return os;
    }
};

int Entity::totalEntities = 0; // Ініціалізація static

// ==========================================
// ДОЧІРНІЙ КЛАС: Reader
// ==========================================
class Reader : public Entity, public IPrintable {
private:
    int readerID;
    ContactInfo contact; // ЛАБ 4: Композиція

public:
    // ЛАБ 2: ДЕЛЕГУВАННЯ конструкторів
    Reader() : Reader("Guest", 0) {}

    Reader(std::string n, int id) : Entity(n), readerID(id) {
        std::cout << "[Constructor] Reader ID: " << readerID << "\n";
    }

    // ЛАБ 3 & 4: COPY Constructor
    Reader(const Reader& other) : Entity(other), readerID(other.readerID), contact(other.contact) {
        std::cout << "[Copy Constructor] Reader\n";
    }

    // ЛАБ 3 & 4: MOVE Constructor
    Reader(Reader&& other) noexcept : Entity(std::move(other)), readerID(other.readerID), contact(std::move(other.contact)) {
        std::cout << "[Move Constructor] Reader\n";
    }

    // ЛАБ 3: Використання THIS
    void setID(int readerID) {
        this->readerID = readerID;
    }

    // ЛАБ 5: OVERRIDE та FINAL
    void getRole() const override final {
        std::cout << "Роль: Читач (ID: " << readerID << ")\n";
    }

    void performAction() const override {
        std::cout << "Читач " << name << " читає книгу.\n";
    }

    void printStatus() const override {
        std::cout << "[STATUS] Читач " << name << " активний.\n";
    }
};

// Демонстрація поліморфізму через ПОСИЛАННЯ (ЛАБ 5, п.6)
void showAction(const Entity& e) {
    e.performAction();
}

int main() {
    // ЛАБ 3: CONST об'єкт
    const Reader constReader("Admin", 1);
    // constReader.setID(5); // Помилка, бо об'єкт константний - ДЕМОНСТРАЦІЯ ЛАБ 3

    // ЛАБ 5: Динамічний поліморфізм (Pointer)
    Entity* ptr = new Reader("Ihor", 123);

    std::cout << "Total Entities: " << Entity::getTotalCount() << "\n";

    ptr->identify();      // Static binding (викличе базу)
    ptr->performAction(); // Dynamic binding (викличе Reader)

    showAction(*ptr);     // ЛАБ 5: Через посилання

    delete ptr;           // Виклик віртуального деструктора

    return 0;
}