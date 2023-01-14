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
        
        int ans = 0;

        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                ans+= (j-i+1);
                for(int k = i; k<=j;k++)
                {
                    if(a[k] == 0)
                        ans++;
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}