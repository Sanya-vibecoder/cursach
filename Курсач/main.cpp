#include "Dormitory.h"
#include "TemplateUtils.h"    // needed for printArray<T> and bigger<T>
#include <iostream>
#include <limits>

void showMenu() {
    std::cout << "\n===== DORMITORY MANAGEMENT =====\n";
    std::cout << "1. Show all rooms\n";
    std::cout << "2. Show free rooms\n";
    std::cout << "3. Show all students\n";
    std::cout << "4. Add a room\n";
    std::cout << "5. Add a student\n";
    std::cout << "6. Move a student\n";
    std::cout << "7. Top up student balance\n";
    std::cout << "8. Pay for dormitory\n";
    std::cout << "9. Show students (polymorphism)\n";
    std::cout << "0. Exit\n";
    std::cout << "Your choice: ";
}

int main() {
    Dormitory dorm;

    // Initial rooms
    dorm.addRoom(Room(101, 2));
    dorm.addRoom(Room(102, 3));
    dorm.addRoom(Room(103, 1));

    // Initial students
    dorm.addStudent(Student("Ivan Petrenko", 18, 1, 101, 2500));
    dorm.addStudent(Student("Olena Koval",   19, 2, 102, 1800));
    dorm.addStudent(Student("Andriy Melnyk", 20, 3, 0,   1200));

    // Template bigger<T> — compare room capacities and balances at startup
    int cap1 = 2, cap2 = 3;
    std::cout << "\n[Template bigger<int>]    Larger room capacity: "
              << bigger<int>(cap1, cap2) << " spots\n";

    double bal1 = 2500.0, bal2 = 1800.0;
    std::cout << "[Template bigger<double>] Highest starting balance: "
              << bigger<double>(bal1, bal2) << "\n";

    int choice;

    do {
        showMenu();
        std::cin >> choice;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
        case 1:
            dorm.showRooms();
            break;

        case 2: {
            int count = 0;
            Room* freeRooms = dorm.getFreeRooms(count);
            std::cout << "\n=== Free rooms ===\n";
            if (count == 0) {
                std::cout << "No free rooms available.\n";
            } else {
                // Template printArray<Room> — uses Room::operator<< internally
                printArray<Room>(freeRooms, count);
            }
            delete[] freeRooms;
            break;
        }

        case 3:
            dorm.showStudents();
            break;

        case 4: {
            Room room;
            std::cin >> room;
            dorm.addRoom(room);
            std::cout << "Room added.\n";
            break;
        }

        case 5: {
            Student student;
            std::cin >> student;
            dorm.addStudent(student);
            std::cout << "Student added.\n";
            break;
        }

        case 6: {
            int id, newRoom;
            std::cout << "Student ID: ";
            std::cin >> id;
            std::cout << "New room number: ";
            std::cin >> newRoom;
            if (dorm.moveStudent(id, newRoom))
                std::cout << "Student moved successfully.\n";
            else
                std::cout << "Failed to move student.\n";
            break;
        }

        case 7: {
            int id;
            double amount;
            std::cout << "Student ID: ";
            std::cin >> id;
            std::cout << "Amount to add: ";
            std::cin >> amount;
            dorm.topUpStudent(id, amount);
            break;
        }

        case 8: {
            int id;
            std::cout << "Student ID: ";
            std::cin >> id;
            dorm.payForDorm(id);
            break;
        }

        case 9:
            dorm.showPeoplePolymorphically();
            break;

        case 0:
            std::cout << "Goodbye!\n";
            break;

        default:
            std::cout << "Unknown command.\n";
        }

    } while (choice != 0);

    return 0;
}
