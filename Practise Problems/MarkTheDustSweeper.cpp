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
        ll n;
        cin>>n;
        vector<ll>a(n);
        ll sum = 0;
        rep(i,0,n)
        {
            cin>>a[i];
            if(i != n-1)
                sum+=a[i];
        }
        ll zeroes = 0;
        ll i = 0,op = 0;
        while(i<n-1)
        {
            
            if(a[i] != 0)
            {
                ll j = i+1;
                while(j<n-1 && a[j] == 0)
                {
                    zeroes++;
                    j++;
                }
                 i= j;
            }        
            else
                i++;
        }
        cout<< sum+zeroes<<endl;
               
    }
    return 0;
}