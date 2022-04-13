//
// Created by adela on 4/6/2022.
//

#include "human.h"
#include <iostream>
#include <utility>

void human::introduce_self() const {
    std::cout << "Hello! My name is " << this->getName() << " and I am a " << this->getAge()<< " years old ";
    std::cout << (this->getGender() ? "man" : "woman");
}

human::human(std::string name_, int age_, bool gender_) : name(std::move(name_)), age(age_), gender(gender_) {}

human::human(const human &Person) : name(Person.name), age(Person.age), gender(Person.gender) {}

human &human::operator=(const human &Person) {
    this->name = Person.name;
    this->age = Person.age;
    this->gender = Person.gender;
    return *this;
}

std::string human::getName() const {
    return this->name;
}

int human::getAge() const {
    return this->age;
}

bool human::getGender() const {
    return this->gender;
}

void human::setName(std::string new_name) {
    this->name = std::move(new_name);
}

void human::setAge(int new_age) {
    this->age = new_age;
}

void human::setGender(bool new_gender) {
    this->gender = new_gender;
}

std::istream &operator>>(std::istream &is, human *Human) {
    is >> Human->name >> Human->age >> Human->gender;
    return is;
}

human::human() : age(0), gender(false) {}

human::~human() = default;
