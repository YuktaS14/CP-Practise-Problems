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

        sort(a.begin(),a.end());

        int sum = 0,maxi = -1e9;

        rep(i,0,n)
        {
            int mini = a[i]-sum;
            maxi = max(maxi,mini);
            sum+=mini;
        }
        
        cout<<maxi<<endl;
    }
    return 0;
}