#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string firstName;
    string lastName;
    string socsecnum;
    string deptNum;
    double wage;

public:
    Employee();
    Employee(string fName, string lName, string ssn, string dept, double w);

    // Setters
    void setFirstName(string fName);
    void setLastName(string lName);
    void setSocSecNum(string ssn);
    void setDeptNum(string dept);
    void setWage(double w);

    // Getters
    string getFirstName() const;
    string getLastName() const;
    string getSocSecNum() const;
    string getDeptNum() const;
    double getWage() const;


    // output operator
    friend ostream& operator<<(ostream& out, const Employee& E);
    // < overloads
    bool operator<(const Employee& other) const;
};

#endif
