#pragma once

#include "Employee.h"
#include <vector>
using namespace std;


class myQueue {
private:
    vector<Employee> elts;
public:
    vector<Employee> & getElts() ;
    myQueue operator+( myQueue& other) ;
    void Enqueue( Employee& emp);  // insert function
    Employee Dequeue();  // remove function
    bool isEmpty() ;
    void printQueue() ;
};


