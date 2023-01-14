#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int element;
	struct node* next;
}Node; 

typedef struct node* nodeptr;

nodeptr cur = NULL, newptr = NULL, first = NULL, prev = NULL;
//pointers: first contains the address of first element of sorted list, prev points to the previous node whereas cur points to current node of sorted linked list, here for every iteration newptr points to newly made node. 
	
int main()
{
	newptr = (nodeptr)malloc(sizeof(struct node));
	int n, x;
	//taking no. of elements as input
	scanf("%d", &n);
	
	//taking the first element as input and creating first node 	
	scanf("%d", &x);
	newptr -> element = x;
	newptr -> next = NULL;
	first = newptr;
		
	cur = first;
		
	for(int i = 2; i <= n; i++)
	{
		//flag pointer ensures whether our newptr element has been placed in sorted linked list or not
		//whereas count is used to check whether newptr element is smaller than the first element of the sorted list or not as in that case count value will still remain 0
		//going through sorted list from beginning by initializing cur to first each time		
		int count = 0, flag = 0;
		cur = first;
		
		//creating new node each time using malloc
		newptr = (nodeptr)malloc(sizeof(struct node));
		scanf("%d", &x);
		newptr -> element = x;
		newptr -> next = NULL;
		
		//till we reach end of sorted list	
		while(cur != NULL)
		{
			//element from new node < element from sorted list
			if((newptr -> element) < (cur -> element)) 
			{
				if(count == 0)
				{
					//case when insertion is to be done at the first place
					//linking newptr with prev first element and updating first pointer
					//breaking through loop as we have inserted new node
					newptr -> next = first;
					first = newptr;
					flag = 1;
					count = 1;
					break;
				}
				
				//case when element is to be inserted in between 2 elements of sorted list
				//linking prev - newptr - cur and breaking through the loop as insertion is complete
				newptr -> next = cur;
				prev -> next = newptr; 
				flag = 1;
				break;
			}
			
			//traversing to next element of sorted list and incrementing count
			prev = cur; 
			cur = cur -> next; 
			count++;
		}
		
		//case when element from new node(pointed by newptr) is largest than all elements of existing sorted list
		if(flag == 0)
		{
			//linkng prev - newptr ,in this case newcur will point to NULL
			newptr -> next = NULL;
			prev -> next = newptr;
		}
			
	}
	
	//printing the elements after sorting	
	cur = first;
	while(cur != NULL )
	{
		printf("%d\n",cur -> element);
		cur = cur -> next;
	}
        
    return 0;
}		