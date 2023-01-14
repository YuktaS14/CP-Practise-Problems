#include <stdio.h>

void insert(int i, int *a)
//i represents the index value of the element which has to be placed at the correct position within the sorted array -- arr[0, ...., i-1] so that after inserting arr[0,..,i] gets sorted in non-decreasing order
{
	int last = *(a + i);
	int j = (i-1);
	
	while(j >= 0 && *(a + j) > last)
	{
		//shifting all the elements which are larger than arr[i], in the sorted array, to the right by one position
		*( a + j + 1) = *(a + j);
		j--;
	}
	*( a + j + 1) = last;
	//and copying the arr[i] element to a position such that all elements less than arr[i] are at the left of it.
}

void Sort(int n, int arr[])
// sorting he array of n elements
{
	if(n <= 1)
		return;
	
	else
	{
		Sort(n-1, arr);
	    //sorting first n-1 elements and inserting the last element of those n elements at its correct position in the sorted array.
		insert(n-1, &arr[0]);
	}
	
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[n];
	
	//takes array as input from the user
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	Sort(n ,arr);
	//applying insertion Sort on the array
	
	for(int i = 0; i < n; i++)
	{
		//printing the sorted array
		printf("%d\n", arr[i]);
	}
	
	return 0;	
}