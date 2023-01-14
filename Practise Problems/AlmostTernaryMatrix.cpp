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
        int n,m;
        cin>>n>>m;

        vector<vector<int>>a(n,vector<int>(m));

        int c = 1;
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                if(j==0)
                {
                    a[i][j] = c;
                    c  = c^1;
                    continue;
                }
                if(j%2 == 0)
                {
                    a[i][j] = c;
                    c= c^1;
                }
                else
                {
                    a[i][j] = c;
                }            
            }
            if(i%2 == 0)
            {
                c= a[i][0]^1;
            }
            else
            {
                c= a[i][0];
            }
        }

        rep(i,0,n)
        {
            rep(j,0,m)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}