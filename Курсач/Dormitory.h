#pragma once
#include "Room.h"
#include "Student.h"
#include "TemplateUtils.h"
#include <string>

class Dormitory {
private:
    Room* rooms;
    int roomCount;

    Student* students;
    int studentCount;

    double monthlyFee;

public:
    Dormitory();
    ~Dormitory();

    void addRoom(const Room& room);
    void addStudent(const Student& student);

    int findStudent(int id) const;                  // function overloading
    int findStudent(const std::string& name) const;

    int findRoom(int roomNumber) const;

    void showRooms() const;
    void showStudents() const;
    void showPeoplePolymorphically() const;

    Room* getFreeRooms(int& count) const;

    bool moveStudent(int studentId, int newRoomNumber);               // function overloading
    bool moveStudent(const std::string& studentName, int newRoomNumber);

    bool payForDorm(int studentId);                                   // function overloading
    bool payForDorm(int studentId, double amount);
    bool payForDorm(const std::string& studentName);
    bool payForDorm(const std::string& studentName, double amount);

    bool topUpStudent(int studentId, double amount);
    bool topUpStudent(const std::string& studentName, double amount);

    int getRoomCount() const;
    int getStudentCount() const;
};
