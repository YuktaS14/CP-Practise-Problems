#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int element;
	struct node* next;
}Node; 

typedef struct node* nodeptr;

nodeptr newptr = NULL,top = NULL;

//function to check whether stack is empty or not
void isEmpty()
{
	if(top == NULL)
		printf("Empty\n");
	else
		printf("Non Empty\n");
}

//to add element into stack
void push(int num)
{
	newptr = (nodeptr)malloc(sizeof(struct node));
	newptr -> element = num;
	newptr -> next = NULL;
	
	if(newptr == NULL)
	{
		printf("Push Failure\n");
		exit(1);
	}
	
	if(top == NULL)
		//case when stack is empty
		top = newptr;
	else
	{
		//linking newptr - top and updating top
		newptr -> next = top; 
		top = newptr;
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

//printing the top element
void TOP()
{
	if(top == NULL)
		printf("Empty Stack\n");
	else
		printf("%d\n", top -> element);
}

//printing all the elements of stack 
void display()
{
	if(top == NULL)
		printf("Empty List\n");
	else
	{
		nodeptr temp = NULL;
		//traversing through stack and printing
		temp = top;
		while(temp != NULL)
		{
			printf("%d\n", temp -> element);
			temp = temp -> next;
		}
	}
}

int main()
{
	int n;
	while(1)
	{
		//prompting the user to enter a value among 0,1,2,3,4,5 and calling the corresponding function
		scanf("%d" , &n);
		
		if(n == 0)
			isEmpty();
		else if(n == 1)
		{
			int num;
			scanf("%d", &num);
			push(num);
		}
		else if(n == 2)
			pop();
		else if(n == 3)
		    TOP();
		else if(n == 4)
			display();
    	else if(n == 5)
			exit(1);
	}

	return 0;
}