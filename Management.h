#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <iostream>
#include <fstream>
#define FILENAME "empFile.txt"
#include "Worker.h"
#include "Manager.h"
#include "Employee.h"

class Management
{
    public:
        Management(); // default constructor
        void Add_Staff(); // add new staff
        void Display_Staff(); // display the information of staff
        int IsExist(int id); // Determine whether staffs exist
        void Delete_Staff(); // delete staff by seaching number
        void Modify_Staff(); // modify the information of staff by searching number
        void Search_Staff(); // check the information of staff by searching number
        void Sort_Staff(); // put staff in order
        void Show_menu(); // display interface of the management system
        void ExitSystem(); // exit system;
        void save();//save file
        bool FileIsEmpty;//file not creat
        int get_EmpNumber();
        ~Management(); // destructor
        
    protected:
        int Emp_number; // record the current number of system
        Worker** _EmpArray; // secondary pointer to record all employee data

~Management();
};
#endif //MANAGEMENT_H
