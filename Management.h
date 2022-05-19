#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "Employee.h"
#include "Manager.h"
#include "Person.h"

class Management {
 public:
  Management();          // default constructor
  void Add_Staff();      // add new staff
  void Display_Staff();  // display the information of staff
  int IsExist1(int id);   // Determine whether staffs exist by checking staff id
  bool IsExist2(std::string name); // Determine whether staffs exist by checking staff name
  void Delete_Staff();   // delete staff by seaching number
  void Modify_Staff();   // modify the information of staff by searching number
  void Search_Staff();   // check the information of staff by searching number
  void Sort_Staff();     // put staff in order
  void Show_menu();      // display interface of the management system
  void Run_System();     // After the user enters the options, the interface for each function is displayed
  void ExitSystem();     // exit system;
  ~Management();         // destructor

 protected:
  int Emp_number;      // record the current number of system
  Person** _EmpArray;  // secondary pointer to record all employee data
};

#endif
