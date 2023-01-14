#include <stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	int A[n];
	for(int i = 0; i< n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	int freq = 0, curr_candidate = A[0];
	for(int i = 0; i < n; i++)
	{
		if(freq == 0)
		{
			freq = 1;
			curr_candidate = A[i];
		}
		else if(curr_candidate == A[i])
		{
			freq++;
		}
		else
		{
			freq--;
		}
	}
	
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(curr_candidate == A[i])
		{
			count++;
		}
	}
	
	if(count > (n/2))
	{
		printf("%d \n", curr_candidate);
	}
	else
	{
		printf("No Majority \n");
	}
	return 0;
}