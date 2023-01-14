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
       
       if(n==1 && m == 1)
        {
            cout<<1<<endl;
            continue;
        }
        ll ans = 0;
        ans = (m*(m+1))/2;

        for(int i =2; i<=n;i++)
        {
            ans += i*m;
        }

        cout<<ans<<endl;
    }

    return 0;
}