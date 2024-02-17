#include <iostream>

using namespace std;

template <class T>
class Memory
{
public:
    static T **allocArray(int m, int n)
    {
        T **p = new T *[m];
        T *myArray = new T[m * n]; // create full size block array of m*n
        for (int i = 0; i < m; i++)
        {
            int index = i * n;
            p[i] = &myArray[index];
        }
        return p;
    }
};

int main()
{
    int **array;
    array = Memory<int>::allocArray(5, 10);
    int j, k;
    for (j = 0; j < 5; j++)
        for (k = 0; k < 10; k++)
            array[j][k] = j * 10 + k;
    for (j = 0; j < 5; j++)
        for (k = 0; k < 10; k++)
            cout << array[j][k] << " ";
}

// in C language
// #include <stdio.h>

// void allocArray(int ***p, int m, int n)
// {
//     int size = m * n;
//     *p = (int **)malloc(m * sizeof(int *));
//     int *myArray = (int *)malloc(size * sizeof(int)); // create full size block array of m*n
//     for (int i = 0; i < m; i++)
//     {
//         int index = i * n;
//         (*p)[i] = &myArray[index];
//     }
// }

// int main()
// {
//     int **array;
//     int j, k;
//     allocArray(&array, 5, 10);
//     for (j = 0; j < 5; j++)
//         for (k = 0; k < 10; k++)
//             array[j][k] = j * 10 + k;
//     for (j = 0; j < 5; j++)
//         for (k = 0; k < 10; k++)
//             printf("%p ", &(array[j][k]));
// }