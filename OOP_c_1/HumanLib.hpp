//
//  Human.hpp
//  OOP_c_1
//
//  Created by Eduard Dzhumagaliev on 3/7/20.
//  Copyright © 2020 Eduard Dzhumagaliev. All rights reserved.
//

#ifndef Human_hpp
#define Human_hpp

#include <stdio.h>
#include <iostream>
#include <string>

namespace HumanLib {

const std::string INSTAGRAMDOMAIN = "http://instagr.am/";
const std::string INSTAGRAMUNDEFINED = "http://instagr.am/undefined";

enum Sex {
    Undefined,
    Male,
    Female
};

/*
 Protocol class for classes that have Instagram account
 */
class Instagrammable {
public:
    virtual std::string getInstagramLink() {
        return INSTAGRAMUNDEFINED;
    };
};

/*
 Protocol class for classes that have a phone number
 */
class Phoneable {
public:
    virtual long int getPhoneNumber() {
        return -1;
    }
};

/*
 Mixin class for classes that can call other classes
 */
class PhoneMixin: public Phoneable {
public:
    void call(Phoneable &target) {
        std::cout << getPhoneNumber() << " 📲 " << target.getPhoneNumber() << std::endl;
    }
};

class Human: public Instagrammable, public PhoneMixin {
private:
    std::string firstName;
    std::string lastName;
    long int phoneNumber = -1;
    int age;
    Sex sex;
    
public:
    int getAge();
    void setAge(int age);
    Sex getSex();
    void setSex(Sex sex);
    std::string getFullName();
    std::string getFirstName();
    std::string getLastName();
    std::string getInstagramLink() override;
    long getPhoneNumber() override;
    void setFirstName(std::string firstName);
    void setLastName(std::string secondName);
    void setFullName(std::string firstName, std::string lastName);
    void setPhoneNumber(long int phoneNumber);

    Human(int age, Sex sex, std::string firstName, std::string lastName);
};

class Student: public Human {
private:
    std::string recordNumber;
    std::string nickname;

public:
    std::string getRecordNumber();
    std::string getNickname();
    void setNickname(std::string nickname);
    std::string getInstagramLink() override;
    void setRecordNumber();
    Student(int age, Sex sex, std::string firstName, std::string lastName, const std::string &recordNumber);
};

class Animal: public Instagrammable {
private:
    std::string nickname;
public:
    std::string getNickname();
    Animal(std::string nickname);
};

class Cat: public Animal {
public:
    std::string getInstagramLink() override;
    Cat(std::string nickname);
};

}


#endif /* Human_hpp */
