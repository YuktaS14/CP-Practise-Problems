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
        vector<ll> v(n);
        ll ans = 0; 
        rep(i,0,n)
            cin>>v[i];
       
            map<ll,ll> m;
            ll sum=0;
            for(ll i=0;i<n;i++){
                sum+=v[i];
                m[sum]=i+1;
            }
            sum=0;
            for(ll i=n-1;i>=0;i--){
                sum+=v[i];
                if(m[sum]>0 && m[sum]<(i+1)){
                    // cout<<"i "<<i<<" "<<m[sum]<<endl;
                    ans=max(ans,(m[sum]+n-i));
                    // cout<<"ans "<<ans<<endl;
                }
            }
            cout<<ans<<endl;
       
         
    }
    return 0;
}