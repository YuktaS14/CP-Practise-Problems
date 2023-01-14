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
            int n;
            cin>>n;
            map<int,int>m;
            vector<pair<int,int>>v;

            vector<int>a(n);
            rep(i,0,n)
            {
                cin>>a[i];
                if(m.find(a[i]) != m.end())
                {
                    v.push_back({m[a[i]],i});
                    m[a[i]] = i;
                }
                else
                    m[a[i]] = i;
            }
            
            int ans = 0, maxi = 0;
            for(int i= 0; i<v.size(); i++)
            {
                ans = v[i].first + n- v[i].second;
                maxi = max(ans,maxi);
            }

            if(maxi)
                cout<<maxi<<endl;
            else
                cout<<-1<<endl;

        }
    
    return 0;
}