#include "Dormitory.h"
#include <iostream>

Dormitory::Dormitory() : rooms(nullptr), roomCount(0), students(nullptr), studentCount(0), monthlyFee(1000.0) {}

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
                std::cout << "Кімната заповнена. Студента буде поселено автоматично в першу вільну кімнату.\n";
                newStudent.setRoomNumber(0);
            }
        }
        else {
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