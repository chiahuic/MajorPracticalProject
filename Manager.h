#ifndef MANAGER_H
#define MANAGER_H

#include "Person.h"

// Management personnel class
class Manager : public Person {
 public:
  Manager(int id, std::string name,
          int age);  // constructor with three basic parameters
  virtual std::string getDepartName() override;  // show job title
  virtual void showInformation()
      override;  // display the information of manager
  virtual int WorkTime() override; // The number of hours worked per day by an manager
};

#endif
