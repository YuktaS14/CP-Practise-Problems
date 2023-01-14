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


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       ll a,b,c,m;
       cin>>a>>b>>c>>m;

        ll maxPairs = a+b+c-3;
        

        if(maxPairs< m)
        {
            cout<<"NO"<<endl;
            continue;
        }

        
        vector <ll>s = {a,b,c};
        sort(s.begin(),s.end());

        s[2] = s[2]-s[1]-s[0];

        
        ll minPairs = s[2]-1;
        if(m< minPairs)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;  

        
    }
    return 0;
}