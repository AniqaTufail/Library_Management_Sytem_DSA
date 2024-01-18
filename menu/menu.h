#pragma once
#include <iostream>
using namespace std;

// Get all the functions
#include "../student/studentFunc.h"
#include "../staff/staffFunc.h"
#include "../book/bookFunc.h"


// prototype declarations
void studentMenu();
void staffMenu();
void bookMenu();


// main menu
void menu ()
{
    int choice;
    bool menu = true;
    while(menu)
    {
        cout << "Select a choice: " << endl << "1. Students" <<endl << "2. Staff" <<endl << "3. Books" << endl << "4. Exit" <<endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            studentMenu();
            break;
        case 2:
            staffMenu();
            break;
        case 3:
            bookMenu();
            break;
        case 4:
            menu = false;
            break;
        default:
            cout << "Please select a valid choice: ";
            
        }
    }
}


// sub-menus

void studentMenu()
{
    int choice;
    bool menu = true;
    while(menu)
    {
        cout << "Select a choice: " << endl << "1. Add new Student" <<endl << "2. Remove a Student" <<endl << "3. Find Student by ID" <<endl << "4. Find Student by Name" << endl<< "5. Edit Record by ID" <<endl << "6. Show all Students" <<endl << "7. Go Back" << endl;
        
        cin >> choice;

        switch(choice)
        {
        case 1:
            makeNewStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            findStudentbyID();
            break;
        case 4:
            findStudentbyName();
            break;
        case 5:
            editStudentbyID();
            break;
        case 6:
            showAllStudents();
            break;
        case 7:
            menu = false;
            break;
        default:
            cout << "Please Enter A Valid Choice" << endl;
        }
    }

}
void staffMenu()
{
    int choice;
    bool menu = true;
    while (menu)
    {
        cout << "Select a choice: " << endl << "1. Add new Staff" <<endl << "2. Remove a Staff" <<endl << "3. Find Staff by ID" <<endl << "4. Find Staff by Name" <<endl << "5. Edit Record by ID" << "6. Show all Staff" <<endl << "7. Go Back" << endl;
        
        cin >> choice;

        switch(choice)
        {
        case 1:
            addNewStaff();
            break;
        case 2:
            deleteStaff();
            break;
        case 3:
            findStaffbyID();
            break;
        case 4:
            findStaffbyName();
            break;
        case 5:
            editStaffbyID();
            break;
        case 6:
            showAllStaff();
            break;
        case 7:
            menu = false;
            break;
        default:
            cout << "Please Enter A Valid Choice" << endl;
        }
    }
}
void bookMenu()
{
    int choice;
    bool menu = true;
    while(menu)
    {
        cout << "Select a choice: " << endl << "1. Add a new Book" <<endl << "2. Remove a Book" <<endl << "3. Find Book by ISBN" <<endl << "4. Issue a Book" <<endl << "5. Receive a Book" << endl << "6. Show all Books" <<endl << "7. Find Book Location" << endl << "8. Go Back" << endl;
        
        cin >> choice;

        switch(choice)
        {
        case 1:
            addNewBook();
            break;
        case 2:
            removeBook();
            break;
        case 3:
            findbookById();
            break;
        case 4:
            issueBook();
            break;
        case 5:
            receiveBook();
            break;
        case 6:
            showAllBook();
            break;
        case 7:
            findBookLocation();
            break;
        case 8:
            menu = false;
            break;
        default:
            cout << "Please Enter A Valid Choice" << endl;
        }
    }
}