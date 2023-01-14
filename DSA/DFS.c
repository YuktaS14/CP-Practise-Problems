#include <stdio.h>
#include <stdlib.h>

//structure for creating nodes of linked list (Adjacency List)
struct node
{
	int num;
	struct node* next;	
};

typedef struct node* AdjElement; 

//function to create newnode
AdjElement createNode(int n)
{
	AdjElement newNode = NULL;
	newNode = (AdjElement)malloc(sizeof(struct node));
	
	if(newNode == NULL)
		exit(1);
	
	//node stores value of vertex while its next pointer is initiated to NULL
	newNode -> num = n;
	newNode -> next = NULL;
	return newNode;
}

//function to create graph by adding vertices in Adjacency List
//it takes array and 2 vertices having edge as arguments
void createGraph(AdjElement arr, int v1, int v2)
{
	AdjElement new1 = NULL, new2 = NULL;
	AdjElement prev1 = NULL, cur1 = NULL, prev2 = NULL, cur2 = NULL;

	//creates a node with value of 2nd vertex
	//and links it to linked list pointed by the 1st vertex
	new1 = createNode(v2);
	cur1 = &arr[v1];
	
	while(cur1 != NULL)
	{
		prev1 = cur1;
		cur1 = cur1 -> next;		
	}
	prev1 -> next = new1;
	
	//similarly creates a node with value of 1st vertex
	//and links it to linked list pointed by the 2nd vertex in array 	
	new2 = createNode(v1);
	cur2 = &arr[v2];
	
	while(cur2 != NULL)
	{
		prev2 = cur2;
		cur2 = cur2 -> next;		
	}
	prev2 -> next = new2;	
}

int clock = 0;

//index i element of array visited indicates if vertex i is visited before or not
//and arrays entry and exit_T stores the entry and exit time respect. for that vertex 
int *visited, *entry, *exit_T;

void DfsExplore(AdjElement arr, int v)
{
	//whenever a vertex is visited store 1,store its entry time and increment clock
	visited[v] = 1;
	entry[v] = clock;
	clock++ ;
	
	//using pointer to go traverse through its neighbours and check whther its vertices are visited or not
	AdjElement Nbr = NULL;
	Nbr = &arr[v];
	Nbr = Nbr -> next;
	
	while(Nbr != NULL)
	{
		int u = (Nbr -> num);
		//if the neighbour vertex is not visited then call the function again for that vertex
		if(visited[u] == 0)
		{
			DfsExplore(arr, u);
		}
		//go to next neighbour
		Nbr = Nbr -> next;
	}
	//record exit time for that vertex and increment the clock
	exit_T[v] = clock;
	clock++ ;
}

//starts the exploration of graph from vertex given and then goes through all vertices even in disconnected graph
void DepthFirstSearch(AdjElement arr, int n, int start)
{
	for(int v = 0; v < n; v++)
	{
		visited[v] = 0;
		entry[v] = -1;
		exit_T[v] = -1; 	
	}
	
	DfsExplore(arr,start);
	
	for(int v = 0; v < n; v++)
	{
		if(visited[v] == 0)
			DfsExplore(arr,v);
	}
	return;
}

//function to print the entry and exit time for each vertex
void Print(AdjElement arr, int n)
{
	AdjElement p = NULL;
	for(int i = 0; i < n; i++)
	{
		p = &arr[i];
			
		printf("%d %d\n",entry[i], exit_T[i]);
	}
}

int main()
{
	//taking no. of vertices and edges as input from user
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	
	//creating a pointer which points to the array of nodes
	//these nodes have vertices as their num and points to linked list containing the neighbours of that respective vertex 
	AdjElement arr;
	arr = (AdjElement)malloc(n * (sizeof(struct node)));
	if(arr == NULL)
	    exit(1);
	    
	for(int i = 0; i < n ; i++)
	{
		arr[i].num  = i;
		arr[i].next = NULL;	
	}	
	
	int v1 = 0, v2 = 0;
	//taking vertices having edge between as input from user
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &v1, &v2);
		//calling a function to arrange the vertices in the Adjacency List
		createGraph(arr, v1,v2);
	}
	
	//allocating the memory to array dynamically uin malloc
	visited = malloc(n * sizeof(int));
	entry =  malloc(n * sizeof(int));
	exit_T = malloc(n * sizeof(int));
	
	//taking vertex from which to start exploring as input from user	
	int S_Vertex;
	scanf("%d", &S_Vertex);
	
	//calling function to explore through graph
	DepthFirstSearch(arr, n, S_Vertex);
	
	//calling print function to print the entry and exit time
	Print(arr, n);			
	return 0;
}