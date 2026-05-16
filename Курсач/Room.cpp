#include "Room.h"

Room::Room(int number, int capacity) : number(number), capacity(capacity), occupied(0) {
    if (this->capacity < 1) this->capacity = 1;
    residents = new int[this->capacity];
    for (int i = 0; i < this->capacity; i++) residents[i] = 0;
}

Room::Room(const Room& other)
    : number(other.number), capacity(other.capacity), occupied(other.occupied) {
    residents = new int[capacity];
    for (int i = 0; i < capacity; i++) {
        residents[i] = other.residents[i];
    }
}

Room& Room::operator=(const Room& other) {
    if (this != &other) {
        delete[] residents;
        number = other.number;
        capacity = other.capacity;
        occupied = other.occupied;
        residents = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            residents[i] = other.residents[i];
        }
    }
    return *this;
}

Room::~Room() {
    delete[] residents;
}

int Room::getNumber() const {
    return number;
}

int Room::getCapacity() const {
    return capacity;
}

int Room::getOccupied() const {
    return occupied;
}

bool Room::isFree() const {
    return occupied < capacity;
}

bool Room::addResident(int studentId) {
    if (!isFree()) return false;

    for (int i = 0; i < occupied; i++) {
        if (residents[i] == studentId) return false;
    }

    residents[occupied++] = studentId;
    return true;
}

bool Room::removeResident(int studentId) {
    int index = -1;
    for (int i = 0; i < occupied; i++) {
        if (residents[i] == studentId) {
            index = i;
            break;
        }
    }

    if (index == -1) return false;

    for (int i = index; i < occupied - 1; i++) {
        residents[i] = residents[i + 1];
    }
    occupied--;
    return true;
}

bool Room::operator==(const Room& other) const {
}