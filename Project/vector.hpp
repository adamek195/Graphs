#ifndef vector_hpp
#define vector_hpp
#include <iostream>


class vectorClass
{
    //arr jest wskaźnikiem liczbowym,
    //który przechowuje adres naszego wektora
    int* array;

    //zmienna capacity jest całkowitą
    //pojemnością magazynową wektora
    int capacity;

    //zmienna current to liczba elementów
    //obecnych obecnie w kontenerze
    int current;

    public:
   //kontruktor domyslny
    vectorClass() 
    { 
        array = new int[1]; 
        capacity = 1; 
        current = 0; 
    }
    ~vectorClass()
    {
        delete [] array;
    }
    void push(int data);
    void push(int data, int index);
    int getData(int index);
    void pop();
    int size();
    int getcapacity();
    void print(); 
};



#endif