#include <iostream>
#include "myArray.h"

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int rand = randomAccess(arr, size);

    remove(arr, size, 2);
    insert(arr, size, 1, 2);

    int sum = traverse(arr, size);
    int num = find(arr, size, 2);

    int *myExtend = extend(arr, size, 2);
}