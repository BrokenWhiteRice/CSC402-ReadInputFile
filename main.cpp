#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// KEY CLASS
class Employee {
private:
    string firstName;
    string lastName;
    string socsecnum;
    string deptNum;
    double wage;
public:
    // Default constructor
    Employee(): firstName(""), lastName(""), socsecnum(""), deptNum(""), wage(0.0) {}
    Employee(string fName, string lName, string ssn, string dept, double w): firstName(fName), lastName(lName), socsecnum(ssn), deptNum(dept), wage(w) {}

    // Setters
    void setFirstName(string fName) { firstName = fName; }
    void setLastName(string lName) { lastName = lName; }
    void setSocSecNum(string ssn) { socsecnum = ssn; }
    void setDeptNum(string dept) { deptNum = dept; }
    void setWage(double w) { wage = w; }

    // Getters
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getSocSecNum() const { return socsecnum; }
    string getDeptNum() const { return deptNum; }
    double getWage() const { return wage; }

    friend ostream & operator<<(ostream & out, const Employee & E); // PUT THIS in MAIN
    bool operator<(const Employee & other) const;
};

ostream & operator<<(ostream & out, const Employee & E) {
    out << E.getLastName() << " " << E.getFirstName() << " " << E.getSocSecNum() << " " << E.getDeptNum() << " " << E.getWage();
    return out;
}

bool Employee::operator<(const Employee & other) const {
    if (deptNum != other.deptNum)
        return deptNum < other.deptNum;
    if (lastName != other.lastName)
        return lastName < other.lastName;
    return firstName < other.firstName;
}

class myStack {
private:
    vector<Employee> elts;
public:
    const vector<Employee> & getElts() const { return elts; } // Marked as const
    void Push(Employee emp) { elts.push_back(emp); }
    Employee Pop();
    bool isEmpty() const { return elts.empty(); }
    void printStack() const;

    myStack operator+(const myStack& other) const; // Marked as const
};



Employee myStack::Pop() {
    if (!isEmpty()) {
        Employee top = elts.back();
        elts.pop_back();
        return top;
    }
    // You might want to throw an exception here for an empty stack
    return Employee();
}

void myStack::printStack() const {
    for (auto it = elts.rbegin(); it != elts.rend(); ++it) {
        cout << *it << endl;
    }
}

myStack myStack::operator+(const myStack& other) const {
    myStack temp = *this;
    for (const auto &emp : other.getElts()) { // getElts() is called on a const object, so it needs to be a const function
        temp.Push(emp);
    }
    return temp;
}


class myQueue {
private:
    vector<Employee> elts;
public:
    const vector<Employee> & getElts() const { return elts; } // Marked as const
    void Enqueue(const Employee& emp) { elts.push_back(emp); } // corrected Enqueue method
    Employee Dequeue();
    bool isEmpty() const { return elts.empty(); }
    void printQueue() const;

    myQueue operator+(const myQueue& other) const; // Marked as const
};

Employee myQueue::Dequeue() {
    if (!isEmpty()) {
        Employee front = elts.front();
        elts.erase(elts.begin());
        return front;
    }
    // You might want to throw an exception here for an empty queue
    return Employee();
}

void myQueue::printQueue() const {
    for (const auto &emp : elts) {
        cout << emp << endl;
    }
}

myQueue myQueue::operator+(const myQueue& other) const {
    myQueue temp = *this;
    for (const auto &emp : other.getElts()) { // getElts() is called on a const object, so it needs to be a const function
        temp.Enqueue(emp);
    }
    return temp;
}

int main() {
    return 0;
}
