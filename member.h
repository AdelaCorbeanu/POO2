//
// Created by adela on 4/10/2022.
//

#ifndef PISICI_MEMBER_H
#define PISICI_MEMBER_H

#include <iostream>
#include <vector>
#include "human.h"

class notFound : public std::exception {
public:
    notFound() = default;

    const char *what() const noexcept override {
        return "This person hasn't worked on this project";
    }
};

class member : public human {
private:
    int year_joined;                                                                           // the year when he joined the team
    int projects_nr;
    std::vector<int> projects_done;                                                            // the codes of his projects

public:
    member(std::string name, int age, bool gender, int year, int projects_nr, std::vector<int> projects);       // constructor
    member(const member &new_member);                                                          // constructorul de copiere
    member();

    void print(std::ostream &os) const override;
    friend std::istream &operator>> (std::istream &is, member &Member);
    friend std::ostream &operator<< (std::ostream &os, const member &Member);
    member &operator=(const member &member2);

    int getYear() const;
    std::vector<int> getProjects() const;
    role getRole() override;
    int getNr() const;

    void setYear(int year);
    void setNr(int nr);
    void setProjects(std::vector<int> projects);
    void addProject(int project);
    void removeProject(int project);

    ~member() override;
};

std::ostream &operator<<(std::ostream &os, const member &Member);                              // operatorul de afisare
std::istream &operator>> (std::istream &is, member &Member);

#endif //PISICI_MEMBER_H
