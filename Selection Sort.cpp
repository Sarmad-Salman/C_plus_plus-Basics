// Selection Sort Algorithm


#include<iostream>
using namespace std;
int min(int arr[], int i, int n)
{
	int j, posmin = i;

	for (j = i; j < n; j++)
	{
		if (arr[j] < arr[i] && arr[j] < arr[posmin]){
			posmin = j;
        }
	}
	return posmin;
}
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void selectionSort(int arr[], int n)
{
	int i, posmin, tmp;
	for (i = 0; i < n-1; i++)
	{
		posmin = min(arr, i, n);
		swap(arr[i], arr[posmin]);
	}
}
int main()
{
	int a;
	cout<<"Enter the size of array: ";
	cin>>a;	int* arr; arr = new int[a];
	cout<<"Enter the array elements seperated by space: ";
	for(int i =0; i<a; i++){
		cin>>arr[i];
	}
	selectionSort(arr, a);
	cout<<"Sorted Array is: ";
	printArray(arr, a);
	return 0;
}
