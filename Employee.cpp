#include "Employee.h"

#include <iostream>

Employee::Employee(int id, std::string name, int age) {
  this->_Id = id;
  this->_Name = name;
  this->_Age = age;
}

std::string Employee::getDepartName() { return "Employee"; }
int Employee::WorkTime() {return 8;}
void Employee::showInformation() {
  std::cout << "Number: " << this->_Id << "\tName: " << this->_Name
            << "\tAge: " << this->_Age
            << "\tName of the post: " << this->getDepartName()
            << "\tJob: Complete tasks assigned by manager."
            << "\tTime hours: "<<this->WorkTime()<<" hours." <<std::endl;
}
