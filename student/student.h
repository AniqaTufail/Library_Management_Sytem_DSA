#pragma once
#include <iostream>
#include <string>

using namespace std;


class student{
    public:
    // data
    int id;
    string firstName="";
    string lastName = "";
    int age;
    string email="";


    // pointer for hashtable
    student * next = NULL;


    friend ostream& operator<<(ostream& os, const student& obj) {
        os << "ID: " << obj.id << " Name: " << obj.firstName << " " << obj.lastName <<endl << "Age: " << obj.age << " Email: " << obj.email << endl <<endl;
        return os;
    }



 };

