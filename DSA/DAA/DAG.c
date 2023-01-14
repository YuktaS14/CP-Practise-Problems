#include <stdio.h>
#include <stdlib.h>

//structure for creating nodes of linked list (Adjacency List) and also for creating stack
typedef struct node
{
	int element;
	struct node* next;	
}Node;

typedef struct node* nodeptr;
nodeptr stackptr = NULL,top = NULL;

//structure for storing properties of vertices,which also contains pointer of struct node datatype which store the vertex value and pointer to its linked list
struct vert
{
	int entry;
	int exit_T;
	int pred;
	int visited;
	nodeptr vertex;
};
typedef struct vert* properties;

//to add elements into stack
void push(int num)
{
	//creating a nodeptr for adding new node
	stackptr = (nodeptr)malloc(sizeof(struct node));
	stackptr -> element = num;
	stackptr -> next = NULL;
	
	if(stackptr == NULL)
	{
		printf("Push Failure\n");
		exit(1);
	}
	
	if(top == NULL)
		//case when stack is empty
		top = stackptr;
	else
	{
		//linking stackptr - top and updating top
		stackptr -> next = top; 
		top = stackptr;
	}
}

//deleting the last input
void pop()
{
	//creating temp pointer to point to element which has to be deleted
	nodeptr temp = NULL;
	temp = (nodeptr)malloc(sizeof(struct node));
	temp = top;
	
	if(temp == NULL)
		printf("Pop Failure\n");
	
	else
	{
		//updating top to next position, discarding the linkage and then freeing the temp pointer 
		top = top -> next;
		temp -> next = NULL;
		printf("%d\n", temp -> element);
		free(temp);
	}
	
}

//function to create newnode
nodeptr createNode(int n)
{
	nodeptr newNode = NULL;
	newNode = (nodeptr)malloc(sizeof(struct node));
	
	if(newNode == NULL)
		exit(1);
	
	//newnode stores value of vertex while its next pointer is initiated to NULL
	newNode -> element = n;
	newNode -> next = NULL;
	return newNode;
}

//function to create graph by adding vertices in Adjacency List
//it takes array and vertices having edge(i->k) as arguments
void createAdjList(properties arr, int i, int k)
{
	nodeptr new1 = NULL;
	nodeptr prev1 = NULL,cur1 = NULL;
	
	//creates a node with value of 2nd vertex
	//and links it to linked list pointed by the 1st vertex
	new1 = createNode(k);
	cur1 = arr[i].vertex;
		
	while(cur1 != NULL)
	{
		prev1 = cur1;
		cur1 = cur1 -> next;
	}
	prev1 -> next = new1;
}

int clock = 0;
//initiating clock = 0;


void DfsExplore(properties arr, int v)
{
	//whenever a vertex is visited store 1 in the [v-1] index of array(as it contains the properties of vertex v),store its entry time and increment clock
	arr[v-1].visited = 1;
	
	arr[v-1].entry = clock;
	clock++ ;
	
	//using pointer to traverse through its neighbours and check whther its vertices are visited or not
	nodeptr Nbr = NULL;
	Nbr = arr[v-1].vertex;
	Nbr = Nbr -> next;
	
	
	while(Nbr != NULL)
	{
		int u = Nbr -> element;
		//if the neighbour vertex(u) is not visited then call the function again for that vertex
		if(arr[u-1].visited == 0)
		{
			arr[u-1].pred = v;
			//u vertex pred = v
			DfsExplore(arr, u);
		}
		//go to next neighbour
		Nbr = Nbr -> next;
	}
	//record exit time for that vertex and increment the clock
	arr[v-1].exit_T = clock;
	//push the vertex into stack
	push(v);
	clock++ ;
}

//starts the exploration of graph from vertex given and then goes through all vertices even in disconnected graph
void DepthFirstSearch(properties arr, int n, int start)
{
	DfsExplore(arr,start);
	
	for(int v = 1; v <= n; v++)
	{
		//vertex v properties would be present at [v-1] index of the array
		if(arr[v-1].visited == 0)
			DfsExplore(arr,v);
	}
	return;
}

//function to print the entry,exit time and pred for each vertex
void Print(properties arr, int n)
{
	for(int i = 0; i < n; i++)
	{
			printf("%d %d %d\n",arr[i].entry, arr[i].exit_T, arr[i].pred);
	}
}

//stack contains vertices in the decreasing order of exit time(top will have max exit time), so we pop to get order
void TopologicalOrd(properties arr, int n)
{
	while(top != NULL)
	{
		pop();
	}
}


void DAG(properties arr, int n)
{
	int flag = 0;
	//flag is updated if a back edge is found
	for(int i = 1; i<=n; i++)
	{
		//edge pointer traverse through adj.list of vertex i
		nodeptr edge = NULL;
		edge = arr[i-1].vertex;
		edge = edge -> next;
		while(edge != NULL)
		{
			//u = neighbouring element of vertex i
			//checking the exit time of u..if its exit time is greater than vertex i, then its back edge
			int u = edge -> element;
			if(arr[i-1].exit_T < arr[u-1].exit_T)
			{
				if(flag == 0)
				{
					printf("Not a DAG\n");
					flag = 1;
				}
				//printing the entry and exit times of vertices having back edge
				printf("%d %d %d %d\n", arr[u-1].entry, arr[i-1].entry, arr[i-1].exit_T, arr[u-1].exit_T);
				
			}
			edge = edge -> next;
		}
		
		
	}
	if(flag == 0)
	{
		printf("DAG\n");
		TopologicalOrd(arr,n);
	}
}

int main()
{
	//taking no. of vertices as input from user
	int n;
	scanf("%d", &n);

	//creating a pointer which points to the array of nodes
	//these nodes store the properties of vertices
	properties arr;
	//allocating the memory to array dynamically using malloc
	arr = (properties)malloc(n * (sizeof(struct vert)));
	
	//initializing the properties
	//head points to a node which contains vertex value and has pointer to adj.list of the vertex
	for(int i = 0; i < n ; i++)
	{
		arr[i].entry = -1;
		arr[i].exit_T = -1;
		arr[i].pred = -1;
		arr[i].visited = 0;
		nodeptr head = (nodeptr)malloc(sizeof(struct node));
		head -> element = i+1;
		head -> next = NULL;
		arr[i].vertex = head;
	}		
	
	int k = 0;
	for(int i = 0; i<n; i++)
	{
		//taking list of outneighbours of vertex (i+1) from user
		while(1)
		{	
			scanf("%d", &k);
			if(k == -1) break;
			//creating edge (i)->k
			createAdjList(arr,i,k);				
		}	
	}
	
	//taking vertex from which to start exploring as input from user	
	int S_Vertex;
	scanf("%d", &S_Vertex);
	
	//calling function to explore through graph
	DepthFirstSearch(arr, n, S_Vertex);
	
	//calling print function to print the entry and exit time
	Print(arr, n);	
	//calling DAG to check if its cyclic and printing backedges
	DAG(arr,n);		
	return 0;
}