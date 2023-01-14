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

       // sort(a.begin(),a.end());

        int maxi = 0,evens = 0,sum = 0,m = 0;

        rep(i,0,n)
        {
            if(a[i] %2 == 0)
            {
                int k = log2(a[i]);
                int j = pow(2,k);
                if(j == a[i])
                {
                    m+= k;
                    a[i] = 1;
                    
                }
                else
                {
                    while(a[i] %2 == 0)
                    {
                        a[i] /= 2;
                        m++;
                    }
                }
                sum+=a[i];
            }
            else
            {
                sum+=a[i];
            }
            maxi = max(maxi,a[i]);
        }

        ll ans = 0;
        sum-=maxi;
        ans = maxi*(ll)pow(2,m) +sum;
        
        cout<<ans<<endl;
        
    }
    return 0;
}