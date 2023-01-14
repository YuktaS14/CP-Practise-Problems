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
        int n, m;
        cin>>n>>m;
        set<int>s;
        rep(i,1,n+1)
            s.insert(i);
        
        while(m--)
        {
            int a, b, c;
            cin>>a>>b>>c;
            
            if(s.find(b) != s.end())
            {
                auto it = s.find(b);
                s.erase(it);
            }
            
        }

            auto it = s.begin();
            int node = *it;

        rep(i,1,n+1)
        {
            if(i == node)
                continue;

            cout<<node<<" "<<i<<endl;
        }
        
    }
    return 0;
}