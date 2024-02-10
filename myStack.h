
#pragma once

#include "Employee.h"
#include <vector>
using namespace std;


class myStack {
private:
    vector<Employee> elts;
public:
    vector<Employee> & getElts() ;
    void Push(Employee emp);
    Employee Pop();
    bool isEmpty() ;
    void printStack() ;
    myStack operator+( myStack& other) ;
};

