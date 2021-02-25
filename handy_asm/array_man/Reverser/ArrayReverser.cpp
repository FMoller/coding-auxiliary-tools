/** ArrayReverser.cpp : An example to how to call the Reverser
 * @author Frederico Moeller
 * 
 * Created on: February 25, 2021
*/

#include <iostream>
#include <stdlib.h>

extern "C" void Reverser(int *y, const int *x, int n);

int main()
{
    const int n = 10;
    int x[n], y[n];

    srand(41);
    for (int i = 0; i < n; i++) {
        x[i] = rand() % 1000;
    }
    Reverser(y, x, n);
    printf("\n---------------------Array Reverser-----------------------\n");
    for (int i = 0; i < n; i++) {
        printf("i: %d\ty: %d\tx: %d\n",i,y[i],x[i]);
    }
}

