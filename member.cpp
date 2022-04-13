//
// Created by adela on 4/10/2022.
//

#include <iostream>
#include "member.h"
#include <algorithm>

member::member(const member &new_member) : human(new_member),
        year_joined(new_member.year_joined), projects_done(new_member.projects_done), projects_nr(new_member.projects_nr) {}

member::member(std::string name, int age, bool gender, int year, int projects_nr, std::vector<int> projects) :
        human(std::move(name), age, gender),
        year_joined(year), projects_nr(projects_nr), projects_done(std::move(projects)) {}

void member::print(std::ostream &os) const  {
    os << "I am " << this->getName() << ", member of the team since " << this->getYear();
    os << ". I worked on " << this->getNr() << " project" << (this->getNr() > 1 ? "s: " : ": ");
    for (auto project : this->getProjects()) os << " " << project;
    os << ".";
}

std::ostream &operator<<(std::ostream &os, const member &Member) {
    Member.print(os);
    return os;
}

member &member::operator=(const member &member2) {
    (*this).human::operator=(member2);
    this->year_joined = member2.year_joined;
    this->projects_done = member2.projects_done;
    this->projects_nr = member2.projects_nr;
    return *this;
}

int member::getYear() const {
    return this->year_joined;
}

std::vector<int> member::getProjects() const {
    return this->projects_done;
}

void member::setYear(int year) {
    this->year_joined = year;
}

void member::setProjects(std::vector<int> projects) {
    this->projects_done = std::move(projects);
    this->projects_nr = (int)this->projects_done.size();
}

void member::addProject(int project) {
    this->projects_done.push_back(project);
    this->projects_nr++;
}

void member::removeProject(int project) {
    auto aux = std::find(projects_done.begin(), projects_done.end(), project);
    if (aux != projects_done.end()) {
        this->projects_done.erase(aux);
        this->projects_nr--;
    }
    else throw notFound();
}

std::istream &operator>>(std::istream &is, member &Member) {
    human *Human = &Member;
    is >> Human;
    is >> Member.year_joined;
    is >> Member.projects_nr;
    Member.projects_done.resize(Member.projects_nr);
    for (auto &project : Member.projects_done)
        is >> project;
    return is;
}

role member::getRole() {
    return role::member;
}

member::member() : human() {
    year_joined = 0;
    projects_nr = 0;
    projects_done = {};
}

int member::getNr() const {
    return this->projects_nr;
}

void member::setNr(int nr) {
    this->projects_nr = nr;
}

member::~member() = default;
