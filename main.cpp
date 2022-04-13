#include <iostream>
#include "human.h"
#include "member.h"
#include "leader.h"
#include "team.h"

int main() {
    std::vector<int> projects = {6, 9, 4, 2, 0};
    auto Member1 = std::make_shared<member>("Andrei", 19, false, 2022, 5, projects);
    auto Leader1 = std::make_shared<leader>("Petrica", 19, false, 2021, "emotional wellness of my colleagues");

    // Dumnezeu 1000000 0 0 1 1
    member Member2;
    std::cin >> Member2;

    // Iisus 1000000 0 0 supervising
    leader Leader2;
    std::cin >> Leader2;


    projects = {4, 2, 0};
    human *Human1 = new member("Matei", 19, false, 2020, 3, projects);
    human *Human2 = new leader("Stefan", 19, false, 2022, "Python stuff");

    auto *Member3 = dynamic_cast<member*>(Human1);
    auto *Leader3 = dynamic_cast<leader*>(Human2);


    member Member4;
    Member4.setName("Tiberiu");
    Member4.setGender(true);
    Member4.setAge(20);
    Member4.setYear(2022);
    Member4.setNr(4);
    projects = {6, 9, 4, 20};
    Member4.setProjects(projects);

    leader Leader4;
    Leader4.setName("Rosianu");
    Leader4.setGender(true);
    Leader4.setAge(20);
    Leader4.setYear(2021);
    Leader4.setTask("sapa de lemn");


    team Team;
    team::addPerson(Member1);
    team::addPerson(Leader1);
    team::addPerson(std::make_shared<member>(Member2));
    team::addPerson(std::make_shared<leader>(Leader2));
    team::addPerson(std::make_shared<member>(*Member3));
    team::addPerson(std::make_shared<leader>(*Leader3));
    team::addPerson(std::make_shared<member>(Member4));
    team::addPerson(std::make_shared<leader>(Leader4));


    team::meetLeaders();
    team::meetMembers();
    std::cout << '\n' << '\n';
    team::meetTeam();
    std::cout << '\n' << '\n';

    Member4.human::introduce_self();
    std::cout << '\n';
    Leader3->human::introduce_self();
    std::cout << '\n';

    Member2.addProject(100);
    std::cout << '\n' << Member2;

    try {
        Member4.removeProject(20);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
    std::cout << '\n' << Member4 << '\n';


    try {
        Member4.removeProject(13);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
