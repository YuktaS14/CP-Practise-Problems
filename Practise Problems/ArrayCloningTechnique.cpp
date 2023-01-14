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
        map<int,int> m;

        int maxFreq = 0,num = 0;

        rep(i,0,n)
        {
            cin>>a[i];
            m[a[i]]++;
            if(m[a[i]] > maxFreq)
            {
                maxFreq = m[a[i]];
                num = a[i];
            }

        }
 
        if(maxFreq== n)
        {
            cout<<0<<endl;
            continue;
        }

        int ans = 1;
        while(maxFreq <=n)
        {
            
           if(maxFreq +maxFreq >=n)
           {
               ans+= n-maxFreq;
               break;
           }
           ans+=maxFreq;
           maxFreq *= 2;
           ans++;
        }

        cout<<ans<<endl;
    }
    return 0;
}