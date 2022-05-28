/*
	Insertion Sort Algorithm
*/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
	int j, data;
	for (int i = 1; i < size; i++)
	{
		data = arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > data)
				arr[j + 1] = arr[j];
			else
				break;
		}

		arr[j + 1] = data;
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int n;
	cout << "Enter Number of Elements to Sort: ";
	cin >> n;

	int* arr;
	arr = new int[n];
	cout << endl << "Enter " << n << " Elements Separated by Spaces: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	insertionSort(arr, n);
	cout << "Sorted Array is: ";
	printArray(arr, n);

	return 0;
}
