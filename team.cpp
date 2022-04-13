//
// Created by adela on 4/11/2022.
//

#include "team.h"
#include "human.h"

int team::ppl = 0;
std::vector<std::shared_ptr<human>> team::people = {};

void team::addPerson(const std::shared_ptr<human> &person) {
    team::people.push_back(person);
    team::ppl++;
}

void team::meetMembers() {
    for (const auto& member : team::getPeople())
        if (member->getRole() == role::member) member->print(std::cout), std::cout << '\n';
}

void team::meetLeaders() {
    for (const auto& leader : team::people)
        if (leader->getRole() == role::leader) leader->print(std::cout), std::cout << '\n';
}

int team::getNumber() {
    return team::ppl;
}

std::vector<std::shared_ptr<human>> team::getPeople() {
    return team::people;
}

void team::meetTeam() {
    std::cout << "There are " << team::getNumber() << " people in our team. They will introduce themselves below: " << '\n';
    for (const auto& member : team::getPeople())
        member->print(std::cout), std::cout << '\n';
}

team::~team() = default;

//void team::deletePerson(const std::shared_ptr<human> &person) {
//    people.erase(person, person+1);
//
//}
