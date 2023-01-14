#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define inf 99999

//structure for creating nodes of edgeList
//a node stores the vertices and the edgeWeight of edge between them 
typedef struct edge
{
	int vertex1;
	int vertex2;
	int EdgeWeight;
		
}edges;

typedef struct edge* nodeptr;


//structure for storing properties of vertices->shortest distance from source and the predecessor in this path
typedef struct vert
{
	int dist;
	int pred;
	
}Vert;

typedef struct vert* vertex;


//function to print the shortest dist and pred of each vertex
void PrintEdge(int n, vertex VertList)
{
	for(int i = 0; i < n; i++)
	{
		if(VertList[i].dist != inf)
		{
			printf("%d %d", VertList[i].dist, VertList[i].pred);
			printf("\n");
		}
		else
		    ////case when vertex is not reachable from source,then dist from source will remain inf
			printf("Unreachable\n");
			
	}
}


//function to print vertices in negative weight cycle
void negativeWeightCycle(vertex VertList, int v, int n,int Cycle[])
{
	//we trace back the pred of vertex v (which got updated first in nth round) 
	int prev = VertList[v-1].pred;
	
	//and place those in array named cycle 
	int k = 0;
	//we trace back through pred till we find v again as pred and till k<n
	//because at max cycle can contain n vertices,hence checking if k<n
	while((prev != v) && k < n)
	{
		
		Cycle[k] = prev;
		k++;
		int temp = VertList[prev-1].pred;
		prev = temp;		
	}
	
	if(k < n)
	{	
		//case when a cycle is found,
		//we just print the vertices stored in cycle in reverse order,so as to get output correctly	
		for(int i = (k-1); i>=0; i--)
		{
			printf("%d ",Cycle[i]);
			
		}
		//printing the vertex v at last
		printf("%d\n",v);
	}
	else
	{	
		//case when vertex v found is not in cycle,
		//then while tracing through pred, we would have found a vertex which lies on cycle,then again calling the function with pred of v as an argument, and checking if that lies on cycle...if it lies then printing the cycle else repeating the function call
		negativeWeightCycle(VertList, VertList[v-1].pred,n,Cycle);		
	}
		
}


void BellmanAlgo(int n, int m,int s, nodeptr arr, vertex VertList,int Cycle[])
{
	//updating the distance and pred of source vertex
	VertList[s-1].pred = -1;
	VertList[s-1].dist = 0;
	
	//updateFlag is set to 1 if any edge relaxation occurs in a round
	int updateFlag;
	//v stores the first vertex which get updated in a round
	int first = 0; int v = 0;
	for(int j = 0; j < n; j++)
	{
		//relaxing all edges n times(for n rounds)
		updateFlag = 0;first = 0;
		for(int i = 0; i < m; i++)
		{
			//relaxing edges as per input order
			int v1 = arr[i].vertex1;
			int v2 = arr[i].vertex2;
				
			//updating the distance of vertex (v2) if shorter distance is found through (v1)
			if((VertList[v2-1].dist > (VertList[v1-1].dist + arr[i].EdgeWeight)))
			{
				if(first == 0)
				{
					//updating first when we find the first vertex that gets updated in a round 
					first = 1;
					v = v2;
				}
				
				VertList[v2-1].dist = (VertList[v1-1].dist + arr[i].EdgeWeight);
				
				//setting the predecessor of updated vertex(v2)						
				VertList[v2-1].pred = v1;
				updateFlag = 1;
				
			}
		}
		//if at any round updateFlag remains 0,means no edge relaxation occurs and will not happen further, thus breaking through loop
		if(updateFlag == 0)
			break;
	}
	
	if(updateFlag == 1)
	{
		//if even at nth round edge relaxation occurs,then we are guarantted that the graph contains a negaive weight cycle.
		negativeWeightCycle(VertList,v,n,Cycle);
	}
	//after nth round if update flag is 0,that means no relaxation occurs in nth round, hence no negative weight cycle is present,therefore printing the distance from source and pred of each vertex 
	else
		PrintEdge(n,VertList);
	
}



int main()
{
	//taking no. of vertices, and no. of edges as input from user
	int n,m;
	scanf("%d", &n);
	scanf("%d", &m)	;

	//creating a pointer of nodeptr type which points to the array of nodes(storing edge list)
	nodeptr arr = NULL;
	
	//creating a pointer of vertex type which points to the array of nodes(storing properties of vertices)
	vertex VertList = NULL;
	
	//allocating the memory to arrays dynamically using malloc
	arr = (nodeptr)malloc(m * (sizeof(struct edge)));
	VertList = (vertex)malloc(n * (sizeof(struct vert)));
	
	if(arr == NULL || VertList == NULL)
		exit(1);
	
	for(int i = 0; i<m; i++)
	{
		//taking the edges (endpoints of each edge and the edge weight) as input from user
		int value1,value2,edgeW;
		scanf("%d %d %d", &value1, &value2, &edgeW);
			
		//storing the edges in edgelist	as per input order			
		arr[i].vertex1 = value1;
		arr[i].vertex2 = value2;
		arr[i].EdgeWeight = edgeW;
	}
	
	//initializing the properties of vertices 
	for(int i = 0; i< n; i++)
	{
		VertList[i].pred = -1;
		VertList[i].dist = inf;
	}
	
	//taking source as input from user
	int source;
	scanf("%d", &source);
	
	//an array to store vertices in cycle
	int Cycle[n];
	
	//calling function to implement Bellman algorithm
	BellmanAlgo(n, m, source, arr,VertList,Cycle);
	
				
	return 0;
}