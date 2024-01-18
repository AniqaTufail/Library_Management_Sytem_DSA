#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

// Needed for Accessing Global Hashtable Objects
#include "../dataStructures/hashtable.h"
#include "../dataStructures/tree.h"

// Needed for Accessing Student, Staff and Book Classes
#include "../student/student.h"
#include "../staff/staff.h"
#include "../book/book.h" 

using namespace std;
using namespace filesystem;


string mainPath = current_path().string();


void bookParser()
{
    ifstream file(mainPath + "\\book\\" + "book.csv");
    string line;
    string word;
    int count;


    getline(file, line);		// skip first record which are just column names



    while(!file.eof())
    {
        book* newbook = new book;
        treeNode* newTreeNode = new treeNode;
        getline(file,line);
        count = 1;
        word = "";
        if (line != "")
        {
        for (int i = 0; i < line.length() + 1; i++)
        {
            if ((line[i] != ',') && (i != line.length()))
            {
                word += line[i];
            }
            else
            {
                if (count == 1)
                {
                    newbook->id = stoi(word);
                    newTreeNode->id = stoi(word);
                }
                else if (count == 2)
                {
                    newbook->bookName = word;
                    newTreeNode->bookName = word;
                }
                else if (count == 3)
                {
                    newbook->authorName = word;
                }
                else if (count == 4)
                {
                    newbook->genre = word;
                }
                else if (count == 5)
                {
                    newbook->rating= word;
                }
                else if (count == 6)
                {
                    newTreeNode->floor = word;
                }
                else if (count == 7)
                {
                    newTreeNode->shelf = word;
                }
                else if (count == 8)
                {
                    newbook->issuedbyID = stoi(word);
                }
                count++;
                word = "";
            }
        }
        }

        bookTable.insertIntoHashTable(newbook,newbook->id);
        bookTree.insertIntoTree(newTreeNode);
    }
    file.close();
}


void studentParser()
{
    ifstream file(mainPath + "\\student\\" + "student.csv");
    string line;
    string word;
    int count;

    getline(file, line);		// skip first record which are just column names



    while(!file.eof())
    {
        student* newStudent = new student;
        getline(file,line);
        count = 1;
        word = "";
        if(line != "")
        {
        for (int i = 0; i < line.length() + 1; i++)
        {
            if ((line[i] != ',') && (i != line.length()))
            {
                word += line[i];
            }
            else
            {
                if (count == 1)
                {
                    newStudent->id = stoi(word);
                }
                else if (count == 2)
                {
                    newStudent->firstName = word;
                }
                else if (count == 3)
                {
                    newStudent->lastName = word;
                }
                else if (count == 4)
                {
                    newStudent->age = stoi(word);
                }
                else if (count == 5)
                {
                    newStudent->email= word;
                }
                count++;
                word = "";
            }
        }
        }

        studentTable.insertIntoHashTable(newStudent,newStudent->id);

    }
    file.close();
}

void staffParser()
{
    ifstream file(mainPath + "\\staff\\" + "staff.csv");
    string line;
    string word;
    int count;

    getline(file, line);		// skip first record which are just column names


    while(!file.eof())
    {
        staff* newStaff = new staff;
        getline(file,line);
        count = 1;
        word = "";
        if (line != "")
        {
        for (int i = 0; i < line.length() + 1; i++)
        {
            if ((line[i] != ',') && (i != line.length()))
            {
                word += line[i];
            }
            else
            {
                if (count == 1)
                {
                    newStaff->id = stoi(word);
                }
                else if (count == 2)
                {
                    newStaff->staffName = word;
                }
                else if (count == 3)
                {
                    newStaff->staffRole= word;
                }
                else if (count == 4)
                {
                    newStaff->age = stoi(word);
                }
                else if (count == 5)
                {
                    newStaff->contactNumber = word;
                }
                count++;
                word = "";
            }
        }
        }

        staffTable.insertIntoHashTable(newStaff,newStaff->id);

    }

    file.close();
}

void writeStudent(student* newstudent)
{
    ofstream file(mainPath + "\\student\\" + "student.csv",ios::app);
    string line = "\n" + to_string(newstudent->id) + "," + newstudent->firstName + "," + newstudent->lastName + "," + to_string(newstudent->age) + "," + newstudent->email;
    file<<line;
    file.close();
}

void writeStaff(staff* newstaff)
{
    ofstream file(mainPath + "\\staff\\" + "staff.csv",ios::app);
    string line = "\n" + to_string(newstaff->id) + "," + newstaff->staffName + "," + newstaff->staffRole + "," + to_string(newstaff->age) + "," + newstaff->contactNumber;
    file << line;
    file.close();
}

void writeBook(book* newbook,treeNode* newtreeNode)
{
    ofstream file(mainPath + "\\book\\" + "book.csv",ios::app);
    string line = "\n" + to_string(newbook->id) + "," + newbook->bookName + "," + newbook->authorName + "," + newbook->genre + "," +newbook->rating + "," + newtreeNode->floor + "," + newtreeNode->shelf + "," + to_string(newbook->issuedbyID);
    file<<line;
    file.close();

}


void  unWriteStudent(int id)
{
    ifstream file1 (mainPath + "\\student\\" + "student.csv");
    int i;
    int count = 0;

    i =0;
    string lines[1000]{""};
    string line;
    while(!file1.eof())
    {
        getline(file1,line);
        lines[i] = line;
        i += 1;
        count +=1;
    }

    file1.close();

    ofstream file2 (mainPath + "\\student\\" + "student.csv");

    i = 0;
    while (i < count)
    {
        string temp = "";
        temp += lines[i][0];
        temp += lines[i][1];
        temp += lines[i][2];
        temp += lines[i][3];
        temp += lines[i][4];
        temp += lines[i][5];
        if ((temp) != to_string(id))
        {
            file2 << lines[i] << "\n";
        }
        i+=1;

    }
    file2.close();

}

void  unWriteStaff(int id)
{
    ifstream file1 (mainPath + "\\staff\\" + "staff.csv");
    int i;
    int count = 0;

    i =0;
    string lines[1000]{""};
    string line;
    while(!file1.eof())
    {
        getline(file1,line);
        lines[i] = line;
        i += 1;
        count +=1;
    }

    file1.close();

    ofstream file2 (mainPath + "\\staff\\" + "staff.csv");

    i = 0;
    while (i < count)
    {
        string temp = "";
        temp += lines[i][0];
        temp += lines[i][1];
        temp += lines[i][2];
        if ((temp) != to_string(id))
        {
            file2 << lines[i] << "\n";
        }
        i+=1;

    }
    file2.close();

}
void  unWriteBook(int id)
{
    ifstream file1 (mainPath + "\\book\\" + "book.csv");
    int i;
    int count = 0;

    i =0;
    string lines[1000]{""};
    string line;
    while(!file1.eof())
    {
        getline(file1,line);
        lines[i] = line;
        i += 1;
        count +=1;
    }

    file1.close();

    ofstream file2 (mainPath + "\\book\\" + "book.csv");

    i = 0;
    while (i < count)
    {
        string temp = "";
        temp += lines[i][0];
        temp += lines[i][1];
        temp += lines[i][2];
        temp += lines[i][3];
        temp += lines[i][4];
        temp += lines[i][5];
        if ((temp) != to_string(id))
        {
            file2 << lines[i] << "\n";
        }
        i+=1;

    }
    file2.close();

}



