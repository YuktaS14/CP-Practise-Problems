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

        vector<ll>a(n);

        rep(i,0,n)
            cin>>a[i];

        ll deficit = 0,extra = 0, op = 0;

        if((n==3) && (a[1]%2 != 0))
        {
            cout<<-1<<endl;
            continue;
        }

        
        ll k = 1;
        while(k<n-1 && a[k] == 1)
            k++;
        
        if(k == n-1)
        {
            cout<<-1<<endl;
            continue;
        }

        rep(i,1,n-1)
        {
            op+=(a[i]+1)/2;
        }
        cout<<op<<endl;
         

       
    }
    deque<string>dq;
    dq.push_back
    return 0;
}