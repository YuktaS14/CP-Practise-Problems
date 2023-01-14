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
        ll hc,dc;
        cin>>hc>>dc;

        ll hm,dm;
        cin>>hm>>dm;

        ll k,w,a;
        cin>>k>>w>>a;

        int flag = 0;
        for(ll i = 0; i<=k; i++)
        {
            ll chealth = (k-i)*a + hc;
            ll cattack = i*w + dc;

            ll mkills = chealth/dm;
            ll ckills = hm/cattack;
            if(chealth%dm !=0) mkills++;
            if(hm%cattack != 0) ckills++;

            if(mkills >= ckills)
            {
                flag = 1;
                break;
            }
        }

        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }
    return 0;
}