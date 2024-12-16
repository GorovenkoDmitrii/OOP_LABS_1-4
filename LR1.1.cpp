#include <iostream>
using namespace std;
int main() {
    cout << "Enter the number of array elements: ";
    int n;
    cin >> n;
    int* array = new int[n];
    cout << "Enter integers to fill the array: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cout << "The contents of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "array[" << i << "]: " << array[i] << " (adress: " << &array[i] << ")" << endl;
    }
    cout << "The distance of the elements from the beginning of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Length of array[" << i << "] from the beginning of the array: " << (&array[i] - array) * sizeof(int) << " byte" << endl;
    }
    delete[] array;
} 