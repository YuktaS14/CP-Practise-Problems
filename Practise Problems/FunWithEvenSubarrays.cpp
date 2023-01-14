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
        int n;
        cin>>n;
        vector<int>a(n);
        rep(i,0,n)
            cin>>a[i];

        if(n == 1)
        {
            cout<<0<<endl;
            continue;
        }

        int flag = 0;
        int i = n-1;
        for(i; i>0; i--)
        {
            if(a[i-1] != a[i])
            {
                flag = 1;
                break;
            }
        }

        int j = n-i;
        int ans = 0;
        while(j<n)
        {
            if(a[n-j-1] == a[n-1])
            {
                j++;
            }
            else
            {
                j= j*2;
                ans++;
            }
        }

        cout<<ans<<endl;
    }
}