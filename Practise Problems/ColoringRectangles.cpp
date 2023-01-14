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

        int ans = (n/3) * m;
        if(n%3 == 1)
        {
            ans+=m/3;
            if(m%3 != 0)
                ans++;
        }
        else if(n%3 == 2)
        {
            ans+= 2* (m/3);
            if(m%3 == 1)
            {
                ans ++;
            }
            else if(m%3 == 2)
            {
                ans+= 2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}