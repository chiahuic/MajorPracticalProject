#ifndef MANAGER_H
#define MANAGER_H

#include "Worker.h"

// Management personnel class
class Manager: public Worker 
{
    public:
        Manager(int id, std::string name, int age); // constructor with three basic parameters
        virtual std::string getDepartName() override; // show job title
        virtual void showInformation() override; // display the information of manager

~Manager();
};

#endif // MANAGER_H
