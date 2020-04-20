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
    void push(int data)
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
        // dodwanie danej 
        array[current] = data; 
        current++;  
    }
    // funckja dodajaca element dla dowolnego indeksu
    void push(int data, int index) 
    { 
  
        //jeśli indeks jest równy pojemności to funkcja
        //ta jest taka sama jak zdefiniowany powyżej push
        if (index == capacity) 
            push(data); 
        else
            array[index] = data; 
    }
      // funkcja zwracajaca element dla danego indeksu
    int get(int index) 
    { 
  
        // podany indeks musi byc mniejszy niz rozmiar tablicy 
        if (index < current) 
            return array[index]; 
    } 
  
    // funkcja usuwajaca ostatni element 
    void pop() 
    { 
        array[current] = NULL;
        current--; 
    } 
  
    // funkcja zwracajaca rozmiar kontenera 
    int size() 
    { 
        return current; 
    } 
  
    // funkcja zwracajaca pojemnosc kontenera czyli ile mamy zarezwerowwowane w pamieci 
    int getcapacity() 
    { 
        return capacity; 
    } 
  
    // funkcja wypisujaca zawartosc kontenera 
    void print() 
    { 
        for (int i = 0; i < current; i++) { 
            std::cout << array[i] << " "; 
        } 
        std::cout << std::endl; 
    } 
};   




int main()
{
    vectorClass v; 
    v.push(10); 
    v.push(20); 
    v.push(30); 
    v.push(40); 
    v.push(50); 
  
    std::cout << "Vector size : "
         << v.size() << std::endl; 
    std::cout << "Vector capacity : "
         << v.getcapacity() << std::endl; 
  
    std::cout << "Vector elements : "; 
    v.print();

    v.pop();
    v.pop();
    std::cout << "Vector size : "
         << v.size() << std::endl;
    std::cout << "Vector capacity : "
         << v.getcapacity() << std::endl; 
  
    std::cout << "Vector elements : "; 
    v.print();

    return 0;
}