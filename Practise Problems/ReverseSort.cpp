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
        string s;
        cin>>s;

        int zeroes = 0,ones = 0;
        rep(i,0,n)
        {
            if(s[i] == '0')
                zeroes++;
            else
                ones++;
        }
        vector<int>ans;

        rep(i,0,zeroes)
        {
            if(s[i] == '1')
                ans.push_back(i+1);
        }
        rep(i,zeroes,ones+zeroes)
        {
            if(s[i] == '0')
                ans.push_back(i+1);
        }

        if(ans.size() == 0)
        {
            cout<<0<<endl;
            continue;
        }

        cout<<1<<endl;
        cout<<ans.size()<<" ";
        rep(i,0,ans.size())
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;        
    }
    return 0;
}