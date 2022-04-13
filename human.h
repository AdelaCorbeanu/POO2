//
// Created by adela on 4/6/2022.
//

#ifndef PISICI_HUMAN_H
#define PISICI_HUMAN_H

#include <string>

enum class role {
    member,
    leader
};
class human {
protected:
    std::string name;
    int age;
    bool gender;

public:
    human(std::string name_, int age_, bool gender_);
    human(const human &Person);
    human();

    void introduce_self() const;

    virtual void print(std::ostream &os) const = 0;
    human &operator=(const human &Person);
    friend std::istream &operator>>(std::istream &is, human *Human);

    virtual role getRole() = 0;
    std::string getName() const;
    int getAge() const;
    bool getGender() const;

    void setName(std::string new_name);
    void setAge(int new_age);
    void setGender(bool new_gender);

    virtual ~human();
};

std::istream &operator>>(std::istream &is, human *Human);

#endif //PISICI_HUMAN_H
