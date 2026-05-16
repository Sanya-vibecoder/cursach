#pragma once
#include "Person.h"
#include <iostream>
#include <string>

class Student : public Person {
private:
    int id;
    int roomNumber;
    double balance;

public:
    Student(const std::string& name = "Unknown", int age = 0, int id = 0,
        int roomNumber = 0, double balance = 0.0);

    int getId() const;
    int getRoomNumber() const;
    double getBalance() const;

    void setRoomNumber(int roomNumber);

    void pay(double amount);              // перевантаження 1
    void pay(double amount, int months);  // перевантаження 2

    Student operator+(double amount) const;     // перевантаження операторів
    Student& operator+=(double amount);
    bool operator==(const Student& other) const;

    void showInfo() const override;

    friend std::ostream& operator<<(std::ostream& out, const Student& s);
    friend std::istream& operator>>(std::istream& in, Student& s);
}; #pragma once
