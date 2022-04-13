//
// Created by adela on 4/10/2022.
//

#include "leader.h"
#include <iostream>
#include <utility>

leader::leader(std::string name, int age, bool gender, int year, std::string task_) :
        human(std::move(name), age, gender),
        year_promoted(year), task(std::move(task_)) {}

leader::leader(const leader &new_leader) : human(new_leader), year_promoted(new_leader.year_promoted), task(new_leader.task) {}

void leader::print(std::ostream &os) const {
    os << "I am " << this->name << ", leader of the team since " << this->getYear();
    os << ". My job is to make sure everything involving " << this->getTask() << " goes well";
}

std::ostream &operator<<(std::ostream &os, const leader &Leader) {
    Leader.print(os);
    return os;
}

leader &leader::operator=(const leader &leader2) {
    (*this).human::operator=(leader2);
    this->year_promoted = leader2.year_promoted;
    this->task = leader2.task;
    return *this;
}

int leader::getYear() const {
    return this->year_promoted;
}

std::string leader::getTask() const {
    return this->task;
}

void leader::setYear(int new_year) {
    this->year_promoted = new_year;
}

void leader::setTask(std::string new_task) {
    this->task = std::move(new_task);
}

role leader::getRole() {
    return role::leader;
}

leader::leader() : human() {
    year_promoted = 0;
    task = "";
}

std::istream &operator>>(std::istream &is, leader &Leader) {
    human *Human = &Leader;
    is >> Human;
    is >> Leader.year_promoted;
    is >> Leader.task;
    return is;
}

leader::~leader() = default;
