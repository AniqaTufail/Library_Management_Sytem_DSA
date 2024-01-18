#pragma once
#include <iostream>


// Needed for declaring Hashtable Objects at the bottom
#include "../student/student.h"
#include "../staff/staff.h"
#include "../book/book.h"


using namespace std;

template <typename T>

class hashtable{
public:
  const static int capacity = 1000;
  T* arr[capacity]{NULL};


    void insertIntoHashTable(T * ptr,int id)
    {
        int location = hashFunction(id);

        if(arr[location]==NULL){
            arr[location] = ptr;
        }
        else{
            T * ploc = NULL;
            T * loc  = arr[location];
            while(loc!=NULL){
                ploc=loc;
                loc=loc->next;
            }
            ploc->next=ptr;
        }

    }


    T* getFromHashTable(int id)
    {
        int location = hashFunction(id);

        T * loc = arr[location];

        while(loc!=NULL && loc->id!=id){
            loc=loc->next;
        }

        return loc;
    }

    void printAll()
    {
        for(int i = 0 ; i < capacity ; i++){
            if(arr[i]!=NULL){
                T * loc = arr[i];
                while(loc!=NULL){

                    cout<< *loc ;
                    loc=loc->next;
                }
            }
        }
    }

    bool deleteFromHashTable(int id)
    {
        int location = hashFunction(id);

        T* ploc = NULL;
        T* loc = arr[location];
        while(loc!= NULL && loc->id != id)      
        {
            ploc = loc;      
            loc = loc->next;
        }
        if(loc != NULL)
        {
            if (ploc == NULL)
            {
                arr[location] = arr[location]->next;
                delete loc;
            }else
            {
                ploc->next = loc->next;
                delete loc;
            }
            return true;
        }else
        {
            return false;
        }

    }


private:
    int hashFunction(int id)
    {
        int x = ((id + 3409746) * 33) % 1000;

        return x;
    }

};


// Global Hashtable Objects
hashtable<book> bookTable;    
hashtable<student> studentTable;
hashtable<staff> staffTable;
