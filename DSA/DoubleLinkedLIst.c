#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int data;
	struct node* next;
	struct node* prev;
}Node;

typedef struct node* nodeptr;

int main()
{
	nodeptr first = NULL, last = NULL, newptr = NULL, curptr = NULL, temp = NULL;
	int n, x;
	scanf("%d", &n);
	//taking number of elements as input from the user
	
	//initialsing the list by creating 1st node
	newptr = (nodeptr)malloc(sizeof(struct node));
	scanf("%d", &x);
	newptr -> data = x;
	newptr -> prev = NULL;
	newptr -> next = NULL;
	first = newptr;
	last = newptr;
		
	for(int i = 1; i < n; i++)
	{
		//with each iteration taking new node as input from the user
		newptr = (nodeptr)malloc(sizeof(struct node));
		scanf("%d", &x);
		
		newptr -> data = x;
		newptr -> prev = NULL;
		newptr -> next = NULL;
		
		//creating double link between prev aand new node
		last -> next = newptr;
		newptr -> prev = last;
		
		last = newptr;								
	}	
	
	//printing all the elements of doubly-linked list from front to back
	curptr = first;
	while(curptr != NULL)
	{
		printf("%d\n", curptr -> data);
		curptr = curptr -> next;
	}
	
	//printing all the elements of doubly-linked list from back to front
	curptr = last;
	while(curptr != NULL)
	{
		printf("%d\n", curptr -> data);
		curptr = curptr -> prev;
	} 
	
	//removing the first element of the list, discarding the linkings associated with it and updating the first pointer
	temp = first;
	curptr = first -> next;
	temp -> next = NULL;
	curptr -> prev = NULL;
	
	first = curptr;
	free(temp);
	
	//removing the last element of the list, discarding the linkings associated with it and updating the last pointer
	temp = last;
	curptr = last -> prev;
	temp -> prev = NULL;
	curptr -> next = NULL;
	
	last = curptr;
	free(temp);
	
	//printimg the elements of doubly-linked list from front to back
	curptr = first;
	while(curptr != NULL)
	{
		printf("%d\n", curptr -> data);
		curptr = curptr -> next;
	}
	
	//printing the elements of doubly-linked list from back to front
	curptr = last;
	while(curptr != NULL)
	{
		printf("%d\n", curptr -> data);
		curptr = curptr -> prev;
	}
		  
	return 0;
}