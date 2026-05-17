#include "Student.h"

// Constructor
Student::Student(const std::string& name, int age, int id, int roomNumber, double balance)
    : Person(name, age), id(id), roomNumber(roomNumber), balance(balance) {}

// Getters
int Student::getId() const { return id; }
int Student::getRoomNumber() const { return roomNumber; }
double Student::getBalance() const { return balance; }

void Student::setRoomNumber(int roomNumber) {
    this->roomNumber = roomNumber;
}

// Function overloading: payment
void Student::pay(double amount) {
    if (balance >= amount) {
        balance -= amount;
        std::cout << "Payment successful. Remaining balance: " << balance << "\n";
    }
    else {
        std::cout << "Insufficient funds.\n";
    }
}

void Student::pay(double amount, int months) {
    pay(amount * months);
}

// Operator overloading
Student Student::operator+(double amount) const {
    Student temp = *this;
    temp.balance += amount;
    return temp;
}

Student& Student::operator+=(double amount) {
    balance += amount;
    return *this;
}

bool Student::operator==(const Student& other) const {
    return id == other.id;
}

// Polymorphic method
void Student::showInfo() const {
    std::cout << "Student: " << name
        << ", age: " << age
        << ", ID: " << id
        << ", room: " << roomNumber
        << ", balance: " << balance << "\n";
}

// Stream I/O
std::ostream& operator<<(std::ostream& out, const Student& s) {
    out << "Student: " << s.name
        << " | age: " << s.age
        << " | ID: " << s.id
        << " | room: " << s.roomNumber
        << " | balance: " << s.balance;
    return out;
}

std::istream& operator>>(std::istream& in, Student& s) {
    std::cout << "Student name: ";
    std::getline(in >> std::ws, s.name);

    std::cout << "Age: ";
    in >> s.age;

    std::cout << "ID: ";
    in >> s.id;

    std::cout << "Balance: ";
    in >> s.balance;

    std::cout << "Room number (0 to assign automatically): ";
    in >> s.roomNumber;

    return in;
}
