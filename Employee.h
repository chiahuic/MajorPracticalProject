#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
// general employee class
class Employee : public Person {
 public:
  Employee(int id, std::string name, int age);
  virtual std::string getDepartName()
      override;  // override the worker class's function of the same name and
                 // get the department name of the employee
  virtual void showInformation()
      override;  // override the worker class's function of the same name and
                 // let the general employee class display the information
  virtual int WorkTime() override; // The number of hours worked per day by an employee
};

#endif
