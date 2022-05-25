/* Lab 11a
Quick sort Algorithm
Sarmad Salman
Muhammad Hassaan */
#include <iostream>
using namespace std;
void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int divide (int arr[], int first, int last){
    int hub = arr[last];
    int i = (first - 1); 
    for (int j = first; j <= last - 1; ++j){
        if (arr[j] < hub){
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[last]);
    return (i + 1);
}
void QuickSort (int arr[], int first, int last){
    if (first < last){
        int part = divide (arr, first, last);
        
        QuickSort (arr, first, part - 1);
        QuickSort (arr, part + 1, last);
    }
}
void printArray (int arr[], int size){
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int num;
    cout<<"Enter the number of integers to sort: ";
    cin>>num; int arr[num];
    cout<<"Enter an array of integers to sort: ";
    for(int i = 0; i<num; ++i)
        cin>>arr[i];
    QuickSort(arr, 0, num - 1);
    cout << "Sorted array: ";
    printArray(arr, num);
    return 0;
}
