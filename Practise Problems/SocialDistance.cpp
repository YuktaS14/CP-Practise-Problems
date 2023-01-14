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
        ll n, m;
        cin>>n>>m;

        ll a[n];

        rep(i,0,n)
        {
            cin>>a[i];
        }

      
        sort(a,a+n);

       
       

        if(n>m)
            cout<<"NO"<<endl;
        
        else
        {
            m = m-n;
            
            rep(i,0,n-1)
            {
                ll maxi = max(a[i],a[i+1]);
                m = m-maxi;
                //cout<<m<<endl;
            }
            m = m- max(a[n-1], a[0]);

           

            if(m<0)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }

    }

}