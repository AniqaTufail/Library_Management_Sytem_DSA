#include <iostream>

// Parser Functions
#include "./parser/parser.h"
// Main Menu
#include "./menu/menu.h"

using namespace std;

int main(){
    cout << "Library Management System" << endl;

    bookParser();
    studentParser();
    staffParser();

    menu();


 }
