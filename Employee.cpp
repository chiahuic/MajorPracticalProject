#include <iostream>

#include "Employee.h"

Employee::Employee(int id, std::string name, int age) 
{
    this->_ID = id;
    this->_Name = name;
    this->_Age = age;
    
}

std::string Employee::getDepartName() 
{
    return "Employee";
}

void Employee::showInformation() 
{
    std::cout << "Number: " << this->_ID
              <<"\tName: " << this->_Name
              << "\tAge: " << this->_Age
              << "\tName of the post: " << this->getDepartName() 
              << "\tJob: Complete tasks assigned by manager." << std::endl;
}