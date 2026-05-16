#include "Dormitory.h"
#include <iostream>
#include <limits>
#include <clocale>

void showMenu() {
    std::cout << "\n===== ВІРТУАЛЬНИЙ ГУРТОЖИТОК =====\n";
    std::cout << "1. Показати всі кімнати\n";
    std::cout << "2. Показати вільні кімнати\n";
    std::cout << "3. Показати всіх студентів\n";
    std::cout << "4. Додати кімнату\n";
    std::cout << "5. Додати студента\n";
    std::cout << "6. Переселити студента\n";
    std::cout << "7. Поповнити баланс студента\n";
    std::cout << "8. Оплатити проживання\n";
    std::cout << "9. Показати студентів через поліморфізм\n";
    std::cout << "0. Вихід\n";
    std::cout << "Ваш вибір: ";
}

int main() {
    setlocale(LC_ALL, "");

    Dormitory dorm;

    // Початкові кімнати
    dorm.addRoom(Room(101, 2));
    dorm.addRoom(Room(102, 3));
    dorm.addRoom(Room(103, 1));

    // Початкові студенти
    dorm.addStudent(Student("Іван Петренко", 18, 1, 101, 2500));
    dorm.addStudent(Student("Олена Коваль", 19, 2, 102, 1800));
    dorm.addStudent(Student("Андрій Мельник", 20, 3, 0, 1200));

    int choice;

    do {
        showMenu();
        std::cin >> choice;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некоректний ввід.\n";
            continue;
        }

        switch (choice) {
        case 1:
            dorm.showRooms();
            break;

        case 2: {
            int count = 0;
            Room* freeRooms = dorm.getFreeRooms(count);

            std::cout << "
                == = Вільні кімнати == =
                ";
                if (count == 0) {
                    std::cout << "Немає вільних кімнат.
                        ";
                }
                else {
                    for (int i = 0; i < count; i++) {
                        std::cout << freeRooms[i] << std::endl;
                    }
                }

            delete[] freeRooms;
        }