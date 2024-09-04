#include "MyList.h"
#include <stdexcept>

MyList::MyList() {
    arr = new int[arrCapacity];
}

MyList::~MyList() {
    delete[] arr;
}

int MyList::Size() {
    return arrSize;
}

int MyList::Capacity() {
    return arrCapacity;
}

int MyList::Get(int index) {
    if (index >= arrSize || index < 0) {
        throw std::out_of_range("索引越界");
    }
    return arr[index];
}

void MyList::Set(int index, int num) {
    if (index >= arrSize || index < 0) {
        throw std::out_of_range("索引越界");
    }
    arr[index] = num;
}

void MyList::Add(int num) {
    if (arrSize == arrCapacity) {
        ExtendCapacity();
    }
    arr[arrSize] = num;
    arrSize++;
}

void MyList::Insert(int index, int num) {
    if (index >= arrSize || index < 0) {
        throw std::out_of_range("索引越界");
    }
    if (arrSize == arrCapacity) {
        ExtendCapacity();
    }
    for (int i = arrSize - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = num;
    arrSize++;
}

int MyList::Remove(int index) {
    if (index >= arrSize || index < 0) {
        throw std::out_of_range("索引越界");
    }
    int num = arr[index];
    for (int i = index; i < arrSize - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arrSize--;
    return num;
}

void MyList::ExtendCapacity() {
    int newCapacity = arrCapacity * extendRation;
    int *temp = arr;
    arr = new int[newCapacity];
    for (int i = 0; i < arrSize; i++) {
        arr[i] = temp[i];
    }
    delete[] temp;
    arrCapacity = newCapacity;
}

std::vector<int> MyList::ToVector() {
    std::vector<int> vec(arrSize);
    for (int i = 0; i < arrSize; i++) {
        vec[i] = arr[i];
    }
    return vec;
}