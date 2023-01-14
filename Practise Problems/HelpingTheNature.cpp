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

        vector<ll> a(n);

        rep(i,0,n)
            cin>>a[i];
        
        //ll op = 0;
        
        ll suffixOp = 0, prev_val = a[0],preffixOp = 0;
        ll ans = 0;
        rep(i,1,n)
        {
            a[i] = a[i]- suffixOp;
            if(a[i] > prev_val)
            {
                suffixOp += a[i]-prev_val;
                
            }
            else if(a[i]<= prev_val)
            {
                preffixOp += prev_val-a[i];
             
                prev_val = a[i];
            }

        }
        
        ans = abs(prev_val)+suffixOp+ preffixOp;
        cout<<ans<<endl;

    }
    //4+8+8+8
    return 0;
}