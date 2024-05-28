#include <stdio.h>
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Array_Out_Of_Range : public exception {
public:
    virtual const char* what() const throw() {
        return "Indexul dat nu se afla in vector";
    }
};

class Array_Out_Of_Space : public exception {
public:
    virtual const char* what() const throw() {
        return "Vectorul a ajuns la marimea sa maxima";
    }
};
template<class T>
class ArrayIterator
{
private:
    int Current;
    T** arr;
public:
    ArrayIterator(T** arr, int current) {
        this->arr = arr;
        this->Current = current;
    }

    ArrayIterator(const ArrayIterator& other) {
        this->arr = other.arr;
        this->Current = other.Current;
    }

    ArrayIterator& operator ++ () {
        this->Current++;
        return *this;
    }

    ArrayIterator& operator -- () {
        this->Current--;
        return *this;
    }

    bool operator==(const ArrayIterator<T>& other) const {
        return this->arr == other.arr && this->Current == other.Current;
    }

    bool operator!=(const ArrayIterator<T>& other) const {
        return !(*this == other);
    }
    T* GetElement() const {
        return this->arr[Current];
    }
};

template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() {
        this->List = nullptr;
        this->Capacity = 0;
        this->Size = 0;
    }// Lista nu e alocata, Capacity si Size = 0

    ~Array() {
        for (int i = 0; i < this->Capacity; i++)
            if (this->List[i])
                delete this->List[i];

        delete[] this->List;
    }// destructor

    Array(int capacity) {
        this->List = new T * [capacity];
        for (int i = 0; i < capacity; i++)
            List[i] = nullptr;
        this->Capacity = capacity;
        this->Size = 0;
    }// Lista e alocata cu 'capacity' elemente


    Array(const Array<T>& otherArray) {
        this->List = new T * [otherArray.Size];
        this->Size = otherArray.Size;
        this->Capacity = otherArray.Size;
        for (int i = 0; i < this->Capacity; i++)
            this->List[i] = new T(*otherArray.List[i]);
    }// constructor de copiere

    T& operator[] (int index) {
        if (index < 0 || index > this->Size) {
            throw Array_Out_Of_Range();
            return nullptr;
        }
        return *this->List[index];
    }// arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T& newElem) {
        if (this->Size >= this->Capacity) {
            throw Array_Out_Of_Space();
        }
        else {
            this->List[this->Size] = new T;
            *this->List[this->Size] = newElem;
            Size++;
        }
        return *this;
    }// adauga un element de tipul T la sfarsitul listei si returneaza this

    const Array<T>& Insert(int index, const T& newElem) {
        if (this->Size >= this->Capacity) {
            throw Array_Out_Of_Space();
        }
        else if (index < 0 || index > this->Size) {
            throw Array_Out_Of_Range();
        }
        else
        {
            this->List[this->Size] = new T;
            for (int i = Size; i > index; i--)
            {
                *this->List[i] = *this->List[i - 1];
            }

            *this->List[index] = newElem;
            this->Size++;
        }

        return *this;
    }// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    
    
    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (this->Size + otherArray.Size >= this->Capacity) {
            throw Array_Out_Of_Space();
        }
        else if (index < 0 || index > this->Size) {
            throw Array_Out_Of_Range();
        }
        else
        {
            for (int i = this->Size - 1; i >= index; i--) 
            {
                this->List[i + otherArray.Size] = this->List[i];
            }
            for (int i = 0; i < otherArray.Size; i++) 
            {
                this->List[index + i] = new T(*otherArray.List[i]);
            }

            this->Size += otherArray.Size;
        }

        return *this;
    }// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= this->Size) {
            throw Array_Out_Of_Range();
        }
        else {
            for (int i = index; i < this->Size - 1; i++) {
                this->List[i] = this->List[i + 1];
            }
            this->List[this->Size - 1] = nullptr;
            this->Size--;
        }
        return *this;
    }// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array& otherArray) {
        for (int i = 0; i < this->Capacity; i++)
            delete this->List[i];
        delete[] this->List;

        this->List = new T * [otherArray.Capacity];
        this->Size = otherArray.Size;
        this->Capacity = otherArray.Capacity;

        for (int i = 0; i < this->Size; i++) 
        {
            this->List[i] = new T(*otherArray.List[i]);
        }
        for (int i = this->Size; i < this->Capacity; i++)
        {
            this->List[i] = nullptr;
        }

        return true;

    }

    int GetSize() {
        return this->Size;
    }
    int GetCapacity() {
        return this->Capacity;
    }

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(this->List, 0);
    }
    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(this->List, this->Size);
    }


    void PrintArray(const char *prompt) {
        cout << prompt;
        for (int i = 0; i < this->Size; i++)
            cout << *this->List[i] << " ";
        cout << "\n";
    }
};

int main()
{
    Array<int> v(10);

    v += 0;
    v += 1;
    v += 3;
    v.Insert(2, 2);
    v += 4;
    v += 5;
    v.PrintArray("Numere: ");

    Array<int> w(3);

    w += 6;
    w += 7;
    w += 8;
    v.Insert(3, w);
    v.PrintArray("Numere dupa alipire: ");

    v.Delete(6);
    v.PrintArray("Numere dupa stergere: ");

    Array<int> z(11);
    z = v;
    z.PrintArray("Elemente z: ");
    z += 3;
    z.PrintArray("z nou: ");

    ArrayIterator<int> i = v.GetBeginIterator();
    for (i = w.GetBeginIterator(); i != w.GetEndIterator(); ++i) {
        cout << *i.GetElement() << " "; 
    }
    cout << "\n";

    return 0;
}