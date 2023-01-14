#include<stdio.h>
#include<stdlib.h>

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

//function to print the graph
void printGraph(AdjElement arr, int n)
{
	AdjElement p = NULL;
	for(int i = 0; i < n; i++)
	{
		//pointer p points to elements of array(vertices) and traverses through the linked list associating with it
		p = &arr[i];
		p = p -> next;
		
		//case when the vertex has no neighbours
		if(p == NULL)
		{
			printf("Nil\n");
			continue;
		}
		else
		{	
			//printing the first neighbour  
			printf("%d", p -> num);
			p = p -> next;
		}
			
		while(p != NULL)
		{
			//printing the neighbours while traversing through the linked list
			printf(" %d", p -> num);
			p = p -> next;
		}
		printf("\n");
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
	
	//printing the graph formed by traversing through its Adjacency list	
	printGraph(arr,n);
	
	return 0;	
}