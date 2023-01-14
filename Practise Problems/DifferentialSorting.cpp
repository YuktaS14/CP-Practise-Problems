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
    ll t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);

        rep(i,0,n)
            cin>>a[i];

        if(a[n-2]>a[n-1])
        {
            cout<<-1<<endl;
            continue;
        }

        if(a[n-1]<0)
        {
            int flag = 0;
            rep(i,0,n-1)
            {
                if(a[i]>a[i+1])
                {
                    cout<<-1<<endl;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) 
            {
                cout<<0<<endl;
            }
           continue;
        }
        
        cout<<n-2<<endl;

        for(ll i = 0; i<n-2; i++)
        {
           cout<<i+1<<" "<<n-1<<" "<<n<<endl;
        }

    }
    return 0;
}