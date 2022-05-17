#include <iostream>

#include "Management.h"
#include <string>

Management::Management() {
  this->Emp_number = 0;
  this->_EmpArray = NULL;
}

void Management::ExitSystem() {
  std::cout << "Welcome to use system again" << std::endl;
}

void Management::Add_Staff() {
  std::cout << "Please enter the number of staffs you want to add" << std::endl;
  int addNum = 0;  // saves the amount entered by the user
  std::cin >> addNum;

  if (addNum > 0 && addNum < 50) {
    int new_Size =
        this->Emp_number + addNum;  // The number of existing employees plus the
                                    // number of new employees
    Person** new_Space = new Person*[new_Size];  // Open up new space
    if (this->_EmpArray !=
        NULL)  // if the data of the original pointer is not null
    {
      for (int i = 0; i < this->Emp_number;
           i++)  // data of the original pointer is added to the new pointer
      {
        new_Space[i] = this->_EmpArray[i];
      }
    }

    for (int i = 0; i < addNum; i++) {
      int ID;
      std::string NAME;
      int AGE;
      int Select;
      std::cout
          << "Please enter pure and positive number as the staff number of "
          << i + 1 << " staff: " << std::endl;
      std::cin >> ID;
      while (ID < 0) {
        std::cout << "Invalid staff number, please enter again: " << std::endl;
        std::cin >> AGE;
      }
      std::cout << "Please enter the name: " << std::endl;
      std::cin >> NAME;
      while (NAME.length() == 0) {
        std::cout << "Name must be added. Please enter it again" << std::endl;
        std::cin >> NAME;
      }
      std::cout << "Please enter the age: " << std::endl;
      std::cin >> AGE;
      while (AGE <= 0 && AGE >= 150) {
        std::cout << "Invalid number, please enter again: " << std::endl;
        std::cin >> AGE;
      }
      std::cout << "Please choose job title(enter 1 or 2)" << std::endl;
      std::cout << "1. Employee" << std::endl;
      std::cout << "2. Manager" << std::endl;
      std::cin >> Select;
      while (Select > 2 && Select < 1) {
        std::cout << "Invalid number, choose 1 or 2 please" << std::endl;
        std::cin >> Select;
      }
      Person* staff = NULL;
      switch (Select) {
        case 1:
          staff = new Employee(ID, NAME, AGE);
          break;
        case 2:
          staff = new Manager(ID, NAME, AGE);
          break;
        default:
          std::cout << "Error choosen" << std::endl;
          break;
      }
      new_Space[this->Emp_number + i] = staff;
    }

    delete[] this->_EmpArray;     // delete the initial array
    this->_EmpArray = new_Space;  // update a new array
    this->Emp_number = new_Size;  // update the current number of staffs
    std::cout << "Add successful" << std::endl;
  } else {
    std::cout << "Invalid number." << std::endl;
  }
}
void Management::Display_Staff() {
  if (_EmpArray != NULL) {
    for (int i = 0; i < this->Emp_number; i++) {
      // std::cout << _EmpArray[i]->showInformation() << std::endl;
      this->_EmpArray[i]->showInformation();
    }
  }
}
int Management::IsExist1(int id) {
  int index = -1;
  for (int i = 0; i < Emp_number; i++) {
    if (this->_EmpArray[i]->_ID == id) {
       index = i;
       break;
    }
  }
  return index;
}
bool Management::IsExist2(std::string name) {
  for (int i = 0; i < Emp_number; i++) {
    if (this->_EmpArray[i]->_Name == name) {
       return true;
       break;
    }
  }
  return false;
}
void Management::Delete_Staff() {
  std::cout << "Please enter the number of the staff you want to delete: " << std::endl;
  int id = 0;
  std::cin >> id;
  int index = this->IsExist1(id);
  if (index != -1) { // it means the staff exist, and need delete
    for (int i = index; i < Emp_number-1;i++) {
      std::cout << "Delete successfully" << std::endl;
      this->_EmpArray[i] = this->_EmpArray[i+1];
    }
    this->Emp_number--; // number of staff decrease
  }
  else {
    std::cout<< "Deletion failed, the staff could not be found." << std::endl;
  }
}

void Management::Modify_Staff() {
  std::cout << "Please enter the number of the employee whose information you want to modify: " << std::endl;
  int id = 0;
  std::cin >> id;
  int modify = this->IsExist1(id);
  
}

void Management::Search_Staff() {
  std::cout<<"Please select a query mode" << std::endl;
  std::cout<< "1. staff number" << std::endl;
  std::cout<< "2. staff name" << std::endl;
  int select = 0;
  std::cin >> select;
  if (select == 1) {
    int id;
    std::cout << "Please enter the employee number you are looking for: " << std::endl;
    std::cin >> id;
    int search1 = IsExist1(id);
    if (search1 != -1) {
      std::cout << "The search is successful. The employee information is as follows: " << std::endl;
      this->_EmpArray[search1]->showInformation();
    }
    else {
      std::cout << "Failed to search for this staff's information" << std::endl; 
    }
  }
  if (select == 2) {
    std::string name;
    std::cout << "Please enter the name of the staff you want to find" << std::endl;
    std::cin >> name;
    bool search2 = IsExist2(name);
    if (search2 == true) {
      std::cout << "The search is successful. The employee information is as follows: " << std::endl;
      this->_EmpArray[search2]->showInformation();
    }
    else {
      std::cout << "Failed to search for this staff's information" << std::endl; 
    }
  }
}
 void Management::Sort_Staff() {

 }

void Management::Show_menu() {
  std::cout << "*********************************************************"
            << std::endl;
  std::cout << "********Welcome to the employee management system********"
            << std::endl;
  std::cout << "***********0.Exit the management page********************"
            << std::endl;
  std::cout << "***********1.Add the employee information****************"
            << std::endl;
  std::cout << "***********2.Display the employee information************"
            << std::endl;
  std::cout << "***********3.Delete the employee information*************"
            << std::endl;
  std::cout << "***********4.Modify the employee information************"
            << std::endl;
  std::cout << "***********5.Search the employee information************"
            << std::endl;
  std::cout << "***********6.Sort by number*****************************"
            << std::endl;
  std::cout << "Please enter the numbers 0 through 6 as your next step "
            << std::endl;
  int choice = 10;
  while (choice != 0) {
    std::cin >> choice;
    switch (choice) {
      case 0:  // if choice is euqal to 0, the programming will be end
        ExitSystem();
        exit;
        break;
      case 1:  // if choice is euqal to 1, the management should add employees
        Add_Staff();
        Show_menu();
        break;
      case 2:  // if choice is euqal to 2, the management should display the
               // information of employees
        Display_Staff();
        Show_menu();
        break;
      case 3:
        Delete_Staff();  // if choice is euqal to 3, the management should delete the
        Show_menu();       // information of employees
        break;
      case 4:  // if choice is euqal to 4, the management should modify the
               // information of employees
        break;
      case 5:
        Search_Staff();  // if choice is euqal to 5, the management should search the
        Show_menu();       // information of employees
        break;
      case 6:  // if choice is euqal to 5, the management should sort by number
        break;
      default:
        std::cout << "Invalid number" << std::endl;
        // system("cls"); // Screen clearing operations
        break;
    }
  }
}

Management::~Management() {
  if (this->_EmpArray != NULL) {
    delete[] this->_EmpArray;
    this->_EmpArray = NULL;
  }
}
