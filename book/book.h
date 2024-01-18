#pragma once
#include <iostream>
using namespace std;


class book{
    public:
    //Data
    string bookName = "";
    string authorName = "";
    int id;
    string genre ="";
    string rating;
    

    int issuedbyID = 0;

    //Pointers for hashtable

    book * next =NULL;
     friend ostream& operator<<(ostream& os, const book& obj) {
        os << "ISBN: " << obj.id << " Name: " << obj.bookName <<endl << "AuthorName: " << obj.authorName << " Genre: " << obj.genre << " Rating: " << obj.rating << endl <<endl;
        return os;
    }


};