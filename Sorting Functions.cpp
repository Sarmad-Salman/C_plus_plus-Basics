/*
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}		
}


void selectionSort(int arr[], int n)
{
	int i, posmin, tmp;

	for (i = 0; i < n; i++)
	{
		posmin = min(arr, i, n);
		swap(&arr[i], &arr[posmin]);
	}
}

int min(int arr[], int i, int n)
{
	int j, posmin;

	for (j = i; j < n; j++)
	{
		if (arr[j] < arr[i])
			posmin = j;
	}

	return posmin;
}
*/