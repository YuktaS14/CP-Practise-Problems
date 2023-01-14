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
        ll n,m;
        cin>>n>>m;

        int k = 0;

        if(n == 1 && m == 1)
            k= 0;
        else if(n == 1 || m == 1)
            k = 1;
        else
            k = 2;
        cout<<k<<endl;


    }
    return 0;
}