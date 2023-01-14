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
        vector<int>b(n);
        rep(i,0,n) cin>>a[i];
        rep(i,0,n) cin>>b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int flag = 1;
        rep(i,0,n)
        {
            if((b[i] == a[i]+1) || (b[i] == a[i]))
            {
                continue;
            }
            else
            {
                flag = 0;
                break;
            }
        }

        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}