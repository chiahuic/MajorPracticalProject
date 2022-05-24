#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "Employee.h"
#include "Manager.h"
#include "Person.h"
#include <fstream>
#define FILENAME "staffs.txt"

class Management {
 public:
  Management();          // default constructor
  void Add_Staff();      // add new staff that include name,age and staff number
  void Display_Staff();  // display the information of staff
  int IsExist1(int id);  // Determine whether staffs exist by checking staff id
  int Staff_number();
  bool IsExist2(std::string name);  // Determine whether staffs exist by
                                    // checking staff name
  bool FileisEmpty;    // check whether the file is empty
  void init_Staff();
  void Delete_Staff();              // delete staff by seaching number
  void Modify_Staff();  // modify the information of staff by searching number
  void Search_Staff();  // check the information of staff by searching number
  void Sort_Staff();    // In ascending order of staff number
  void Save_information();
  void Show_menu();     // display interface of the management system
  void Run_System();    // After the user enters the options, the interface for each function is displayed
  void ExitSystem();    // exit system;
  ~Management();        // destructor

 protected:
  int _StaffNumber;      // record the current number of system
  Person** _StaffArray;  // secondary pointer to record all employee data
};

#endif
