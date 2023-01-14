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
    cin >>t;

    while(t--)
    {
        int N;
        cin>>N;
        
        vector<ll>A(N);

        rep(i,0,N)
            cin>>A[i];

        ll ans = 0;

        rep(i,0,N-1)
        {
            ll temp = A[i] + A[i+1];
            ans = max(ans,temp);
        }

        ans = max(ans, A[0]+A[N-1]);

        cout<<ans<<endl;
    }
}