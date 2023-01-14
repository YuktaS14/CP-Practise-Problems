#include<stdio.h>

void merge(int A[], int first, int mid, int last)
//This function merges the 2 sorted subarrays in such a way to form a sorted array
{
	int n1 = mid - first + 1;
	int n2 = last - mid;
	
	int L[n1], R[n2];
	//Subarray L[] contains the elements from the left half in sorted manner 
	//and array R[] contains the elements from the right half in sorted manner
	
	//copying the elements of the array in L[] and R[] subarrays
	
	for(int i = 0; i < n1 ; i++)
	{
		L[i] = A[first + i];
	}
	
	for(int j = 0; j < n2 ; j++)
	{
		R[j] = A[mid + 1 + j];
	}
	
	int i = 0, j = 0 , k = first;
	//here k refers to the index position of initial element of left subarray in the original array
	
	//merging the 2 subarrays and copying it back to the original array
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			//if element from the left half is smaller than that from the right half then copy it to the original array and increment the index values of the left array. 
			A[k] = L[i];
			i++;
		}	
		else
		{
			//else copy the right half element to the original array and increment the index values of the right array.
			A[k] = R[j];
			j++;
		}
			
		k++;
		//incrementing the index of array.
	}
	
	//copying the remaining elements back to the original array
	while(i < n1)
	{
		A[k] = L[i];
		k++ ;
		i++ ;
	}
	
	while(j < n2)
	{
		A[k] = R[j];
		k++ ;
		j++ ;
	}
	
	
}

void Sort(int A[], int first, int last)
//This recursive function sorts the right and the left halves of the subarrays and merges them later to get the sortd array 
{
	if(first >= last)
		return;
		
	else				
	{
		int mid = (first + last) / 2;
		
		Sort(A, first, mid);
		//sorting the left half
		
		Sort(A, mid + 1, last);		
		//sorting the right half
		
		merge(A, first, mid, last);
		//merges the 2 subarrays
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	
	//taking array as input from the user
	int A[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	Sort(A, 0, n-1);
	
	//printing out the sorted array
	for(int i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}
	
	return 0;
}