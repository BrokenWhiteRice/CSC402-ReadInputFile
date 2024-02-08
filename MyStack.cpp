#include "myStack.h"
using namespace std;

const vector<Employee> & myStack::getElts() const { return elts; }

void myStack::Push(Employee emp) { elts.push_back(emp); }

Employee myStack::Pop() {
    if (!isEmpty()) {
        Employee top = elts.back();
        elts.pop_back();
        return top;
    }
    return Employee();
}

bool myStack::isEmpty() const {
    return elts.empty();
}

void myStack::printStack() const {
    for (int i = elts.size() - 1; i >= 0; --i) {
        cout << elts[i] << endl;
    }
}

myStack myStack::operator+(const myStack& other) const {
    myStack temp = *this;
    for (const Employee& emp : other.getElts()) {
        temp.Push(emp);
    }
    return temp;
}
