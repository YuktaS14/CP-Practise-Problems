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
        int n,x;
        cin>>n>>x;

        vector<ll>a(n);
        map<ll,ll>m;

        rep(i,0,n)
        {
            cin>>a[i];
            m[a[i]]++;
        }

        sort(a.begin(),a.end());
        ll ans = 0;

        rep(i,0,n)
        {
            if(m[a[i]] != 0)
            {
                ll p = a[i] * x;
                
                if(m[p] == 0)
                {
                    ans++;
                }
                else
                {
                    m[p]--;
                }
                m[a[i]]--;
            }
        }

        cout<<ans<<endl;
        
    }
    return 0;
}