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

        ll a[n];

        rep(i,0,n)
            cin>>a[i];


        if(n == 1 && a[0]>1)
        {
            cout<<"NO"<<endl;
            continue;
        }

        sort(a,a+n);
        int len = sizeof(a)/8;
        //cout<<len;

        if(a[len-1]-a[len-2]>1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;

    }

    return 0;
}