#include <iostream>

#include "Manager.h"

Manager::Manager(int id, std::string name, int age) 
{
    this->_ID = id;
    this->_Name = name;
    this->_Age = age;
}

std::string Manager::getDepartName() 
{
    return "Manager";
}

void Manager::showInformation() 
{
    std::cout << "Number: " << this->_ID
              <<"\tName: " << this->_Name
              << "\tAge: " << this->_Age
              << "\tName of the post: " << this->getDepartName() 
              << "\tJob: Assign tasks to employees." << std::endl;
}