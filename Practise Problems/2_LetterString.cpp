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


        map<string,ll> m;
        ll ans =0;

        rep(i,0,n)
        {
            string t;
            cin>>t;
            string temp = t;

            for(char ch = 'a'; ch <='k';ch++)
            {
                if(ch != t[0])
                {
                    temp[0] = ch;
                    ans+=m[temp];
                }
            }
            
            temp = t;
            for(char ch = 'a'; ch <='k';ch++)
            {
                if(ch != t[1])
                {
                    temp[1] = ch;
                    ans+=m[temp];
                }
            }
            m[t]++;

        }

        cout<<ans<<endl;

    }
    return 0;
}