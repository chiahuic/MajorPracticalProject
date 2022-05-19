#include "Management.h"

#include <iostream>
#include <algorithm>
#include <cctype> // allowed to use isalpha
#include <climits> // allowed to use INT_MAX

Management::Management() {
  this->_StaffNumber = 0;    // initialized to zero
  this->_StaffArray = NULL;  // empty array
}

void Management::ExitSystem() {
  std::cout << "Welcome to use system again" << std::endl;
}

void Management::Add_Staff() {
  std::cout << "Please enter the number of staffs you want to add: " << std::endl;
  int addNum = 0;  // saves the amount entered by the user
  std::cin >> addNum;
  while (addNum <= 0 || addNum >= 50) {
    std::cout << "Invaild number. Please try again" << std::endl;
    std::cout << "Please enter the number of staffs you want to add: " << std::endl;
    std::cin.clear(); // clear error enter
    std::cin.ignore(INT_MAX, '\n'); // INT_MAX means an extremely large number,'\n' means empty space
    std::cin >> addNum;
  }
  
    int new_Size = this->_StaffNumber + addNum;  // The number of existing employees plus
                                      // the number of new employees
    Person** new_Space = new Person*[new_Size];  // Open up new space
    if (this->_StaffArray !=
        NULL)  // if the data of the original pointer is not null
    {
      for (int i = 0; i < this->_StaffNumber;
           i++)  // data of the original pointer is added to the new pointer
      {
        new_Space[i] = this->_StaffArray[i];
      }
    }

    for (int i = 0; i < addNum; i++) {
      int ID;  // create an variable nameed id to store the staff number entered
               // from users           
      std::cout << "Please enter pure and positive number as the staff number of " << i + 1 << " staff: " << std::endl;
      std::cin >> ID;
      while (ID <= 0) {
        std::cout << "Invalid staff number, please enter again: " << std::endl;
        std::cin.clear(); 
        std::cin.ignore(INT_MAX, '\n'); 
        std::cin >> ID;
      }
      std::string NAME;  // create an variable nameed id to store the staff
                         // number entered from users
      std::cout << "Please enter the name: " << std::endl;
      // std::cin >> NAME;
      while (std::getline(std::cin, NAME)) {
        if (NAME.length() == 0)
        {
            std::cout << "Your input is not correct. Please re-enter your name" << std::endl;
        }

        // This will check if the NAME contains only characters.
        else if (std::all_of(NAME.begin(), NAME.end(), isalpha)) // isalpha: The function returns a non-zero value if the argument is an alphabetic character, or zero otherwise.
        {
            break;
        }
        else {
            std::cout << "Only characters are allowed:" << std::endl;
        }
    }
      int AGE;
      std::cout << "Please enter the age: " << std::endl;
      std::cin >> AGE;
      while (AGE <= 0 && AGE >= 150) {
        std::cout << "Invalid number, please enter again: " << std::endl;
        std::cin.clear(); 
        std::cin.ignore(INT_MAX, '\n');
        std::cin >> AGE;
      }
      int Select;
      std::cout << "Please choose job title(enter 1 or 2)" << std::endl;
      std::cout << "1. Employee" << std::endl;
      std::cout << "2. Manager" << std::endl;
      std::cin >> Select;
      while (Select > 2 && Select < 1) {
        std::cout << "Invalid number, choose 1 or 2 please" << std::endl;
        std::cin.clear(); 
        std::cin.ignore(INT_MAX, '\n');
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
      new_Space[this->_StaffNumber + i] = staff;
    }

    delete[] this->_StaffArray;     // delete the initial array
    this->_StaffArray = new_Space;  // update a new array
    this->_StaffNumber = new_Size;  // update the current number of staffs
    std::cout << "Add successful" << std::endl;
  }
void Management::Display_Staff() {
  std::cout << "====================================" << std::endl;
  if (_StaffArray != NULL) {
    for (int i = 0; i < this->_StaffNumber; i++) {
      // std::cout << _EmpArray[i]->showInformation() << std::endl;
      this->_StaffArray[i]->showInformation();
    }
    std::cout << "====================================" << std::endl;
  }
  else{
    std::cout << "There are no any current staffs in the system" << std::endl;
    std::cout << "====================================" << std::endl;
  }
}
int Management::IsExist1(int id) {
  int index = -1;
  for (int i = 0; i < _StaffNumber; i++) {
    if (this->_StaffArray[i]->_Id == id) {
      index = i;
      break;
    }
  }
  return index;
}
bool Management::IsExist2(std::string name) {
  for (int i = 0; i < _StaffNumber; i++) {
    if (this->_StaffArray[i]->_Name == name) {
      return true;
      break;
    }
  }
  return false;
}
void Management::Delete_Staff() {
  std::cout << "Please enter the number of the staff you want to delete: "
            << std::endl;
  int id = 0;
  std::cin >> id;
  int index_check = this->IsExist1(id);

  if (index_check != -1) {  // it means the staff exist, and need delete
    delete this->_StaffArray[index_check];
    Person** new_persons = new Person*[_StaffNumber-1];
    for (int i = index_check; i < _StaffNumber - 1; i++) {
      std::cout << "Delete successfully" << std::endl;
      new_persons[i] = this->_StaffArray[i + 1];
    }
    this->_StaffNumber--;  // number of staff decrease
    delete[] this->_StaffArray;
    this->_StaffArray = new_persons;
  } else {
    std::cout << "Deletion failed, the staff could not be found." << std::endl;
  }
}

void Management::Modify_Staff() {
  std::cout << "Please enter the staff number of the employee whose information you "
               "want to modify: "
            << std::endl;
  int id = 0;
  std::cin >> id;
  int modify = this->IsExist1(id);
  if (modify != -1) {
    delete this->_StaffArray[modify];
    std::cout << "Have found the staff that staff number is " << id << std::endl;
    std::cout << "Please enter the modified information" << std::endl;
    int new_id = 0;
    int new_select = 0;
    std::cout << "new staff number: " << std::endl;
    std::cin >> new_id;
    std::string new_name = "";
    std::cout << "new name is : " << std::endl;
    std::cin >> new_name;
    int new_age = 0;
    std::cout << "new age is : " << std::endl;
    std::cin >> new_age;
    std::cout << "new job title is: " << std::endl;
    std::cout << "1. Employee" << std::endl;
    std::cout << "2. Manager" << std::endl;
    std::cin >> new_select;
    Person* person = NULL;
    switch (new_select) {
        case 1:
          person = new Employee(new_id, new_name, new_age);
          break;
        case 2:
          person = new Manager(new_id, new_name, new_age);
          break;
        default:
          std::cout << "Error choosen" << std::endl;
          break;
      }
    // update new data  
    this->_StaffArray[modify] = person;
    std::cout << "The information has been modified successfully." << std::endl;
    
  }
  else {
    std::cout << "Failed to find staff who have staff number " << id << std::endl;
  }
}

void Management::Search_Staff() {
  std::cout << "Please select a query mode" << std::endl;
  std::cout << "1. staff number" << std::endl;
  std::cout << "2. staff name" << std::endl;
  int select = 0;
  std::cin >> select;
  if (select == 1) {
    int id;
    std::cout << "Please enter the employee number you are looking for: "
              << std::endl;
    std::cin >> id;
    int search_id = IsExist1(id);
    if (search_id != -1) {
      std::cout << "The search is successful. The employee information is as "
                   "follows: "
                << std::endl;
      this->_StaffArray[search_id]->showInformation();
    } else {
      std::cout << "Failed to search for this staff's information" << std::endl;
    }
  }
  if (select == 2) {
    std::string name;
    std::cout << "Please enter the name of the staff you want to find"
              << std::endl;
    std::cin >> name;
    bool search_name = IsExist2(name);
    if (search_name == true) {
      std::cout << "The search is successful. The employee information is as "
                   "follows: "
                << std::endl;
      this->_StaffArray[search_name]->showInformation();
    } else {
      std::cout << "Failed to search for this staff's information" << std::endl;
    }
  }
}
void Management::Sort_Staff() {
  if (_StaffArray != NULL) {
    for (int i = 0; i < _StaffNumber; i++) {
      int min_max = i;
      for (int j = i + 1; j < _StaffNumber; j++) {
        if (_StaffArray[min_max]->_Id > _StaffArray[j]->_Id) {
          min_max = j;
        }
      }
      if (i != min_max) {
        Person* temp = _StaffArray[i];
        _StaffArray[i] = _StaffArray[min_max];
        _StaffArray[min_max] = temp;
      }
    }
    std::cout << "Sorting success" << std::endl;
  } else {
    std::cout << "Don't need to arrange" << std::endl;
  }
}

void Management::Show_menu() {
  // The initial interface of the management system
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
}

void Management::Run_System() {
  Show_menu();
  int choice = 10;
  while (choice != 0) {
    std::cin >> choice;
    switch (choice) {
      case 0:  // if choice is euqal to 0, the programming will be end
        ExitSystem();
        break;
      case 1:  // if choice is euqal to 1, the management should add employees
        Add_Staff();
        break;
      case 2:  // if choice is euqal to 2, the management should display the
               // information of employees
        Display_Staff();
        break;
      case 3:
        Delete_Staff();  // if choice is euqal to 3, the management should delete the information of employees
        break;
      case 4:
        Modify_Staff();  // if choice is euqal to 4, the management should modify theinformation of employees
        break;
      case 5:
        Search_Staff();  // if choice is euqal to 5, the management should search the information of staffs
        break;
      case 6:
        Sort_Staff();  // if choice is euqal to 5, the management should sort by number
        break;
      default:
        std::cout << "Invalid number" << std::endl;
        // system("cls"); // Screen clearing operations
        break;
    }
    if (choice == 0) { // if choice is euqal to zero, it doesn't need to show menu
      return;
    }
    else {
      Show_menu();
    }
  }
}
Management::~Management() {
  if (this->_StaffArray != NULL) {
    delete[] this->_StaffArray;
    this->_StaffArray = NULL;
  }
}
