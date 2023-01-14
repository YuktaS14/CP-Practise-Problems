#include <stdio.h>
#include <stdlib.h>

int n;
int *parent;
int *rank;

void MakeSet(int x)
{
	//each element is a set and thus has parent as itself,its rank is 0
	parent[x-1] = x;
	rank[x-1] = 0;
}

int Find(int x)
{
	//traversing back through parents from x, till we reach root of tree(or reprentative of set containing x) and returning this root  
	int root = x;
	while(parent[root-1] != root)
	{
		root = parent[root-1];
	}
	
	//compressing the paths of intermediate parent elements, by attaching them directly to the root(representative element by changing the parent of such intermediate elements) 
	int z = x;
	
	while (parent[z-1] != z)
	{
		int p = parent[z-1];
		parent[z-1] = root;
		z = p;
	}
	return root;
}

void Union(int x,int y)
{
	//p1,p2 contains the representative of the set in which x,y are present.
																																				
	int p1 = Find(x);
	int p2 = Find(y);
	int newR = 0;
	
	//case when x,y are present in same set
	if(p1 == p2)
		return;
	else
	{
		//storing the rank of each representative
		int r1 = rank[p1-1];
		int r2 = rank[p2-1];
		
		if(r1 == r2)
		{
			//when ranks of both are same, we add set containing y, into set containing x,thus representive of both elements are is now p1
			parent[p2-1] = p1;
			rank[p1-1] = rank[p1-1] + 1;
			newR = p1;			
		}
		//else we add the set with smaller rank epresentative into bigger set, thus new representative of both elements is th one whivch has greater rank
		else if(r1 < r2)
		{
			parent[p1-1] = p2;
			newR = p2;
		}
		else
		{
			parent[p2-1] = p1;
			newR = p1;
		}
	}
	
	//printing the representative of set after union along with its rank.
	printf("%d %d\n",newR, rank[newR-1]);
}


void Print()
{
	for(int i = 0; i<n; i++)
	{
		//printing the element and its representative
		int representative = Find(i+1); 
		printf("%d %d\n",i+1, representative);
	}
}

int main()
{
	//univeral set contains n elements
	scanf("%d", &n);
	
	//creating 2 array which stores the parent and the rank of each element
	parent = malloc(n * sizeof(int));
	rank = malloc(n * sizeof(int));
	
	
	int opt = 0;
	
	//creating a singleton set for each element
	for(int i = 0; i<n; i++)
	{
		MakeSet(i+1);
	}
	
	while(1)
	{
		scanf("%d",&opt);
		if(opt == 1)
		{
			//taking element from user on which find operation is to be performed
			int x;
			scanf("%d",&x);
			//find returns the representative of set containing element x 
			int root = Find(x);
			printf("%d\n", root);
		}	
		else if(opt == 2)
		{
			//performing union operation on the elements given by user
			int x,y;
			scanf("%d %d",&x,&y);
			Union(x,y);
		}
		else if(opt == 3)
			//printing each element and its representative
			Print();
		else if(opt == 4)
			//option to exit the program
			exit(1);

	}
	return 0;
}