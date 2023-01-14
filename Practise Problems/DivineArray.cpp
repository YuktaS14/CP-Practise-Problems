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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
       
        vector<int>a(n);

        rep(i,0,n)
            cin>>a[i];
        
        int q;
        cin>>q;

        int v[n+1][n];
        rep(i,0,n)
            v[0][i] = a[i];
        
        rep(i,1,n+1)
        {
            map<int,int>m;
            rep(j,0,n)
            {
                m[v[i-1][j]]++;
            }
            rep(j,0,n)
            {
                v[i][j] = m[v[i-1][j]]; 
            }
        }

        // rep(i,0,n+1)
        // {
        //     rep(j,0,n)
        //     {
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        while(q--)
         {
             ll x,k;
             cin>>x>>k;
            
             if(k>n)
             {
                 cout<<v[n][x-1]<<endl;
             }            
             else
             {
                 cout<<v[k][x-1]<<endl;
             }            
         }
    }
    return 0;
}