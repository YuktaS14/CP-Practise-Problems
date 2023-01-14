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
        ll n,x;
        cin>>n>>x;
        vector<ll>a(n);
        ll sum = 0;
        rep(i,0,n)
        {
            cin>>a[i];
            sum+=a[i];
        }
        
        sort(a.begin(),a.end());

        ll day = 0,ans = 0,s = 0;

        for(int i = n-1; i>=0; i--)
        {
            if(sum>x)
            {
                sum-= (a[i]+day);
                continue;
            }

            //an = a+(n-1)*d
            //d = i+1
            ll rem = x-sum;
            ll numdays = rem/(i+1);
            ans+=((numdays+1)*(i+1));
            day += (numdays+1);

            sum+= ((i+1)*(numdays+1));
            sum-=(a[i]+day); 

        }

        cout<<ans<<endl;      

    }
    return 0;

}
//