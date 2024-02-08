#include "myQueue.h"
using namespace std;

const vector<Employee> & myQueue::getElts() const { return elts; }

// overloads implementation
myQueue myQueue::operator+(const myQueue& other) const {
    myQueue temp = *this;
    for (const auto &emp : other.getElts()) {
        temp.Enqueue(emp);
    }
    return temp;
}

// Enqueue() implementation
void myQueue::Enqueue(const Employee& emp) { elts.push_back(emp); }

// Dequeue() implementation
Employee myQueue::Dequeue() {
    if (!isEmpty()) {
        Employee front = std::move(elts.front());
        elts.erase(elts.begin());
        return front;
    }
    return Employee();
}

bool myQueue::isEmpty() const {
    return elts.empty();
}

void myQueue::printQueue() const {
    for (const auto &emp : elts) {
        cout << emp << endl;
    }
}
