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


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>c(n);
        rep(i,0,n)
            cin>>c[i];
        
        map<int,int>m;
        int ans[n] = { 0 };
        
        rep(i,0,n)
        {
            if(m[c[i]] == 0)
            {
                m[c[i]] = i+1;
                ans[c[i] - 1]++;
            }
            else
            {
                if(((i+1) - m[c[i]]) % 2 != 0)
                {
                    m[c[i]] = i+1;
                    ans[c[i] - 1]++;
                }
            }
        }

        rep(i,0,n)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}