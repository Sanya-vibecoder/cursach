#pragma once
#include <iostream>

class Room {
private:
    int number;
    int capacity;
    int occupied;
    int* residents;

public:
    Room(int number = 0, int capacity = 2);
    Room(const Room& other);
    Room& operator=(const Room& other);
    ~Room();

    int getNumber() const;
    int getCapacity() const;
    int getOccupied() const;
    bool isFree() const;

    bool addResident(int studentId);
    bool removeResident(int studentId);

    bool operator==(const Room& other) const;
    bool operator==(int roomNumber) const;

    friend std::ostream& operator<<(std::ostream& out, const Room& room);
    friend std::istream& operator>>(std::istream& in, Room& room);
}; #pragma once
