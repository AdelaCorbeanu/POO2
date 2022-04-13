//
// Created by adela on 4/10/2022.
//

#ifndef PISICI_LEADER_H
#define PISICI_LEADER_H

#include "human.h"

class leader : public human{
private:
    int year_promoted;
    std::string task;

public:
    leader(std::string name, int age, bool gender, int year, std::string task_);
    leader(leader const &new_leader);
    leader();

    void print(std::ostream &os) const override;

    friend std::istream &operator>> (std::istream &is, leader &Leader);
    friend std::ostream &operator<< (std::ostream &os, const leader &Leader);
    leader &operator=(const leader &leader2);

    int getYear() const;
    std::string getTask() const;
    role getRole() override;

    void setYear(int new_year);
    void setTask(std::string new_task);

    ~leader() override;
};

std::ostream &operator<< (std::ostream &os, const leader &Leader);
std::istream &operator>> (std::istream &is, leader &Leader);

#endif //PISICI_LEADER_H
