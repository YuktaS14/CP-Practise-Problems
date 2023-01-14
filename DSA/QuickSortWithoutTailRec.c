#include <stdio.h>

void swap(int* a, int* b)
//swaps the 2 given numbers whose addresses are given as parameters to the function
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition( int arr[], int left, int right, int pivot)
//this function takes the first element of the subarray(left,....,right) as the pivot, places the pivot at its correct position in the sorted array, in a way that all the elements smaller than the pivot are to the left of it and all greater elements are to the right of the pivot. 
{
	int i = left ;
	//index of smaller elements found till now and indicates the right position of pivot at the end. 
	
	for(int j = (left + 1) ; j <= right ; j++)
	{
		if(arr[j] <= pivot)
		{
			//if current element is smaller than the pivot then increment i and swap the smaller element (arr[j]) with the arr[i] element.
			i++ ;
			swap(&arr[i], &arr[j]);
		}	
	}
	swap(&arr[i], &arr[left]);
	//place the pivot at right position and return the pivot index 
	return i ;
}

void QuickSort(int arr[], int left, int right)
//left -> starting index , right -> ending index
//if arr has only one element then return as no sorting is required
{
	while(1)
	{
		if(left >= right)
			return;
		
		else if(left < right)
		{
			//consider the first element as the pivot
			int pivot = arr[left] ;
			//pivotIndex gives the index position of our pivot in the sorted array by calling partition function
			int pivotIndex = partition(arr, left, right, pivot);
		
			//using QuickSort function on the smaller sub-array among the two obtained after partition and using the iterative way for another to eliminate tail recursion.   
			
			if(pivotIndex - left < right - pivotIndex)
			{
				QuickSort(arr, left, pivotIndex - 1);
				left = pivotIndex + 1;
			}
				
			else
			{
				QuickSort(arr, pivotIndex + 1, right);
				right = pivotIndex - 1;
			}	
		}
	}
}
	
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[n];
	
	//taking elements of the array as input from the user 
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	QuickSort(arr, 0 , n-1);
	//calling the Quick sort function to sort the array
	
	for(int i = 0; i < n; i++)
	{
		//printing the sorted array
		printf("%d\n", arr[i]);
	}
	
	return 0;
}