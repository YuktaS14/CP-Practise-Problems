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
        ll l,r,a;
        cin>>l>>r>>a;

        ll ans = 0;
        int x = 0;
        int i = r/a;
        if(r%a != (a-1))
        {
            x = a*(i-1) + (a-1);
            if(x>=l)
                ans = floor((double)x/(double)a) + x%a ;
            else
                ans = floor((double)r/(double)a) + r%a ;
        }
        else
            ans = floor((double)r/(double)a) + r%a ;


        cout<<ans<<endl;
    }
    return 0;
}