#include <stdio.h>
#include <stdlib.h>
#define no 100

//calculating the positions of parent, left child and right child of the element present at index i;
int parent(int i)
{
	int ans = ((i - 1) / 2);
	return ans;
}

int left(int i)
{
	int ans = ((2 * i) + 1);
	return ans;
}

int right(int i)
{
	int ans = ((2 * i) + 2);
	return ans;
}

//function to swap 2 numbers
void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
	return;
}

//this function shifts the position of element(whose position we give) upward if it is smaller than its parent and then changes pos to pos of its parent and then shifts up again till they are arranged in heap
void SiftUp(int arr[],int pos)
{
	while((pos > 0) && (arr[pos] < arr[parent(pos)]))
	{
		swap(&arr[pos], &arr[parent(pos)]);
		pos = parent(pos);
	}
	return;
}

//function to insert new element
void Insert(int num, int arr[], int *Size)
{
	if(*Size > no)
	{
		printf("Insert Fail");
	}
	else
	{
		//case when heap size is 0
		if((*Size) == 0)
		{
			arr[0] = num;
			(*Size)++ ;
		}
		else
		{
			//increment heap size, insert the element at end and then shift its position up till heap is formed
			(*Size)++ ;
			arr[(*Size) - 1] = num;
			SiftUp(arr, (*Size) - 1);
		}
	}
}	

//this function shifts down the element to form heap
void MinHeapify(int posn, int arr[], int heapSize)
{

	//find minimum of elements present at posn, left(posn) and right(posn) 
	int min;
	if(left(posn) > (heapSize - 1))
		return;
	if(arr[left(posn)] < arr[posn])
		min = left(posn);
	else 
		min = posn;
		
	if((right(posn) <= (heapSize - 1)) && (arr[right(posn)] < arr[min]))
		min = right(posn);
	
	//case when element at posn is minimum then that subtree is already in heap	 
	 if(min == posn)
	 	return;
	 else
	 {
	 	//swapping arr[posn] and arr[min] using swap function to get minimum at the root of the subtree
	 	swap(&arr[posn], &arr[min]);
	 
	 	//and then again using MinHeapify function to arrange the elements in the subtrees of this subtree in a heap 
	 	MinHeapify(min, arr, heapSize);
	 }	
}

void Delete(int index, int arr[], int * Size)
{
	//case when we are deleting the element which is not in heap
	if(index > ((*Size) - 1) || ((*Size) == 0))
		printf("Operation Fail\n");
	else
	{
		//replacing the element to be deleted with last element of heap, decrementing heap Size and then arranging the heap
		arr[index] = arr[(*Size) - 1];
		(*Size)-- ;
		MinHeapify(index, arr, *Size);
	}
	return;
}

//prints the min element, replaces it with last element of heap and then arranging the heap
void ExtractMin(int arr[], int * Size)
{
	if(*Size == 0)
	{
		printf("Empty Heap\n");	
	}
	else
	{
		int temp = arr[0];
		printf ("%d\n", temp);
		arr[0] = arr[(*Size) - 1];
		MinHeapify(0, arr, *Size);
		(*Size)-- ;
	}
	return;		
}

//printing the elements of heap as per array indices
void PrintHeap(int arr[], int heapSize)
{
	for(int i = 0; i < heapSize; i++)
	{
		printf("%d\n", arr[i]);
	}
	return;
}

void DecreaseKey(int arr[], int index, int value, int heapSize)
{
	//case when element is to be replaced with larger value 
	//also the case when user gives index position of element which is not in heap 
	if((arr[index] < value) || index > (heapSize - 1))
	{
		printf("Operation Fail\n");	
		return;
	}
	else
	{
		//replace the element value with new value(which is smaller than previous one) and then use SiftUp to arrange the heap in correct order
		arr[index] = value;
		SiftUp(arr, index);
	}
}

void BuildHeap(int arr[], int heapSize)
{
	//if its not leaf node, then use MinHeapify to arrange that subtree in form of heap 	
	int Index = heapSize/2;
	for(int j = Index; j >= 0; j--)
	{
		MinHeapify(j, arr, heapSize);
	}
}

//prints the minimum element of heap
void FindMin(int arr[], int size)
{
	if(size == 0)
		printf("Empty Heap");
	else
		printf("%d\n", arr[0]);
}

int main()
{
	int arr[no], heapSize = 0;
	int opt;
 	scanf("%d", &heapSize);
 	
 	//taking array as input from user
	for(int i = 0; i < heapSize; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	//building heap using the array
	BuildHeap(arr, heapSize);
		
	while(1)
	{
	    //takes input from user and calls appropriate function
		scanf("%d", &opt);
		
		//when opt = 1, user has to give a number as input which has to be inserted in the heap
		//then insert function is called 
		if(opt == 1)
		{
			int a;
			scanf("%d", &a);
			Insert(a, arr, &heapSize);
		}
		//when opt = 2, user has to give index position of the number to be deleted from heap as input 
		//then delete function is called
		else if(opt == 2)
		{
			int index;
			scanf("%d", &index);
			Delete(index, arr, &heapSize);
		}
		//when opt = 3, Extract Min function is called 
		else if(opt == 3)
		{
			ExtractMin(arr, &heapSize);
		}
		//when opt = 4, print heap function is called which prints the heap
		else if(opt == 4)
		{
		    PrintHeap(arr, heapSize);
		}
		//when opt = 5, the user is asked to give input for index position of the number, whose value has to be decreased,
		//and also the value to which it has to be decreased to.
		//then we call the DecreaseKey function
		else if(opt == 5)
		{
			int index, num;
			scanf("%d", &index);
			scanf("%d", &num);
			DecreaseKey(arr, index, num, heapSize);
		}
		//when opt = 6, FindMin function is called
		else if(opt == 6)
		{
			FindMin(arr, heapSize);
		}
		else if(opt == 7)
			exit(1);
	}

	return 0;
}