#include "Employee.h"
using namespace std;

// default constructor
Employee::Employee(): firstName(""), lastName(""), socsecnum(""), deptNum(""), wage(0.0) {}

// constructor taking 5 arguments
Employee::Employee(string fName, string lName, string ssn, string dept, double w):
        firstName(fName), lastName(lName), socsecnum(ssn), deptNum(dept), wage(w) {}

// Setters
void Employee::setFirstName(string fName) { firstName = fName; }
void Employee::setLastName(string lName) { lastName = lName; }
void Employee::setSocSecNum(string ssn) { socsecnum = ssn; }
void Employee::setDeptNum(string dept) { deptNum = dept; }
void Employee::setWage(double w) { wage = w; }

// Getters
string Employee::getFirstName() const { return firstName; }
string Employee::getLastName() const { return lastName; }
string Employee::getSocSecNum() const { return socsecnum; }
string Employee::getDeptNum() const { return deptNum; }
double Employee::getWage() const { return wage; }

// make it like output format
ostream & operator<<(ostream & out,  Employee & E) {
    out << E.lastName << " " << E.firstName << " " << E.socsecnum << " " << E.deptNum << " " << E.wage;
    return out;
}

// implementation for overloads <
bool Employee::operator<(const Employee & other) const {
    if (deptNum != other.deptNum)
        return deptNum < other.deptNum;
    if (lastName != other.lastName)
        return lastName < other.lastName;
    return firstName < other.firstName;
}
