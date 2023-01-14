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
        int n;
        cin>>n;
        vector<int>a(n);
        set<int>s;
        rep(i,0,n)
        {
            cin>>a[i];
            s.insert(a[i]);
        }
        
        int pair = n/2;

        sort(a.begin(),a.end());
        //reverse(a.begin(),a.end());

        rep(i,1,(n/2)+1)
        {
            cout<<a[i]<<" "<<a[0]<<endl;
        }
        //cout<<endl;
    }
    return 0;
}