#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    int x;
    
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);
    
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            printf("%d", i);
            exit(1);
            
        }
    }
    printf("-1");
    
    return 0;
}