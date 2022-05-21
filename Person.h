#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
 public:
 virtual std::string getDepartName() = 0;  // show job title
 virtual void showInformation() = 0;       // display information of persons
 virtual int WorkTime();                   // person's working time range
 int _Id;                                  // individual numbers of persons
 std::string _Name;                        // name of persons
 int _Age;                                 // Age of persons
};

#endif
