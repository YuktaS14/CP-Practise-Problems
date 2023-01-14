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
        vector<pair<pair<int,int>,int>>coords;
        rep(i,0,m)
        {
            int x,w;
            cin>>x>>w;
            coords.push_back({{w,x},i+1});
        }
        sort(coords.begin(),coords.end());
        
        vector<pair<int,int>> ord;
        int ans = 0;
        int num = 2*n;
        rep(i,0,num)
        {
            int o = coords[i].second;
            int c = coords[i].first.second;
            ans+=coords[i].first.first;
            ord.push_back({c,o});
        }

        sort(ord.begin(),ord.end());

        cout<<ans<<endl;
        rep(i,0,n)
        {
            cout<<ord[i].second<<" "<<ord[2*n-1-i].second<<endl;
        }



    }
    return 0;
}