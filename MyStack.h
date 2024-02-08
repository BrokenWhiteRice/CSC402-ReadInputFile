#ifndef MYSTACK_H
#define MYSTACK_H

#include "Employee.h"
#include <vector>
using namespace std;


class myStack {
private:
    vector<Employee> elts;
public:
    const vector<Employee> & getElts() const;
    void Push(Employee emp);
    Employee Pop();
    bool isEmpty() const;
    void printStack() const;
    myStack operator+(const myStack& other) const;
};

#endif
