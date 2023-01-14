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

int maxi = 0;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        ll n,m;
        cin>>n>>m;

        ll c = 0,b = 0,h = 0,w = 0;

        ll maxi = 0-1e9;
        //cout<<maxi<<endl;


        vector<vector<ll>>a(n, vector<ll>(m));
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                cin>>a[i][j];
                maxi = max(maxi,a[i][j]);
                if(maxi == a[i][j])
                {
                    c = i;b=j;
                }
            }
        }

        h = max(c, n-1-c)+1;
        w = max(b, m-1-b)+1;

        cout<<h*w<<endl;
    }
    return 0;
}