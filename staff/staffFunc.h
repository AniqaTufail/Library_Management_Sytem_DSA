#pragma once
#include <iostream>
using namespace std;

// Needed for Accessing Global Hashtable Objects
#include "../dataStructures/hashtable.h"

// Needed for Accessing Staff Class
#include "staff.h"

#include "../parser/parser.h"


void addNewStaff()
{
    int id;
    string name;
    int age;
    string role;
    string contact;

    cout << "Enter ID: " << endl;
    cin >> id;
    cout << "Enter Name: " << endl;
    cin >> name;
    cout << "Enter Age: " << endl;
    cin >> age;
    cout << "Enter Role: " << endl;
    cin >> role;
    cout << "Enter Contact: " << endl;
    cin >> contact;
    staff* newstaff = new staff;
    newstaff->id = id;
    newstaff->staffName = name;
    newstaff->age = age;
    newstaff->staffRole = role;
    newstaff->contactNumber = contact;
    staffTable.insertIntoHashTable(newstaff, id);

    writeStaff(newstaff);

}

void deleteStaff()
{
    int id;
    cout << "Enter ID: ";
    cin >> id;
    bool deleted = staffTable.deleteFromHashTable(id);

    if (deleted)
    {
        cout << "The Staff has been deleted " << endl;
    }
    else
    {
        cout << "Staff not found!! " << endl;
    }

    unWriteStaff(id);
}

void findStaffbyID()
{
    int id;
    cout << "Enter ID: " << endl;
    cin >> id;
    staff *ptr = staffTable.getFromHashTable(id);
    if (ptr == NULL)
    {
        cout << "Staff not Found!!" << endl;
    }
    else
    {
        cout << *ptr;
    }
}

void findStaffbyName()
{
    string name;
    cout << "Enter name: " << endl;
    cin >> name;

    for (char &c : name)
    {
        c = tolower(c);
    }

    for (int i = 0; i < staffTable.capacity; i++)
    {
        if (studentTable.arr[i] != NULL)
        {
            staff *loc = staffTable.arr[i];
            while (loc != NULL)
            {
                string fullname = loc->staffName;
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

void editStaffbyID()
{
    int id;
    string name;
    int age;
    string role;
    string contact;
    cout << "Enter ID: ";
    cin >> id;

    staff* ptr = staffTable.getFromHashTable(id);
    cout << *ptr;

    cout << "Enter New Name: " << endl;
    cin >> name;
    cout << "Enter New Age: " << endl;
    cin >> age;
    cout << "Enter New Role: " << endl;
    cin >> role;
    cout << "Enter New Contact: " << endl;
    cin >> contact;
  
    ptr->id = id;
    ptr->staffName = name;
    ptr->age = age;
    ptr->staffRole = role;
    ptr->contactNumber = contact;

    cout << "Edited: " <<endl;
    cout << *ptr;

    unWriteStaff(id);
    writeStaff(ptr);
}

void showAllStaff()
{
    studentTable.printAll();
}
