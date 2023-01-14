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
        ll w,h;
        cin>>w>>h;
        vector<pair<ll,ll>>side1,side1v,side2,side2h;

        rep(i,0,4)
        {
            ll k;
            cin>>k;
            rep(j,0,k)
            {
                ll m ;
                cin>>m;
                if(i == 0)
                    side1.push_back({m,0});
                else if(i == 1)
                    side1v.push_back({m,h});
                else if(i == 2)
                    side2.push_back({m,0});
                else if(i == 3)
                    side2h.push_back({m,w});
                
            }
        }

        ll maxi = 0, ans = 0;
        maxi = max(side1[side1.size()-1].first - side1[0].first, side1v[side1v.size()-1].first - side1v[0].first);
        ans = maxi*h;

        maxi = max(side2[side2.size()-1].first - side2[0].first, side2h[side2h.size()-1].first - side2h[0].first);
        ans = max(ans,maxi*w);

        cout<<ans<<endl;
        
        
    }
    return 0;
}