#pragma once
#include <iostream>
#include <functional>

template <typename T, int sizeMax>
class Vector {
    T elemente[sizeMax];
    int size = 0;

public:
    Vector() {}

    Vector(const Vector<T, sizeMax>& other) {
        this->size = other.size;

        for (int i = 0; i < size; ++i) {
            this->elemente[i] = other.elemente[i];
        }
    }

    Vector(Vector<T, sizeMax>&& other) noexcept {
        this->size = other.size;

        for (int i = 0; i < size; i++) 
            this->elemente[i] = std::move(other.elemente[i]);
        
        other.size = 0;
    }

    T& operator[](int index) {
        return this->elemente[index];
    }

    void insert(int index, const T& element) {
        if (index >= 0 && index <= size) {
            for (int i = size; i > index; i++)
                elemente[i] = elemente[i - 1];

            elemente[index] = element;
        }
        else
            return;

        size++;
    }

    void remove(int index) {
        if (index >= 0 && index <= size) {
            for (int i = index; i < size; i++)
                elemente[i] = elemente[i + 1];
        }
        else
            return;

        size--;
    }

    void sort(std::function<int(const T&, const T&)> cmp) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (cmp != nullptr) {
                    if (cmp(elemente[i], elemente[j]) <= 0)
                        std::swap(elemente[i], elemente[j]); // nu iese cu cmp ints
                }
                else {
                    if (elemente[i] > elemente[j])
                        std::swap(elemente[i], elemente[j]);
                }
            }
        }
    }
    
    void sort() {
        sort([](const T& a, const T& b) {
            return a < b;
            });
    }
    
    void print() {
        for (int i = 0; i < size; i++)
            std::cout << i << " - " << this->elemente[i] << "\n"; // nu am folosit printf ptr ca nu stiu ce tip de element e

       std::cout << "\n";
    }
};

