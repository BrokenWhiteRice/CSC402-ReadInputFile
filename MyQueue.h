#ifndef MYQUEUE_H
#define MYQUEUE_H

#include "Employee.h"
#include <vector>
using namespace std;


class myQueue {
private:
    vector<Employee> elts;
public:
    const vector<Employee> & getElts() const;
    myQueue operator+(const myQueue& other) const;
    void Enqueue(const Employee& emp);  // insert function
    Employee Dequeue();  // remove function
    bool isEmpty() const;
    void printQueue() const;
};

#endif
