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
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n,h;
        cin>>n>>h;

        vector<ll>a(n);
        rep(i,0,n)
            cin>>a[i];
        
        ll l =1,r = h,found = 0,k= 0;
        while(l<=r)
        {
            ll mid = (l+r)/2;
            ll ans = 0; 
            for(ll i = 0; i<n; i++)
            {
                if(i == n-1)
                {
                    ans+=mid;
                    continue;
                }
                ll d = a[i+1]-a[i];
                if(d<mid)
                {
                    ans+=d;
                }
                else
                {
                    ans+=mid;
                }
            }

            if(ans>=h)
            {
                k=mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        cout<<k<<endl;
        
    }
    return 0;
}