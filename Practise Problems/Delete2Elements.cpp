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
        ll n;
        cin>>n;
        vector<ll>a(n);

        map<ll,ll>m;
        ll sum = 0;
        rep(i,0,n)
        {
            cin>>a[i];
            sum+= a[i];
            m[a[i]]++;
        }
        
        ll k = 0;
        

        ll req = (2*sum)/n;
        if((2*sum) % n != 0)
        {
            cout<<0<<endl;
            continue;
        }
        // cout<<"req "<<req<<endl;
        rep(i,0,n)
        {
            if(req == (2*a[i]))
                k+=(m[req-a[i]]-1);
            else
                k+=m[req-a[i]];
        }

        cout<<k/2<<endl;
    }
    return 0;
}
