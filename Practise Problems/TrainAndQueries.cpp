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
        ll n, k;
        cin>>n>>k;
        map<ll,vector<ll>>m;
        rep(i,0,n)
        {
            int s;
            cin>>s;
            
            m[s].push_back(i+1);
        }
        
        while(k--)
        {
            ll a,b;
            cin>>a>>b;

           
            
            //ll second = m[b][m[b].size()-1];
            int j = m.count(a);
            int l = m.count(b);
         
            if(j == 0 || l == 0)
            {
                cout<<"NO"<<endl;
                continue;
            }
            // vector<ll>first = m[a];
            // vector<ll>second = m[b];
            // j = second.size()-1;
            int x =m[a][0];
            if(upper_bound(m[b].begin(),m[b].end(),x) == m[b].end())
            {
                //cout<<m[a]<<a<<" "<<m[b]<<b<<endl;
                cout<<"NO"<<endl;
            }
            else
                cout<<"YES"<<endl;
        }


    }
    return 0;
}