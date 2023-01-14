#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//creating a node to store tree
struct tree
{
	char key;
	struct tree* left;
	struct tree* right;
};

typedef struct tree* treeptr;

treeptr t_ptr = NULL, root = NULL, p = NULL;

//creating a node of stack which stores pointer to a tree as its element and uses next for linking
struct node
{
	treeptr element;
	struct node* next;
};

typedef struct node* nodeptr;

nodeptr newptr = NULL,top = NULL, temp = NULL;

//pushing a tree in stack using pointer to the tree
void push(treeptr S_tree)
{
	//creating new node in stack
	newptr = (nodeptr)malloc(sizeof(struct node));
	newptr -> element = S_tree;
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

//pop function deletes the top node from stack and here it returns the pointer to the tree, which is the element of the node being deleted   
treeptr pop()
{
	//creating temp pointer to point to node which has to be deleted
	temp = (nodeptr)malloc(sizeof(struct node));
	temp = top;
	
	if(temp == NULL)
	{
		printf("Pop Failure\n");
		exit(1);
	}
	else
	{
		//updating top to next position, discarding the linkage and then freeing the temp pointer 
		top = top -> next;
		temp -> next = NULL;
		
		//p points to tree
		p = (treeptr)malloc(sizeof(struct tree));
		
		p = temp -> element;
		free(temp);
		return p;
	}
	
}

//printing the expression in infix form
void Inorder(treeptr cur)
{
    //case when BST is empty
	if(cur == NULL)
		return;
	
	//printing elements recursively in order of left subtree -> root -> right subtree
	//considering the way in which we need to put the paranthesis
	if((cur -> left) != NULL)
		printf("(");
	Inorder(cur -> left);
	printf("%c", cur -> key);
	Inorder(cur -> right);	
	if((cur -> left) != NULL)
		printf(")");
}

//printing the expression in prefix form
void Preorder(treeptr cur)
{
    //case when BST is empty
	if(cur == NULL)
		return;
	
	///printing elements recursively in order of root -> left subtree -> right subtree
	printf("%c", cur -> key);
	Preorder(cur -> left);
	Preorder(cur -> right);
}

int main()
{
	char var, exp[100];
	
	//taking expression as input from user
	scanf("%s", exp);
	
	for(int i = 0; i < strlen(exp); i++)
	{
		var = exp[i]; 
		//storing each var of expression in a separate node of struct tree datatype(i.e creating a tree node for each var)
		t_ptr = (treeptr)malloc(sizeof(struct tree));
		t_ptr -> key = var;		
		t_ptr -> left = t_ptr -> right = NULL;
		
		if((var != '+') && (var != '-') && (var != '*') && (var != '/') && (var != '^'))
		{
		    //pushing each tree in stack if its not an operator
			push(t_ptr);
			continue;
		}	
		else
		{
			//if var is any operator then linking that operator (keeping it as root) with the top 2 trees stored in the stack using pop function.
			//modifying root and pushing the pointer to this new tree into stack 
			t_ptr -> right = pop();
			t_ptr -> left = pop();
			root = t_ptr;
			push(root);
		}	
	}
	
	//calling inorder and preorder functions	
	Inorder(root);
	printf("\n");
	Preorder(root);					
	printf("\n");
	return 0;
}