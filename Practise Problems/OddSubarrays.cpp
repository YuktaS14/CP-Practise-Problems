#include <bits/stdc++.h>
#include <set>
using namespace std;
#define ll long long
//#define fo(i,n) for(ll i=0;i<n;i++)
#define vvi vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i = a; i<b; i++)
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
        vector<int> p(n);

        rep(i,0,n)
        {
            cin>>p[i];

        }

        int ans = 0;
        int  maxi = 0;

        rep(i,0,n)
        {
            maxi = max(p[i],maxi);

            //cout<<t<<" "<<p[i]<<" "<<maxi<<" "<<endl;
            if(p[i] != maxi)
            {
               
                ans++;
                maxi = 0;
            }
                        // int j = i;
            // while(j<n)
            // {
            //     if(p[j]<p[i])
            //     {
            //         ans++;
            //     }
            //     j++;
            
        }

        cout<<ans<<endl;
    }


    return 0;

}