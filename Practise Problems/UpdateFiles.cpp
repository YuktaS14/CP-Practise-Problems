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
        ll n,k;
        cin>>n>>k;

        ll comp = 0,ans = 0;

        ll p = log2(k);
        
        ll c = pow(2,p);
       // cout<<"cp "<<c<<"b "<<k<<endl;
        if(c < k) p++;
        
        //if(c != k) p++;
        ans+=p;
        comp += pow(2,p);

        //cout<<comp<<" c "<<p<<endl;
        if(comp<n)
        {
        ll rem = n-comp;
        ll time = rem/k;
        if(rem%k)
            time++;
        ans+=time;
      
        }   
         cout<<ans<<endl;   
        
    }
    return 0;
}