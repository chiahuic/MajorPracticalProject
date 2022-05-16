#include <iostream>

#include "Management.h"
using namespace std;


Management::Management() 
{
    ifstream ifs;
    char ex;
    ifs >> ex;
    ifs.open(FILENAME, ios::in);//read file
    //if file not exit
    if(!ifs.is_open()){
        cout<<"File not exit"<<endl;
        this->Emp_number = 0;
        this->_EmpArray = NULL;
        this->FileIsEmpty = true;
        ifs.close():
        return;
    }
    //have file but no data
    if(ifs.eof(){
        cout<<"File is empty!"<<endl;
        this->Emp_number = 0;
        this->_EmpArray = NULL;
        this->FileIsEmpty = true;
        ifs.close():
        return;
    }
    //have file and data
    int num = this->get_EmpNumber():
    cout<<"Number of worker is:"<<num<<endl;
    this->Emp_number = num;
}


void Management::ExitSystem() 
{
    cout<<"Welcome to use system again" << endl;
}

void Management::Add_Staff() 
{
    cout << "Please enter the number of staffs you want to add" << endl;
    int addNum = 0; // saves the amount entered by the user
    cin >> addNum;

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
            string NAME;
            int AGE;
            int Select;
            cout << "Please enter pure number as the staff number of " << i+1 <<" staff: " <<endl;
            cin >> ID;
            while (ID < 0) 
            {
                cout << "Invalid staff number, please enter again: " << endl;
                cin >> AGE;
            }
            cout << "Please enter the name: " << endl;
            cin >> NAME;
            while (NAME.length() == 0) 
            {
                cout<< "Name must be added. Please enter it again" << endl;
                cin >> NAME;
            }
            cout << "Please enter the age: " << endl;
            cin >> AGE;
            while (AGE <= 0) 
            {
                cout << "Invalid number, please enter again: " << endl;
                cin >> AGE;
            }
            cout << "Please choose job title(enter 1 or 2)" << endl;
            cout << "1. Employee" << endl;
            cout << "2. Manager" << endl;
            cin >> Select;
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
                    cout << "Error choosen" << endl;
                    break;
            }
            new_Space[this->Emp_number+i] = staff;

        }

        delete [] this->_EmpArray; // delete the initial array
        this->_EmpArray = new_Space; // update a new array
        this->Emp_number = new_Size; // update the current number of staffs
        this->FileIsEmpty = false;
        cout << "Add successful" << endl;
        this->save();
    }
    else 
    {
        cout << "Invalid number." << endl; 
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
    cout <<"*********************************************************" << endl;
    cout <<"********Welcome to the employee management system********" << endl;
    cout <<"***********0.Exit the management page********************" << endl;
    cout <<"***********1.Add the employee information****************" << endl;
    cout <<"***********2.Display the employee information************" << endl;
    cout <<"***********3.Delete the employee information*************" << endl;
    cout <<"***********4.Modify the employee information************" << endl;
    cout <<"***********5.Search the employee information************" << endl;
    cout <<"***********6.Sort by number*****************************" << endl;
    cout << "Please enter the numbers 0 through 6 as your next step "<< endl;
    int choice;
    cin >> choice;
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
            cout<<"Invalid number" << endl;
            // system("cls"); // Screen clearing operations
            break;
    }
   
    

}

int Managment::get_EmpNumber(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);//read file
    int ID;
    string NAME;
    int AGE;
    int num = 0;
    while(ifs >> ID && ifs >> NAME && ifs >> AGE){
        num++;
    }

}

void Management::save(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for(int i = 0; i < this->Emp_number; i++){
        ofs <<this->_EmpArray[i]->_ID<<" "
            <<this->_EmpArray[i]->_Name<<" "
            <<this->_EmpArray[i]->_Age<<endl;
    }
    ofs.close();
}

int Managment::IsExist(int id){
    int index = -1;
    for(int i = 0; i <this->Emp_number; i++){
        if(this->_EmpArray[i]->_ID == id){
            index = i;
            break;
        }
    }
    return index;
}

void Managment::Delete_Staff(){
    if(this->FileIsEmpty){
        cout<<"File not exit"<<endl;
    }
    else{
        cout<<"Enter ID want to delete:"<<endl;
        int id = 0;
        cin >> id;
        int index = this->IsExist(id);
        if(index != -1){
            for(int i = index; i < this->Emp_number; i++){
                this->_EmpArray[i] = this->_EmpArray[i+1];
            }
            this->Emp_number--;
            this->save();
            cout<<"delete"<<endl;
        }else{
            cout<<"fale to delete"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void Management::Modify_Staff(){
    if(this->FileIsEmpty){
        cout<<"file not exit"<<endl;
    }else{
        cout<<"enter modify id:"<<endl;
        int id;
        sdt::cin >> id;
        int ret = this->IsExist(id);
        if(ret != -1){
            delete this->_EmpArray[ret];
            int newID = 0;
            string newName = " ";
            int newAge = 0;
            int newSelect = 0;
            cout<<"check: "<<id<<"enter new id:"<<endl;
            cin >> newID;
            cout<<"Enter new name:"<<endl;
            cin >> newName;
            cout<<"Enter age:"<<endl;
            cin >> newAge;
            cout << "Please choose job title(enter 1 or 2)" << endl;
            cout << "1. Employee" << endl;
            cout << "2. Manager" << endl;
            cin >> newSelect;
            Worker * Worker = NULL;
            switch(newSelect){
                case 1:
                Worker = new Employee(newID,newName,newAge);
                break;
                case 2:
                Worker = new Manager(newID,newName,newAge);
                break;
                default:
                break;
            }
            this->_EmpArray[ret] = Worker;
            cout<<"Modify successfully"<<endl;
            this->save();
        }else{
            cout<<"To forgive"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void Management::Search_Staff(){
    if(this->FileIsEmpty){
        cout<<"file not exit"<<cout;
    }else{
        cout<<"Enter lookup:"<<endl;
        cout<<"1. ID"<<endl;
        cout<<"2. Name"<<endl;

        int Select = 0;
        cin >> Select;

        if(Select == 1){
            int id;
            cout<<"Enetr ID:"<<endl;
            cin >> id;

            int ret = IsExist(id);
            if(ret != -1){
                cout<<"The information is:"<<endl;
                this->_EmpArray[ret]->showInformation();
            }else{
                cout<<"ID is fales"<<endl;
            }
        }else if(Select == 2){
            string name;
            cout<<"Enter name:"<<endl;
            cin >> name;

            bool falg = false;
            for(int i = 0; i <Emp_number; i++){
                if(_EmpArray[i]->getDepartName == name){
                    cout<<"The information is:"<<_EmpArray[i]->showInformation()<<endl;
                    flag = true;
                    this->_EmpArray[i]->showInformation;
                }
            }
            if(falg == false){
                cout<<"no found"<<end;
            }
        }
        else{
                cout<<"To forgive"<<endl;
        }
    }
    system("pause");
    system("cls");
}


Management::~Management() {
  if (this->_EmpArray != NULL) {
    delete[] this->_EmpArray;
    this->_EmpArray = NULL;
  }
}