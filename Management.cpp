#include <iostream>

#include "Management.h"


Management::Management() 
{
    this->Emp_number = 0;
    this->_EmpArray = NULL;
}


void Management::ExitSystem() 
{
    std::cout<<"Welcome to use system again" << std::endl;
}

void Management::Add_Staff() 
{
    std::cout << "Please enter the number of staffs you want to add" << std::endl;
    int addNum = 0; // saves the amount entered by the user
    std::cin >> addNum;

    if (addNum > 0) 
    {
        int new_Size = this->Emp_number + addNum;  // The number of existing employees plus the number of new employees
        Worker** new_Space = new Worker*[new_Size]; // Open up new space
        if (this->_EmpArray != NULL) // if the data of the original pointer is not null
        {
            for (int i = 0; i < this->Emp_number; i++) // data of the original pointer is added to the new pointer
            {
                new_Space[i] = this->_EmpArray[i];
            }
        }

        for (int i = 0; i < addNum; i++) 
        {
            int ID;
            std::string NAME;
            int AGE;
            int Select;
            std::cout << "Please enter pure number as the staff number of " << i+1 <<" staff: " <<std::endl;
            std::cin >> ID;
            while (ID < 0) 
            {
                std::cout << "Invalid staff number, please enter again: " << std::endl;
                std::cin >> AGE;
            }
            std::cout << "Please enter the name: " << std::endl;
            std::cin >> NAME;
            while (NAME.length() == 0) 
            {
                std::cout<< "Name must be added. Please enter it again" << std::endl;
                std::cin >> NAME;
            }
            std::cout << "Please enter the age: " << std::endl;
            std::cin >> AGE;
            while (AGE <= 0) 
            {
                std::cout << "Invalid number, please enter again: " << std::endl;
                std::cin >> AGE;
            }
            std::cout << "Please choose job title(enter 1 or 2)" << std::endl;
            std::cout << "1. Employee" << std::endl;
            std::cout << "2. Manager" << std::endl;
            std::cin >> Select;
            Worker* staff = NULL;
            switch (Select) 
            {
                case 1:
                    staff = new Employee(ID,NAME,AGE);
                    break;
                case 2:
                    staff = new Manager(ID,NAME,AGE);
                    break;
                default:
                    std::cout << "Error choosen" << std::endl;
                    break;
            }
            new_Space[this->Emp_number+i] = staff;

        }

        delete [] this->_EmpArray; // delete the initial array
        this->_EmpArray = new_Space; // update a new array
        this->Emp_number = new_Size; // update the current number of staffs
        std::cout << "Add successful" << std::endl;
    }
    else 
    {
        std::cout << "Invalid number." << std::endl; 
    }
    
}
// void Management::Display_Staff() 
// {
//     if (!_EmpArray == NULL) 
//     {

//     }
// }

void Management::Show_menu() 
{
    std::cout <<"*********************************************************" << std::endl;
    std::cout <<"********Welcome to the employee management system********" << std::endl;
    std::cout <<"***********0.Exit the management page********************" << std::endl;
    std::cout <<"***********1.Add the employee information****************" << std::endl;
    std::cout <<"***********2.Display the employee information************" << std::endl;
    std::cout <<"***********3.Delete the employee information*************" << std::endl;
    std::cout <<"***********4.Modify the employee information************" << std::endl;
    std::cout <<"***********5.Search the employee information************" << std::endl;
    std::cout <<"***********6.Sort by number*****************************" << std::endl;
    std::cout << "Please enter the numbers 0 through 6 as your next step "<< std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 0: // if choice is euqal to 0, the programming will be end
            ExitSystem(); 
            break;
        case 1: // if choice is euqal to 1, the management should add employees
            Add_Staff();
            break;
        case 2: // if choice is euqal to 2, the management should display the information of employees
            break;
        case 3: // if choice is euqal to 3, the management should delete the information of employees
            break;
        case 4: // if choice is euqal to 4, the management should modify the information of employees
            break;
        case 5: // if choice is euqal to 5, the management should search the information of employees
            break;
        case 6: // if choice is euqal to 5, the management should sort by number
            break;
        default:
            std::cout<<"Invalid number" << std::endl;
            // system("cls"); // Screen clearing operations
            break;
    }
   
    

}



Management::~Management() 

{

}