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

const int N= 1e7, MOD = 1e9+7;

 
int main()
{
    int n,m;
    cin>>n>>m;
    int ar[n+3];
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    sort(ar+1,ar+n+1);
    ll pre[n+4];
    pre[0]=0;
    for(int i=n,j=1;i>=1;i--,j++)pre[j]=pre[j-1]+ar[i];

    
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        ll ans=pre[x]-pre[x-y];
        cout<<ans<<endl;
    }


    return 0;
}