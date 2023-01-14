#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int element;
	struct node* next;
}Node; 

typedef struct node* nodeptr;

nodeptr newptr = NULL,front = NULL, back = NULL;

//function to check whether queue is empty or not
void isEmpty()
{
	if(front == NULL || back == NULL)
		printf("Empty\n");
	else
		printf("Non Empty\n");
}

//to add element into queue
//element is added at the back in queue

void enqueue(int num)
{
	newptr = (nodeptr)malloc(sizeof(struct node));
	newptr -> element = num;
	newptr -> next = NULL;
	
	if(newptr == NULL)
	{
		printf("Enqueue Failure\n");
		exit(1);
	}
	
	if(front == NULL)
	{	//case when queue is empty
		front = newptr;
		back = newptr;
	}
	else
	{
		//linking back - newptr and updating back
		back -> next = newptr; 
		back = newptr;
	}
}

//deleting the first input in dequeue function
void dequeue()
{
	//creating temp pointer to point to element which has to be deleted
	nodeptr temp = NULL;
	temp = (nodeptr)malloc(sizeof(struct node));
	temp = front;
	
	//case when list is empty or pointer is not created successfully
	if(temp == NULL)
		printf("Dequeue Failure\n");
	
	else
	{
		//updating front to next position, discarding the linkage and then freeing the temp pointer 
		front = front -> next;
		printf("%d\n", temp -> element);
		temp -> next = NULL;
		free(temp);
	}
	
}

//printing the first element
void peek()
{
	if(front == NULL)
		printf("Empty queue\n");
	else
		printf("%d\n", front -> element);
}

//printing all the elements of queue from front to back;
void display()
{
	if(front == NULL)
		printf("Empty List\n");
	else
	{
		nodeptr temp = NULL;
		//traversing through stack and printing
		temp = front;
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
			enqueue(num);
		}
		else if(n == 2)
			dequeue();
		else if(n == 3)
		    peek();
		else if(n == 4)
			display();
    	else if(n == 5)
			exit(1);
	}

	return 0;
}