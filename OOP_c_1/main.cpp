//
//  main.cpp
//  OOP_c_1
//
//  Created by Eduard Dzhumagaliev on 3/7/20.
//  Copyright © 2020 Eduard Dzhumagaliev. All rights reserved.
//

#include <iostream>
#include "HumanLib.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    HumanLib::Human human1(19, HumanLib::Sex::Male, "Andrei", "Vasilevsky");
    HumanLib::Student student1(19, HumanLib::Sex::Male, "Eduard", "Dzhumagaliev", "fjdufshu");
    std::cout << human1.getFullName() << std::endl;
    std::cout << human1.getInstagramLink() << std::endl;
    std::cout << student1.getInstagramLink() << std::endl;
    student1.setNickname("terriblegoodday");
    std::cout << student1.getInstagramLink() << std::endl;
    HumanLib::Animal animal1("Bolt");
    std::cerr << animal1.getInstagramLink() << std::endl;
    HumanLib::Cat cat1("Frank");
    std::cout << cat1.getInstagramLink() << std::endl;
    human1.setPhoneNumber(81432567);
    student1.setPhoneNumber(89006662256);
    human1.call(student1);
}
