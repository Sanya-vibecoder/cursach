#include "Dormitory.h"
#include <iostream>

Dormitory::Dormitory()
    : rooms(nullptr), roomCount(0),
      students(nullptr), studentCount(0),
      monthlyFee(1000.0) {}

Dormitory::~Dormitory() {
    delete[] rooms;
    delete[] students;
}

void Dormitory::addRoom(const Room& room) {
    Room* newRooms = new Room[roomCount + 1];
    for (int i = 0; i < roomCount; i++) {
        newRooms[i] = rooms[i];
    }
    newRooms[roomCount] = room;
    delete[] rooms;
    rooms = newRooms;
    roomCount++;
}

void Dormitory::addStudent(const Student& student) {
    Student newStudent = student;

    if (newStudent.getRoomNumber() != 0) {
        int roomIndex = findRoom(newStudent.getRoomNumber());
        if (roomIndex != -1) {
            if (!rooms[roomIndex].addResident(newStudent.getId())) {
                std::cout << "Room is full. Assigning student to first available room.\n";
                newStudent.setRoomNumber(0);
            }
        }
        else {
            std::cout << "Room not found. Assigning student automatically.\n";
            newStudent.setRoomNumber(0);
        }
    }

    if (newStudent.getRoomNumber() == 0) {
        for (int i = 0; i < roomCount; i++) {
            if (rooms[i].isFree()) {
                rooms[i].addResident(newStudent.getId());
                newStudent.setRoomNumber(rooms[i].getNumber());
                break;
            }
        }
    }

    Student* newStudents = new Student[studentCount + 1];
    for (int i = 0; i < studentCount; i++) {
        newStudents[i] = students[i];
    }
    newStudents[studentCount] = newStudent;
    delete[] students;
    students = newStudents;
    studentCount++;
}

// Function overloading: search
int Dormitory::findStudent(int id) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getId() == id) return i;
    }
    return -1;
}

int Dormitory::findStudent(const std::string& name) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getName() == name) return i;
    }
    return -1;
}

int Dormitory::findRoom(int roomNumber) const {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].getNumber() == roomNumber) return i;
    }
    return -1;
}

void Dormitory::showRooms() const {
    std::cout << "\n=== All rooms ===\n";
    if (roomCount == 0) {
        std::cout << "No rooms available.\n";
        return;
    }
    for (int i = 0; i < roomCount; i++) {
        std::cout << rooms[i] << "\n";
    }
}

void Dormitory::showStudents() const {
    std::cout << "\n=== All students ===\n";
    if (studentCount == 0) {
        std::cout << "No students registered.\n";
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        std::cout << students[i] << "\n";
    }
}

// Polymorphism: call via base class pointer
void Dormitory::showPeoplePolymorphically() const {
    std::cout << "\n=== Students (polymorphism) ===\n";
    for (int i = 0; i < studentCount; i++) {
        Person* p = &students[i];
        p->showInfo();
    }
}

// Dynamic array of free rooms
Room* Dormitory::getFreeRooms(int& count) const {
    count = 0;
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].isFree()) count++;
    }
    if (count == 0) return nullptr;

    Room* freeRooms = new Room[count];
    int j = 0;
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].isFree()) freeRooms[j++] = rooms[i];
    }
    return freeRooms;
}

// Function overloading: move student
bool Dormitory::moveStudent(int studentId, int newRoomNumber) {
    int sIdx = findStudent(studentId);
    if (sIdx == -1) {
        std::cout << "Student not found.\n";
        return false;
    }
    int newRoomIdx = findRoom(newRoomNumber);
    if (newRoomIdx == -1) {
        std::cout << "Room not found.\n";
        return false;
    }
    if (!rooms[newRoomIdx].isFree()) {
        std::cout << "Room is full.\n";
        return false;
    }

    int oldRoomIdx = findRoom(students[sIdx].getRoomNumber());
    if (oldRoomIdx != -1) rooms[oldRoomIdx].removeResident(studentId);

    rooms[newRoomIdx].addResident(studentId);
    students[sIdx].setRoomNumber(newRoomNumber);
    return true;
}

bool Dormitory::moveStudent(const std::string& studentName, int newRoomNumber) {
    int sIdx = findStudent(studentName);
    if (sIdx == -1) {
        std::cout << "Student not found.\n";
        return false;
    }
    return moveStudent(students[sIdx].getId(), newRoomNumber);
}

// Function overloading: pay for dormitory
bool Dormitory::payForDorm(int studentId) {
    return payForDorm(studentId, monthlyFee);
}

bool Dormitory::payForDorm(int studentId, double amount) {
    int sIdx = findStudent(studentId);
    if (sIdx == -1) {
        std::cout << "Student not found.\n";
        return false;
    }
    students[sIdx].pay(amount);
    return true;
}

bool Dormitory::payForDorm(const std::string& studentName) {
    int sIdx = findStudent(studentName);
    if (sIdx == -1) {
        std::cout << "Student not found.\n";
        return false;
    }
    return payForDorm(students[sIdx].getId(), monthlyFee);
}

bool Dormitory::payForDorm(const std::string& studentName, double amount) {
    int sIdx = findStudent(studentName);
    if (sIdx == -1) {
        std::cout << "Student not found.\n";
        return false;
    }
    return payForDorm(students[sIdx].getId(), amount);
}

// Function overloading: top up balance
bool Dormitory::topUpStudent(int studentId, double amount) {
    int sIdx = findStudent(studentId);
    if (sIdx == -1) {
        std::cout << "Student not found.\n";
        return false;
    }
    students[sIdx] += amount;
    std::cout << "Balance updated. New balance: " << students[sIdx].getBalance() << "\n";
    return true;
}

bool Dormitory::topUpStudent(const std::string& studentName, double amount) {
    int sIdx = findStudent(studentName);
    if (sIdx == -1) {
        std::cout << "Student not found.\n";
        return false;
    }
    return topUpStudent(students[sIdx].getId(), amount);
}

int Dormitory::getRoomCount() const { return roomCount; }
int Dormitory::getStudentCount() const { return studentCount; }
