#include<stdio.h>
#include<stdlib.h>
#define inf 99999

//structure for creating nodes of linked list (Adjacency List)
//it also stores the edge weight.
typedef struct node
{
	int element;
	int EdgeWeight;
	struct node* next;	
}Node;

typedef struct node* nodeptr;

//structure for storing properties of vertices,which also contains pointer of struct node datatype which store the vertex value and pointer to its linked list
//stores shortest distance from set s in cost var,the pred of it(from set S), the position of vertex in heap and included is 1 when the vertex is include in minimum spanning tree

struct vert
{
	int cost;
	int pred;
	int position;
	int included;
	nodeptr vertex;
};
typedef struct vert* properties;

//structure for creating nodes of heap,stores the vertex value and cost value for the vertex, which is used as a key.
typedef struct heapnode
{
	int vertex;
	int cost; //key
}HeapNode;

typedef struct heapnode* heapptr;

properties arr;

//function to create newnode
nodeptr createNode(int k,int w)
{
	nodeptr newNode = NULL;
	newNode = (nodeptr)malloc(sizeof(struct node));
	
	if(newNode == NULL)
		exit(1);
	
	//newnode stores value of vertex,and edge weight while its next pointer is initiated to NULL
	newNode -> element = k;
	newNode -> EdgeWeight = w;
	newNode -> next = NULL;
	return newNode;
}

//function to create graph by adding vertices in Adjacency List
//adds k th vertex in adjacency list of (i+1) vertex,along with their edge weight
void createAdjList(properties arr, int i, int k,int w)
{
	nodeptr new1 = NULL;
	nodeptr prev1 = NULL,cur1 = NULL;
	
	//creates a node with value of 2nd vertex
	//and links it to linked list pointed by the 1st vertex
	new1 = createNode(k,w);
	cur1 = arr[i].vertex;
		
	while(cur1 != NULL)
	{
		prev1 = cur1;
		cur1 = cur1 -> next;
	}
	prev1 -> next = new1;
}

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

//function to swap 2 nodes
//after swapping vertex in node a occupies position b and that in b occupies position a
void swap(HeapNode *a, HeapNode *b,int posna,int posnb)
{
	int vb = b -> vertex;
	int va = a -> vertex;
	//updating position of vertices in arr array
	arr[vb-1].position = posna;//after swapping
	arr[va-1].position = posnb;//after swapping
	
	
	HeapNode temp = *b;
	*b = *a;
	*a = temp;
	
	return;
}

void MinHeapify(int posn, heapptr array, int heapSize)
{

	//find minimum of elements present at posn, left(posn) and right(posn) 
	int min;
	if(left(posn) > (heapSize - 1))
		return;
	if((array[left(posn)].cost) < array[posn].cost)
		min = left(posn);
	else 
		min = posn;
		
	if((right(posn) <= (heapSize - 1)) && ((array[right(posn)].cost) < array[min].cost))
		min = right(posn);
	
	//case when element at posn is minimum then that subtree is already in heap	 
	 if(min == posn)
	 	return;
	 else
	 {
	 	//swapping arr[posn] and arr[min] using swap function to get minimum at the root of the subtree
	 	swap(&array[posn], &array[min],posn,min);
	 
	 	//and then again using MinHeapify function to arrange the elements in the subtrees of this subtree in a heap 
	 	MinHeapify(min, array, heapSize);
	 }	
}

//function to return the vertex value of node with min key value(dist from set S)
int FindMin(heapptr array, int size)
{
	if(size == 0)
		printf("Empty Heap");
	else
	{
		int v = array[0].vertex;
		//this vertex would now be include in S, so storing its properties in array arr
		arr[v-1].cost = array[0].cost;
		arr[v-1].included = 1;
		arr[v-1].position = 0;
		return v;		
	}
}


void BuildHeap(heapptr array, int heapSize)
{
	//if its not leaf node, then use MinHeapify to arrange that subtree in form of heap 	
	int Index = heapSize/2;
	for(int j = Index; j >= 0; j--)
	{
		MinHeapify(j, array, heapSize);
	}
}

//Function to replace the min element of heap with the last element of heap and then arranging the heap
void ExtractMin(heapptr array, int * Size)
{
	if(*Size == 0)
	{
		printf("Empty Heap\n");	
	}
	else
	{
		array[0] = array[(*Size) - 1];
		int v = array[(*Size)-1].vertex;
		//last element of heap is placed at 0th index in heap,so updating the position for that vertex in array arr
		arr[v-1].position = 0;
		//decrementing size of heap
		(*Size)--;
		MinHeapify(0, array, *Size);
	}
	return;		
}



//this function shifts the position of element(whose position we give) upward if it is smaller than its parent and then changes pos to pos of its parent and then shifts up again till they are arranged in heap
void SiftUp(heapptr array, int pos,int heapSize)
{
	while((pos > 0) && (array[pos].cost < array[parent(pos)].cost))
	{
		swap(&array[pos], &array[parent(pos)],pos,parent(pos));
		pos = parent(pos);
	}
	
	return;
}


void DecreaseKey(heapptr array, int index, int value, int heapSize)
{
	//case when element is to be replaced with larger value 
	
	if((array[index].cost <= value))
	{
		printf("Operation Fail\n");	
		return;
	}
	else
	{
		//replace the element value with new value(which is smaller than previous one) and then use SiftUp to arrange the heap in correct order
		array[index].cost = value;
		
		//updating the cost value in array arr
		int v = array[index].vertex;
		arr[v-1].cost = value;
		
		SiftUp(array, index,heapSize);
	}
}

void Delete(int index, heapptr array, int * Size)
{
	//case when we are deleting the element which is not in heap
	if(index > ((*Size) - 1) || ((*Size) == 0))
		printf("Operation Fail\n");
	else
	{
		//replacing the element to be deleted(if its not the last one itself) with last element of heap, decrementing heap Size and then arranging the heap
		
		if(index < (*Size - 1))
		{
			array[index] = array[(*Size) - 1];
			
		}
		(*Size)-- ;
		MinHeapify(index, array, *Size);
	}
	return;
}


void PrimsAlgo(int s,int n)
{
	heapptr minheap;
	//minheap is the pointer to array of nodes in heap
	
	//allocating the space to heap using malloc function
	minheap = (heapptr)malloc(n*sizeof(struct heapnode));
	
	if(minheap == NULL)
		exit(1);
	
	//initializing the vertex and cost value for heap nodes 
	for(int i = 0; i<n;i++)
	{
		minheap[i].vertex = i+1;
		minheap[i].cost = inf;	
	}
	
	//source vertex is the only element in S  
	arr[s-1].included = 1;
	
	//going through the adjacency list of s, we update the distance(cost) value of its neighbouring elements,and also pred value
	for(nodeptr adj = (arr[s-1].vertex)->next ; adj != NULL; adj = adj->next)
	{
		int u = adj -> element;
		int w = adj -> EdgeWeight;
		arr[u-1].cost = w;
		arr[u-1].pred = s;
		minheap[u-1].cost = w;
	}
	
	
	int heapSize = n;
	//creating heap of verices in set S complement
	BuildHeap(minheap, heapSize);
	
	//since s is include in set S, we delete it from heap
	int sourcePos = arr[s-1].position;
	Delete(sourcePos, minheap, &heapSize);
	
	
	//while heap is not empty	
	while(heapSize != 0)
	{
		int v = FindMin(minheap,heapSize);
		//v is the vertex in S complement with minimum distance from set S elements
		ExtractMin(minheap, &heapSize);
		
		//deleting it from heap
		//printing the endpoints of edge being added to MST, along with its weight
		
		printf("%d %d %d\n", arr[v-1].pred, v, arr[v-1].cost);
		
		
		for(nodeptr adj = (arr[v-1].vertex)->next ; adj != NULL; adj = adj->next)
		{
			//for all neighbours of v, if they are not yet included in MST; 
			int u = adj-> element;
			int w = adj->EdgeWeight;
			if(arr[u-1].included != 1)
			{
				if(arr[u-1].cost > w)
				{
					//if cost value for v is shorter than originally found for u, then decreasing the cost value in heap
					DecreaseKey(minheap, arr[u-1].position, w,heapSize);
					//settig the pred, if updation occurs
					arr[u-1].pred = v;
										
				}
			}
	
		}
	}
					
}

int main()
{	
	//taking number of vertices as input
	int n;
	scanf("%d", &n);
	
	//allocating space to array arr using malloc function
	arr = (properties)malloc(n * (sizeof(struct vert)));
	
	if(arr == NULL)
		exit(1);
	
	//initializing the array with properties of vertices	
	for(int i = 0; i < n ; i++)
	{
		arr[i].cost = inf;
		arr[i].pred = -1;
		arr[i].position = i;
		arr[i].included = 0;
		nodeptr head = (nodeptr)malloc(sizeof(struct node));
		head -> element = i+1;
		head -> EdgeWeight = 0;
		head -> next = NULL;
		arr[i].vertex = head;
	}	
	
	int k = 0,w = 0;
	for(int i = 0; i<n; i++)
	{
		//taking list of outneighbours of vertex (i+1),and their edge weight as input from user
		while(1)
		{	
			scanf("%d", &k);
			if(k == -1) break;
			scanf("%d", &w);
			
			//creating edge (i+1)->k
			createAdjList(arr,i,k,w);
						
		}	
	}
	
	//taking source vertex as input
	int source = 0;
	scanf("%d", &source);

	//calling Prims Algo. to find the MST of the graph given
	PrimsAlgo(source,n);
					
}