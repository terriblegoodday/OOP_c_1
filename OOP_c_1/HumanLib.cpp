//
//  Human.cpp
//  OOP_c_1
//
//  Created by Eduard Dzhumagaliev on 3/7/20.
//  Copyright © 2020 Eduard Dzhumagaliev. All rights reserved.
//

#include "HumanLib.hpp"

using namespace HumanLib;

int Human::getAge() {
    return this->age;
};

void Human::setAge(int age) {
    this->age = age;
};

Sex Human::getSex() {
    return this->sex;
};

void Human::setSex(Sex sex) {
    this->sex = sex;
};

std::string Human::getFullName() {
    return this->firstName + " " + this->lastName;
};

std::string Human::getFirstName() {
    return this->firstName;
};

std::string Human::getLastName() {
    return this->lastName;
};

std::string Human::getInstagramLink() {
    return INSTAGRAMDOMAIN + this->getFirstName() + this->getLastName();
};

std::string Student::getNickname() {
      return this->nickname;
};

void Student::setNickname(std::string nickname) {
    this->nickname = nickname;
};

std::string Student::getInstagramLink() {
    auto nickname = this->getNickname();
    if (nickname != "") return INSTAGRAMDOMAIN + nickname;
    return Human::getInstagramLink();
};

Human::Human(int age, Sex sex, std::string firstName, std::string lastName): age(age), sex(sex) {
    
    this->firstName = firstName;
    this->lastName = lastName;
};

Student::Student(int age, Sex sex, std::string firstName, std::string lastName, const std::string &recordNumber): Human(age, sex, firstName, lastName) {
    this->recordNumber = recordNumber;
};

Animal::Animal(std::string nickname): nickname(nickname) {};

std::string Animal::getNickname() {
    return this->nickname;
};

std::string Cat::getInstagramLink() {
    return INSTAGRAMDOMAIN + this->getNickname() + "Cat";
};

Cat::Cat(std::string nickname): Animal(nickname) {};

void Human::setPhoneNumber(long phoneNumber) {
    this->phoneNumber = phoneNumber;
};

long Human::getPhoneNumber() {
    return this->phoneNumber;
};
