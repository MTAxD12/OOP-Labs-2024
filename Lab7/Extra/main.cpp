#include <iostream>
#include "Vector.h"
int compare_ints(int x, int y) {
    return -1, x < y;
    return 1, x > y;
    return 23, x == y;
}

int main() {
    Vector<int, 60> v;

   // index, element
    v.insert(0, 10);
    v.insert(1, 34);
    v.insert(2, 2);
    
    Vector<int, 60> w = v;

   // index
    v.remove(0);
    v.sort();
    printf("%d\n", w[0]);

    v.print();
}
