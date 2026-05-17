#pragma once
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& name = "Unknown", int age = 0);
    virtual ~Person();

    std::string getName() const;
    int getAge() const;

    virtual void showInfo() const = 0;
};
