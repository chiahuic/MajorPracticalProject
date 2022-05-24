#include "Manager.h"

#include <iostream>

Manager::Manager(int id, std::string name, int age, int D_id) {
  this->_Id = id;
  this->_Name = name;
  this->_Age = age;
  this->_DepartmentID = D_id;
}

std::string Manager::getDepartName() { return "Manager"; }
int Manager::WorkTime() {return 9;}
void Manager::showInformation() {
  std::cout << "Number: " << this->_Id << "\tName: " << this->_Name
            << "\tAge: " << this->_Age
            << "\tName of the post: " << this->getDepartName()
            << "\tPost ID: " << this->_DepartmentID
            << "\tJob: Assign tasks to employees." 
            << "\tTime hours: "<<this->WorkTime()<<" hours." <<std::endl;
}

