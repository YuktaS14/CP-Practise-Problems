#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int element;
	struct node* next;
}Node;

typedef struct node* nodeptr;
//defining a structure to create nodes that will form a linked list

int main()
{
	int n;
	Node node1, node2, node3, node4, node5, node6;
	//creating 6 nodes to store the values in linked list
	
	nodeptr first = NULL,prev = NULL, curptr = NULL;
	//pointers: first contains the address of node1, prev points to the previous node than the node which curptr points to
	 
	//taking inputs from the user and linking each node with each other 
	scanf("%d", &(node1.element));
	first = &node1;
	scanf("%d", &(node2.element));
	node1.next = &node2;
	scanf("%d", &(node3.element));
	node2.next = &node3;
	scanf("%d", &(node4.element));
	node3.next = &node4;
	scanf("%d", &(node5.element));
	node4.next = &node5;
	node5.next = NULL;
	
	//taking new integer as input from the user
	scanf("%d", &(node6.element));
	node6.next = NULL;
	
	curptr = first;
	//curptr now points to the address of first node,thus enabling us to traverse through all nodes subsequently
	for(int i = 0; i < 5; i++)
	{
		//printing the elements of linked list
		printf("%d\n", curptr -> element);
		curptr = curptr -> next;
	}

	curptr = first;
	prev = curptr;
	int count = 1;
	//count value at the end ensures whether we have found an element within the 5 nodes which is greater than node6 element or not   
	//we increment count and then break trough whenever greater element is found in first 5 nodes.
		 
	for(int i = 0; i < 5; i++)
	{
		//for the case when element has to be inserted at the first position i.e node1 element itself is greater than new integer 
		if(node1.element > node6.element)
		{
			//first now would contain address of node6 and node6 will link to node1 element
			first = &node6;
			node6.next = &node1;
			count++;
			break;
		}
		
		//case when inserion is to be done between the nodes
		else if(((curptr -> element) > (node6.element)) && (count == 1))
		{
			//here now we link previous node to the node6 and then link node6 to the node pointed by curptr pointer thus inserting between.
			prev -> next = &node6;
			node6.next = curptr;
			count ++;
			break;
		}
		
		//updating prev and curptr inorder to check for next node after each iteration
		prev = curptr;
		curptr = curptr -> next;
	}
	
	//case when there is no element greater than new integer (or node6 element) in first 5 nodes
	if(count == 1)
	{
		//linking node5 with node6
		node5.next = &node6;
	}
	
	curptr = first;
	//curptr now points to the address of first node,thus enabling us to traverse through all nodes subsequently
	for(int i = 0; i < 6; i++)
	{
		//printing the elements of linked list containing 6 elements
		printf("%d\n", curptr -> element);
		curptr = curptr -> next;
	}
		
	return 0;
}
