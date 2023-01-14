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
        string s;
        cin>>s;

        ll ans = 0;

        for(int i = 0; i<s.length(); i++)
        {
            if(i == 0)
                ans++;
            else if((s[i]==s[i-1]))
                ans ++;
            else
                ans+=i+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}