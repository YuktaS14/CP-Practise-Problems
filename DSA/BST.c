#include <stdio.h>
#include <stdlib.h>

//creating a binary search tree
typedef struct node
{
	int key;
	struct node* left;
	struct node* right;
	struct node* parent;
}Node;

typedef struct node* nodeptr;

//globally defining root which points at root of BST
nodeptr root = NULL;

//declaring functions to be used
nodeptr Insert(int num);
nodeptr Search(nodeptr cur, int num);
int Predecessor(nodeptr p);
int Successor(nodeptr p);

//wrapper function for insert
void W_Insert()
{
    //takes key to be inserted, checks return value of insert function and prints the error code if error is detected
	int num;
	scanf("%d", &num);
	nodeptr check = Insert(num);
	if(check == NULL)
		printf("Insert Fail\n");	
	
}

//creates a new node, stores num value in it
nodeptr Insert(int num)
{
	nodeptr temp = NULL, prev = NULL, cur = NULL;
	nodeptr newptr = (nodeptr)malloc(sizeof(struct node));
	
	if(!newptr)
		return NULL;	
	
	newptr -> key = num;
	newptr -> left = NULL;
	newptr -> right = NULL;
	newptr -> parent = NULL;
	
	//case when tree is empty
	if(root == NULL)
		root = newptr;
	
	else
	{
	    //traversing through tree using cur pointer, if num is less than cur then traverse in left subtree , else traverse in right subtree
	    //if cur pointer points to null, i.e we reach at end of a subtree then insert appropriately, such that condition for BST holds
		cur = root;
		int flag;
		//flag is used to note which child of cur ptr is to be updated
		while(cur != NULL)	
		{
			if(num < (cur -> key))
			{
				prev = cur;
				cur = (cur -> left);
				flag = 0;
			}
			else
			{
				prev = cur;
				cur = cur -> right;
				flag = 1;
			}
		}	
	
		if(flag == 0)
		{
			prev -> left = newptr;
			newptr -> parent = prev;
		}
		else
		{
			prev -> right = newptr;
			newptr -> parent = prev;
		}	
		return newptr;	
	}
}
	
//wrapper function for search
void W_Search()
{
    //takes input from user, checks return value of Search function, if its null -> prints not found, else -> found
	int num; 
	scanf("%d", &num);
	nodeptr temp;
	temp = Search(root,num);
	if(temp == NULL)
	printf("Not Found\n");
	else
	printf("Found\n");
}

nodeptr Search(nodeptr cur, int num)
{	
    //cur ptr points to root in the beginning
    //checks whether BST is empty or not
    //then it compares if key of cur ptr is equal to num or not
    //if num is less than key pointed by cur, then recursuvely search in left subtree, else search in right subtree
	if(cur == NULL)
		return cur;
	
	else if(num == (cur -> key))
		return cur;
	
	else if(num <= (cur -> key))
		Search(cur -> left, num);
	else
		Search(cur -> right, num);	
}

void Inorder(nodeptr cur)
{
    //case when BST is empty
	if(cur == NULL)
		return;
	
	//printing elements recursively in order of left subtree -> root -> right subtree
	Inorder(cur -> left);
	printf("%d\n", cur -> key);
	Inorder(cur -> right);	
}

void Preorder(nodeptr cur)
{
    //case when BST is empty
	if(cur == NULL)
		return;
	
	///printing elements recursively in order of root -> left subtree -> right subtree
	printf("%d\n", cur -> key);
	Preorder(cur -> left);
	Preorder(cur -> right);
}

void Postorder(nodeptr cur)
{
    //case when BST is empty
	if(cur == NULL)
		return;
	
	//printing elements recursively in order of left subtree -> right subtree -> root
	Postorder(cur -> left);
	Postorder(cur -> right);
	printf("%d\n", cur -> key);
}

//wrapper function for predecessor
void W_Predecessor()
{
    //taking key value as input from user
	int num;
	scanf("%d", &num);
	nodeptr p = NULL;
	
	//p pointer points at the key whose predecessor we have to find
	p = Search(root,num);
	
	//case when input num is not present in BST
	if(p == NULL)
	{
		printf("Invalid Input\n");
		return;
	}
	
	nodeptr prev = (p -> parent);	
	//prev points to parent of the node whose predecessor we have to find 
	
	//case when only the node containing num is present in BST
	if((prev == NULL) && ((p -> left) == NULL))
	{
		printf("No predecessor\n");
		return;
	}
	
	//case when the node does not have left subtree and it is left child of its parent node
	else if(((p -> left) == NULL) && ((prev -> right) != p))
	{
		printf("No predecessor\n");
		return;
	}	
	
	//case when the node does not have left subtree and it is right child of its parent node, printing parent
	else if(((p -> left) == NULL) && ((prev -> right) == p))	
	{
		printf("%d\n", prev -> key);
		return;
	}			
	
	else
	{
	   //finding predecessor and printing it.
		int value =	Predecessor(p);
		printf("%d\n", value);
		return;
	}	
}

int Predecessor(nodeptr p)
{
    //first going to immediate left subtree of the node and then traversing through its right subtrees till we reach at the end (leaf node)
    //as now our cur pointer will point to predecessor 
	nodeptr previous, cur;
	previous = p;
	cur = p -> left;
	while((cur -> right) != NULL)
	{
		previous = cur;
		cur = cur -> right;
	}
	
	int val;
	val = (cur -> key);
	return val;

}

//wrapper function for Successor
void W_Successor()
{
    //taking key value as input from user  
	int num;
	scanf("%d", &num);
	nodeptr p = NULL;
	
	//p pointer points at the key whose predecessor we have to find
	p = Search(root,num);
	
	
	//case when input num is not present in BST
	if(p == NULL)
	{
		printf("Invalid Input\n");
		return;
	}
	
	//prev points to parent of the node whose successor we have to find
	nodeptr prev = (p -> parent);
	
	if((prev == NULL) && ((p -> right) == NULL))
	{
		printf("No successor\n");
		return;
	}
	
	//case when the node does not have right subtree and it is left child of its parent node
	else if(((p -> right) == NULL) && ((prev -> left) == p))	
	{
		printf("%d\n", prev -> key);
		return;
	}	
	
	//case when the node does not have right subtree and it is right child of its parent node	
	else if(((p -> right) == NULL) && ((prev -> left) != p))
	{
		printf("No successor\n");
		return;
	}	
	else
	{
	    //returning successor of the node containg key
		int value =	Successor(p);
		printf("%d\n", value);
		return;
	}	
}

int Successor(nodeptr p)
{
    //first going to immediate right subtree of the node and then traversing through its left subtrees till we reach at the end (leaf node)
    //as now our cur pointer will point to successor
	
	nodeptr pre, curr;		
	
	pre = p;
	curr = p -> right;
	while((curr -> left) != NULL)
	{
		pre = curr;
		curr = curr -> left;
	}
	int value = curr -> key;
	return value;	
}

int main()
{
	int n;
	while(1)
	{
	    //takes input from user and calls appropriate function
		scanf("%d", &n);
		if(n == 1)
		{
			W_Insert();
		}
		else if(n == 2)
		{
			W_Search();
		}
		else if(n == 3)
			Inorder(root);
		else if(n == 4)
		    Preorder(root);
		else if(n == 5)
			Postorder(root);
    	else if(n == 6)
		{
			W_Predecessor();
		}
		else if(n == 7)
		{
			W_Successor();
		}
		else if(n == 8)
			exit(1);
	}

	return 0;
}