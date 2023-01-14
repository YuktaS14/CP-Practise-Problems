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
        ll n, a, b;
        cin>>n>>a>>b;
    

        if(abs(a-b)> 1 || (a+b) > (n-2))
        {
            cout<<-1<<endl;
            continue;
        }
               
        vector<ll>num(n);
        rep(i,0,n)
        {
            num[i] = i+1;
        }

        if(a== 0 && b==0)
        {
            rep(i,0,n)
                cout<<num[i]<<" ";
            cout<<endl;
            continue;
        }

        if(a == b)
        {
            ll i = b-1;
            ll j = a-1;
            ll temp = num[0];
            num[0] = num[1];
            num[1] = temp;

            temp = num[n-1];
            num[n-1] = num[n-2];
            num[n-2] = temp;
           
            ll in = 2;
            while(i--)
            {
                ll temp = num[in];
                num[in] = num[in+1];
                num[in+1] = temp;
                in+=2;
            }
        }
        else if(a>b)
        {
            ll in = n-1;
            while(a--)
            {
                ll temp = num[in];
                num[in] = num[in-1];
                num[in-1] = temp;
                
                in-=2;
            }
        }
        else
        {
            ll in = 0;
            while(b--)
            {
                ll temp = num[in];
                num[in] = num[in+1];
                num[in+1] = temp;
               
                in+=2;
            }
        }
        rep(i,0,n)
            cout<<num[i]<<" ";
        cout<<endl;
    }
    return 0;
}