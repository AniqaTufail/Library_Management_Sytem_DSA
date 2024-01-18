#pragma once
#include <iostream>
using namespace std;

// Needed for Accessing Global Hashtable Objects
#include "../dataStructures/hashtable.h"

// Needed for Accessing Student Class
#include "student.h"

void makeNewStudent()
{
    int id;
    string fname;
    string lname;
    int age;
    string email;
    cout << "Enter ID: " << endl;
    cin >> id;
    cout << "Enter First Name: " << endl;
    cin >> fname;
    cout << "Enter Last Name: " << endl;
    cin >> lname;
    cout << "Enter Age: " << endl;
    cin >> age;
    cout << "Enter Email: " << endl;
    cin >> email;
    student *newstudent = new student;
    newstudent->id = id;
    newstudent->firstName = fname;
    newstudent->lastName = lname;
    newstudent->age = age;
    newstudent->email = email;
    studentTable.insertIntoHashTable(newstudent, id);

    writeStudent(newstudent);
}

void deleteStudent()
{
    int id;
    cout << "Enter ID: ";
    cin >> id;
    bool deleted = studentTable.deleteFromHashTable(id);

    if (deleted)
    {
        cout << "The Student has been deleted " << endl;
    }
    else
    {
        cout << "Student not found!! " << endl;
    }

    unWriteStudent(id);
}

void findStudentbyID()
{
    int id;
    cout << "Enter ID: " << endl;
    cin >> id;
    student *ptr = studentTable.getFromHashTable(id);
    if (ptr == NULL)
    {
        cout << "Student not Found!!" << endl;
    }
    else
    {
        cout << *ptr;
    }
}

void findStudentbyName()
{
    string name;
    cout << "Enter name: " << endl;
    cin >> name;

    for (char &c : name)
    {
        c = tolower(c);
    }

    for (int i = 0; i < studentTable.capacity; i++)
    {
        if (studentTable.arr[i] != NULL)
        {
            student *loc = studentTable.arr[i];
            while (loc != NULL)
            {
                string fullname = loc->firstName + loc->lastName;
                for (char &c : fullname)
                {
                    c = tolower(c);
                }

                size_t found = fullname.find(name);

                if (found != string::npos)
                {
                    cout << *loc;
                }

                loc = loc->next;
            }
        }
    }
}

void editStudentbyID()
{
    int id;
    string fname;
    string lname;
    string email;
    int age;
    cout << "Enter ID: ";
    cin >> id;
    student *ptr = studentTable.getFromHashTable(id);

    cout << *ptr;

    cout << "Enter new First Name: " << endl;
    cin >> fname;
    cout << "Enter new Last Name: " << endl;
    cin >> lname;
    cout << "Enter new Age: " << endl;
    cin >> age;
    cout << "Enter new Email: " << endl;
    cin >> email;
    ptr->id = id;
    ptr->firstName = fname;
    ptr->lastName = lname;
    ptr->age = age;
    ptr->email = email;


    cout << "Edited: " <<endl;
    cout << *ptr;

    unWriteStudent(id);
    writeStudent(ptr);
}

void showAllStudents()
{
    studentTable.printAll();
}
