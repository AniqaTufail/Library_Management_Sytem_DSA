#pragma once
#include <iostream>
using namespace std;

class staff{
    //Data
    public:
    string staffName="";
    int id ;
    string staffRole ;
    int age;
    string contactNumber;
    //Pointer 
    staff * next =NULL;

    friend ostream& operator<<(ostream& os, const staff& obj) {
        os << "ID: " << obj.id << " Name: " << obj.staffName << " Role: " << obj.staffRole << " Age: " << obj.age << " ContactNumber: "<< obj.contactNumber << endl <<endl;
        return os;
    }

};