#include "myStack.h"
using namespace std;

vector<Employee> & myStack::getElts()  { return elts; }

void myStack::Push(Employee emp) { elts.push_back(emp); }

Employee myStack::Pop() {
    if (!isEmpty()) {
        Employee top = elts.back();
        elts.pop_back();
        return top;
    }
    return Employee();
}

bool myStack::isEmpty()  {
    return elts.empty();
}

void myStack::printStack()  {
    for (int i = elts.size() - 1; i >= 0; --i) {
        cout << elts[i] << endl;
    }
}

myStack myStack::operator+( myStack& other)  {
    myStack temp = *this;
    for ( Employee& emp : other.getElts()) {
        temp.Push(emp);
    }
    return temp;
}
