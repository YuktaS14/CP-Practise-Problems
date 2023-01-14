#include <stdio.h>

typedef struct node
{
	int element;
	struct node* next;
}Node;

typedef struct node* nodeptr;
//defining a structure to create nodes that will form a linked list

int main()
{
	Node node1, node2, node3, node4, node5;
	//creating 5 nodes to store the values in linked list
	
	
	nodeptr first = NULL,prev = NULL, newcur = NULL, cur = NULL;
	//pointers: first contains the address of node1, prev points to the previous node whereas newcur points to current node of sorted linked list, here for every iteration cur points to new nodes. 
	 
	//taking nodes as inputs from the user and then linking them later in sorted manner. 
	scanf("%d", &(node1.element));
	node1.next = NULL;
	first = &node1;
	scanf("%d", &(node2.element));
	node2.next = NULL;
	scanf("%d", &(node3.element));
	node3.next = NULL;
	scanf("%d", &(node4.element));
	node4.next = NULL;
	scanf("%d", &(node5.element));
	node5.next = NULL;
	
	//initializing the sorted linked list by 1st node
	newcur = first;
	printf("%d\n",newcur -> element);
	
	for(int i=2;i<=5;i++)
	{
		int flag = 0, count = 0;
		//flag pointer ensures whether our cur element has been placed in sorted linked list or not
		//whereas count is used to check whether cur element is smaller than the first element of the sorted list or not as in that case count value will still remain 0
		
		//going through sorted list from beginning by initializing newcur to first each time
		newcur = first;
	
		//for insertion of each new node we consider cases depending on i and make cur pointer to point the new node	
		switch(i)
		{
			case 2: cur=&node2;
				break;
			case 3: cur=&node3;
				break;
			case 4: cur=&node4;
				break;
			case 5: cur=&node5;
				break;
		}
		
		//till we reach end of sorted list	
		while(newcur != NULL)
		{
			//element from next node < element from sorted list
			if((cur -> element) < (newcur -> element))
			{
				if(count == 0)
				//case when insertion is to be done at the first place
				{
					//linking cur with prev first element and updating first pointer
					//breaking through loop as we have inserted a node
					cur -> next = first;
					first = cur;
					flag = 1;
					count ++;
					break;
				}
				//case when element is to be inserted in between 2 elements of sorted list
				//linking prev - cur - newcur and breaking through the loop as insertion is complete
				cur -> next = newcur;
				prev -> next = cur;
				flag = 1;
				break;
			}
			//traversing to next element of sorted list and incrementing count
			prev = newcur;
			newcur = newcur -> next;
			count++;
		}
		
		//case when element from new node(pointed by cur) is largest than all elements of existing sorted list
		if(flag == 0)
		{
			//linkng prev - cur ,in this case newcur will point to NULL
			cur -> next = NULL;
			prev -> next = cur;
		}
		
		//printing the elements of sorted list after each iteration by traversing through the sorted linked list
		newcur = first;		
		while(newcur != NULL)
		{
			printf("%d\n",newcur -> element);
			newcur = newcur -> next;
		}
	}
        
        return 0;


//  After the first iteration, \(L\) contains only the first input element.  In general, at the beginning of \(i^{th}\)  iteration, \(L\) contains the first \(i-1\) input elements in their ascending order. In the \(i^{th}\) iteration, the \(i^{th}\) input element is inserted into \(L\) just before the first element in \(L\) which is greater than it (or at the end of \(L\) if all elements in \(L\) are smaller than or equal to the element being inserted). After \(5\) iterations, the list \(L\) contains all input elements, in sorted order.  After each iteration, traverse the linked list and print its elements as output. 