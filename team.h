//
// Created by adela on 4/11/2022.
//

#ifndef PISICI_TEAM_H
#define PISICI_TEAM_H

#include <iostream>
#include <vector>
#include "human.h"
#include <memory>


class team {
private:
    static int ppl;                                                             // number of people in the team
    static std::vector<std::shared_ptr<human>> people;

public:
    static void addPerson(const std::shared_ptr<human> &person);
    static void meetMembers();
    static void meetLeaders();
    static void meetTeam();

    static int getNumber();
    static std::vector<std::shared_ptr<human>> getPeople();

    ~team();
};


#endif //PISICI_TEAM_H
