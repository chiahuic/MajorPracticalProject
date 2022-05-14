#ifndef WORKER_H
#define WORKER_H

#include <string>

class Worker 
{
    public:
        virtual std::string getDepartName() = 0; // show job title
        virtual void showInformation() = 0; // display information of workers
        
    protected:
        int _ID; // individual numbers of workers
        std::string _Name; // name of workers
        int _Age; // Age of workers    
};

#endif