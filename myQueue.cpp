#include "myQueue.h"
using namespace std;

 vector<Employee> & myQueue::getElts()  { return elts; }

// overloads implementation
myQueue myQueue::operator+( myQueue& other)  {
    myQueue temp = *this;
    for ( auto &emp : other.getElts()) {
        temp.Enqueue(emp);
    }
    return temp;
}

// Enqueue() implementation
void myQueue::Enqueue( Employee& emp) { elts.push_back(emp); }

// Dequeue() implementation
Employee myQueue::Dequeue() {
    if (!isEmpty()) {
        Employee front = elts.front();
        elts.erase(elts.begin());
        return front;
    }
    return Employee();
}

bool myQueue::isEmpty() 
{
    return elts.empty();
}

void myQueue::printQueue() 
{
    for ( auto &emp : elts) {
        cout << emp << endl;
    }
}
