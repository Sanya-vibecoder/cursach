#include "Student.h"
if (balance >= amount) {
    balance -= amount;
    std::cout << "Оплата успішна. Залишок: " << balance << " грн\n";
}
else {
    std::cout << "Недостатньо коштів.\n";
}
}

void Student::pay(double amount, int months) {
    pay(amount * months);
}

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

void Student::showInfo() const {
    std::cout << "Студент: " << name
        << ", вік: " << age
        << ", ID: " << id
        << ", кімната: " << roomNumber
        << ", баланс: " << balance << " грн\n";
}

std::ostream& operator<<(std::ostream& out, const Student& s) {
    out << "Студент: " << s.name
        << " | вік: " << s.age
        << " | ID: " << s.id
        << " | кімната: " << s.roomNumber
        << " | баланс: " << s.balance << " грн";
    return out;
}

std::istream& operator>>(std::istream& in, Student& s) {
    std::cout << "Ім'я студента: ";
    std::getline(in >> std::ws, s.name);

    std::cout << "Вік: ";
    in >> s.age;

    std::cout << "ID: ";
    in >> s.id;

    std::cout << "Баланс: ";
    in >> s.balance;

    std::cout << "Номер кімнати (0 якщо не заселяти автоматично): ";
    in >> s.roomNumber;

    return in;
}