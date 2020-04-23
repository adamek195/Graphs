#include "vector.hpp"

void vectorClass::push(int data)
{
    //jeśli liczba elementów jest równa pojemności,
    //oznacza to, że nie mamy miejsca na umieszczenie większej liczby elementów
    //Musimy podwoić przepustowość
    if (current == capacity)
    { 
        int* temp = new int[2 * capacity]; 
  
        //kopiowanie elementow w starej tablicy do nowej
        for (int i = 0; i < capacity; i++)
            temp[i] = array[i]; 
  
        // usuwanie poprzedniej tablicy
        delete[] array; 
        capacity *= 2; 
        array = temp; 
    } 
    // dodawanie danej 
    array[current] = data; 
    current++;  
}

// funckja dodajaca element dla dowolnego indeksu
void vectorClass::push(int data, int index) 
{ 
  
    //jeśli indeks jest równy pojemności to funkcja
    //ta jest taka sama jak zdefiniowany powyżej push
    if (index == capacity) 
        push(data); 
    else
        array[index] = data; 
}

// funkcja zwracajaca element dla danego indeksu
int vectorClass::getData(int index) 
{ 
    // podany indeks musi byc mniejszy niz rozmiar tablicy 
    if (index < current) 
        return array[index];
    else
    {
        std::cout <<"Indeks wykracza poza zakres kontenera!!!";
        return 0;
    }    
} 
  
// funkcja usuwajaca ostatni element 
void vectorClass::pop() 
{ 
    array[current] = NULL;
    current--; 
}
  
// funkcja zwracajaca rozmiar kontenera 
int vectorClass::size() 
{ 
    return current; 
} 
  
// funkcja zwracajaca pojemnosc kontenera czyli ile mamy zarezwerowwowane w pamieci 
int vectorClass::getcapacity() 
{ 
    return capacity; 
} 
  
// funkcja wypisujaca zawartosc kontenera 
void vectorClass::print() 
{ 
    for (int i = 0; i < current; i++)
        std::cout << "("<<array[i] << ") ";
    std::cout << std::endl;      
} 