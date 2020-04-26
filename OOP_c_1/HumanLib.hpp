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


class Instagrammable {
public:
    virtual std::string getInstagramLink() {
        return INSTAGRAMUNDEFINED;
    };
};


class Callable {
public:
    virtual long int getPhoneNumber() {
        return -1;
    }
};


class PhoneMixin: public Callable {
public:
    void call(Callable &target) {
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
    Sex getSex();
    std::string getFullName();
    std::string getFirstName();
    std::string getLastName();
    
    std::string getInstagramLink() override;
    
    long getPhoneNumber() override;
    void setPhoneNumber(long int phoneNumber);

    
    void setAge(int age);
    void setSex(Sex sex);
    void setFirstName(std::string firstName);
    void setLastName(std::string secondName);
    void setFullName(std::string firstName, std::string lastName);

    Human(int age, Sex sex, std::string firstName, std::string lastName);
};

class Student: public Human {
private:
    std::string recordNumber;
    std::string nickname;

public:
    std::string getRecordNumber();
    std::string getNickname();
    
    std::string getInstagramLink() override;
    
    void setRecordNumber();
    void setNickname(std::string nickname);
    
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
