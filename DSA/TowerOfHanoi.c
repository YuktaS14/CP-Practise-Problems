#include<stdio.h>

void Tower(int n, int source, int target, int auxiliary)
{
	if(n < 1)
		return;
	if(n == 1)
		printf("Move Disk %d from Pole %d to Pole %d\n", n, source, target);
	else
	{
		int i = 1;
		Tower(n-1, source, auxiliary, target);
		printf("Move Disk %d from Pole %d to Pole %d\n", n , source, target);
		Tower(n-1, auxiliary, target, source);
		return;
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	Tower(n, 0, 2, 1);
	
	return 0;
}