#pragma once
#include <iostream>
#include <string>
using namespace std;

// Needed for Accessing Global Hashtable Objects
#include "../dataStructures/hashtable.h"

// Needed for Accessing Book Class
#include "book.h"

void addNewBook()
{
    string bookname;
    string authorname;
    string genre;
    int id;
    string rating;
    bool available;
    string floor;
    string shelf;
    cout<<"Enter Book ID: "<<endl;
    cin >> id;
    cout<<"Enter New Book Name: "<<endl;
    cin>>bookname;
    cout<<"Enter the Author Name: "<<endl;
    cin>>authorname;
    cout<<"Enter Genre: "<<endl;
    cin>>genre;
    cout << "Enter Rating: " << endl;
    cin >> rating;
    cout<<"Enter Floor: "<<endl;
    cin>>floor;
    cout<<"Enter Shelf: "<<endl;
    cin>>shelf;

    book* newbook = new book;
    treeNode* newtreeNode = new treeNode;
    newbook->bookName = bookname;
    newbook->authorName = authorname;
    newbook->genre = genre;
    newbook->id = id;
    newbook->rating = rating;

    newtreeNode->id = id;
    newtreeNode->bookName = bookname;
    newtreeNode->floor=floor;
    newtreeNode->shelf=shelf;
    
    bookTable.insertIntoHashTable(newbook,id);
    bookTree.insertIntoTree(newtreeNode);
    writeBook(newbook,newtreeNode);


}

void removeBook()
{
    int id;
    cout<<"Enter ID: "<<endl;
    cin>>id;
    bool deletedbook = bookTable.deleteFromHashTable(id);
    if(deletedbook){
        cout<<"The Book has been Deleted!!"<<endl;
    }
    else{
        cout<<"Book not Found!!"<<endl;
    }
    unWriteBook(id);

}
void findbookById(){
    int id;
    cout<<"Enter the Book ID:"<<endl;
    cin>>id;
    book* searchedbook = bookTable.getFromHashTable(id);
    cout<<*searchedbook<<endl;
}

void issueBook()
{
    int bookID;
    int studentID;
    cout << "Enter ID of Book to be Issued: ";
    cin >> bookID;
    cout << "Enter ID of Student: ";
    cin >> studentID;

    book* book = bookTable.getFromHashTable(bookID);
    treeNode* treeNode = bookTree.getFromTree(bookID);

    if (book != NULL)
    {
        if (book->issuedbyID ==0)
        {
        book->issuedbyID = studentID;
        }else
        {
            cout << "Book Already Issued" <<endl;
        }
        
    }else
    {
        cout << "Book Not Found" << endl;
    }

    unWriteBook(bookID);
    writeBook(book,treeNode);

}

void receiveBook()
{
    int bookID;
    int studentID;
    cout << "Enter ID of Book to be Returned: ";
    cin >> bookID;
    cout << "Enter ID of Student: ";
    cin >> studentID;

    book* book = bookTable.getFromHashTable(bookID);
    treeNode* treeNode = bookTree.getFromTree(bookID);

    if (book != NULL)
    {
        book->issuedbyID = 0;
    }else
    {
        cout << "Book Not Found" << endl;
    }

    unWriteBook(bookID);
    writeBook(book,treeNode);
}


void showAllBook()
{
    bookTable.printAll();
}

void findBookLocation()
{
    int id;
    cout<<"Enter ID: "<<endl;
    cin>>id;

    treeNode* temp = bookTree.getFromTree(id);
    cout << "Book Name: " << temp->bookName << endl;
    cout << "Floor: " << temp->floor << endl;
    cout << "Shelf: " << temp->shelf <<endl;
}
