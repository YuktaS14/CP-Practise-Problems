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
    cin >>t;

    while(t--)
    {
        ll l,r;
        cin>>l>>r;

        if(l%2 != 0)
        {
            if(l+4 >r)
                cout<<-1 <<endl;
            else
                cout<<l+1<<" "<<l+2<<" "<<l+3<<" "<<l+4<<endl;
        }
        
        else
            cout<<l<<" "<<l+1<<" "<<l+2<<" "<<l+3<<endl;
       
    }
    return 0;
}