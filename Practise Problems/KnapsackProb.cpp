#include <bits/stdc++.h>
#include <set>
using namespace std;
#define ll long long
//#define fo(i,n) for(ll i=0;i<n;i++)
#define vvi vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define ff first
#define ss second

int dp[105][10005];
int Knapsack(int n, int W, vector<int>& w, vector<int>p)
{
    if(n== 0 || W == 0)
        return 0;
    
    if(dp[n][W] != -1) return dp[n][W];
    
    if(w[n-1] > W)
        return Knapsack(n-1,W,w,p);
    
    else
    {
        int ans = p[n-1] + Knapsack(n-1,W-w[n-1],w,p);
           
        ans =  max( ans, Knapsack(n-1,W,w,p));
       
        return dp[n][W] = ans;
    }
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n,W;
    cin>>n>>W;
    vector<int>w(n);
    vector<int>p(n);
    rep(i,0,n)
        cin>>w[i];
     rep(i,0,n)
        cin>>p[i];
        
    priority_queue<int>pq;
    
    int ans = Knapsack(n,W,w,p);
    cout<<ans<<endl;
}