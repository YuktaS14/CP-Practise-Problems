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
        ll n;
        cin>>n;
        vector<pair<ll,ll>>a;
       // map<int>m;
        rep(i,0,n)
        {
            ll t;
            cin>>t;
            a.push_back({t,i+1});
        }
        
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());

        vector<pair<ll,ll>>x;
        x.push_back({0,1});

        ll k = 2, j =0;
        rep(i,0,a.size())
        {
            if(i%2 == 0)
            {
                x.push_back({a[i].second,k});
                k++;
            }
            else
            {
                x.push_back({a[i].second,j});
                j--;
            }
        }

        ll ans = 0;

        rep(i,1,x.size())
        {
            ans += abs(x[i].second -1) * a[i-1].first;
        }

        cout<<2*ans<<endl;

        sort(x.begin(),x.end());
        rep(i,0,x.size())
            cout<<x[i].second<<" ";

        cout<<endl;





    }
    return 0;
}