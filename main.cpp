#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

#include "Employee.h"
#include "myStack.h"
#include "myQueue.h"


using namespace std;

// open and read from a datafile, path entered by user
int main() {
    // create myStack and myQueue obj
    myStack S1;
    myQueue Q1;
    // file inputs
    string path1, path2;
    ifstream file1(path1), file2(path2);

    // open and read the file
    cout << "Please enter a path for file #1: ";
    cin >> path1;
    cout << "Please enter a path for file #2: ";
    cin >> path2;

    // create variable for the form
    string lName, fName, ssn, dept;
    double wage;

    // Read file1 to the end
    while (file1 >> lName >> fName >> ssn >> dept >> wage) {
        // create 2 Employee records
        Employee emp1(fName, lName, ssn, dept, wage);
        Employee emp2(fName, lName, ssn, dept, wage);

        S1.Push(emp1);
        Q1.Enqueue(emp2);
    }
    file1.close();

    // create myStack and myQueue obj
    myStack S2;
    myQueue Q2;
    // Read file #2
    while (file2 >> lName >> fName >> ssn >> dept >> wage) {
        // create 2 Employee records
        Employee emp1(fName, lName, ssn, dept, wage);
        Employee emp2(fName, lName, ssn, dept, wage);

        S2.Push(emp1);
        Q2.Enqueue(emp2);
    }
    // Close the second input file
    file2.close();

    // Print stack #1
    cout << "STACK #1" << endl;
    cout << "_______" << endl;
    S1.printStack();
    cout << endl;

    // Print queue #1
    cout << "QUEUE #1" << endl;
    cout << "_______" << endl;
    Q1.printQueue();
    cout << endl;

    // Print stack #2
    cout << "STACK #2" << endl;
    cout << "_______" << endl;
    S2.printStack();
    cout << endl;

    // Print queue #2
    cout << "QUEUE #2" << endl;
    cout << "_______" << endl;
    Q2.printQueue();
    cout << endl;

    // Sort S1 and S2
    sort(S1.getElts().begin(), S1.getElts().end(), less<Employee>());
    sort(S2.getElts().begin(), S2.getElts().end(), less<Employee>());

    // Sort Q1 and Q2
    sort(Q1.getElts().begin(), Q1.getElts().end(), less<Employee>());
    sort(Q2.getElts().begin(), Q2.getElts().end(), less<Employee>());

    // Print sorted S1
    cout << "Sorted Stack #1:" << endl;
    cout << "_______" << endl;
    S1.printStack();
    cout << endl;

    // Print sorted Q1
    cout << "Sorted Queue #1:" << endl;
    cout << "_______" << endl;
    Q1.printQueue();
    cout << endl;

    // Print sorted S2
    cout << "Sorted Stack #2:" << endl;
    cout << "_______" << endl;
    S2.printStack();
    cout << endl;

    // Print sorted Q2
    cout << "Sorted Queue #2:" << endl;
    cout << "_______" << endl;
    Q2.printQueue();
    cout << endl;

    // Create stack and queue for third obj
    myStack S3;
    myQueue Q3;
    // Create S3 and Q3 by adding S1 and S2, Q1 and Q2 respectively
    S3 = S1 + S2;
    Q3 = Q1 + Q2;

    // Print myStack S3
    cout << "STACK #3" << endl;
    cout << "_______" << endl;
    S3.printStack();

    // Print myQueue Q3
    cout << "QUEUE #3" << endl;
    cout << "_______" << endl;
    Q3.printQueue();

    // Sort myStack S3
    sort(S3.getElts().begin(), S3.getElts().end(),less<Employee>());

    // Sort myQueue Q3
    sort(Q3.getElts().begin(), Q3.getElts().end(), less<Employee>());

    // Print sorted myStack S3
    cout << "After sorting STACK #3" << endl;
    cout << "_______" << endl;
    S3.printStack();

    // Print sorted Q3
    cout << "After sorting QUEUE #3" << endl;
    cout << "_______" << endl;
    Q3.printQueue();

    // Pop all items from S2
    cout << "Items POPPED from Stack S2" << endl;
    while (!S2.isEmpty()) {
        Employee emp = S2.Pop();
        cout << "POPPING " << emp << endl;
    }

    // try to print now empty
    S2.printStack(); // This may produce an error message if S2 is empty

    // Dequeue all elements from Q2
    cout << "Items DEQUEUED from Queue Q2" << endl;
    while (!Q2.isEmpty()) {
        Employee emp = Q2.Dequeue();
        cout << "DEQUEUEING " << emp << endl;
    }

    // try to print now empty
    Q2.printQueue(); // This may produce an error message if Q2 is empty

    // Print an appropriate exit message
    cout << "Program execution complete." << endl;

    return 0;
}
