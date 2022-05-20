#include "Manager.h"

#include <iostream>

Manager::Manager(int id, std::string name, int age) {
  this->_Id = id;
  this->_Name = name;
  this->_Age = age;
}

std::string Manager::getDepartName() { return "Manager"; }
int Manager::WorkTime() {return 9;}
void Manager::showInformation() {
  std::cout << "Number: " << this->_Id << "\tName: " << this->_Name
            << "\tAge: " << this->_Age
            << "\tName of the post: " << this->getDepartName()
            << "\tJob: Assign tasks to employees." 
            << "\tTime hours: "<<this->WorkTime()<<" hours." <<std::endl;
}
