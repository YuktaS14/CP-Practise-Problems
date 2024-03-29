#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+2, MOD = 1e9+7;

int dp[N];
int minNumSquares(int n)
{
    if(n<1)
        return 0;
    if(n==1 || n==2 || n==3)
        return dp[n]=n;

    if(dp[n] != MOD)
        return dp[n];
    
    for(int i= 1; i*i<=n; i++)
    {
        dp[n] = min(dp[n], 1+ minNumSquares(n-(i*i)));
    }

    return dp[n];
}  

int main(){
    for(int i = 0; i<N; i++)
        dp[i] = MOD;

    int n;
    cin>>n;

    int ans = minNumSquares(n);
    cout<<ans<<endl;

    return 0;
}