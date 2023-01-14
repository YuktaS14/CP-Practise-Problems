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
        int a,b;
        cin>>a>>b;
        int ans = a;
        int val = 0;
        int r = (a-1)%4;
        if(r == 0)
            val = a-1;
        else if(r == 1)
            val = 1;
        else if(r == 2)
            val = a;
        else
            val = 0;        
        
        if(val != b)
        {    
        if((val ^ b) != a)
            ans++;
        else
        {
            ans+=2;
           
        }
        }

        cout<<ans<<endl;
    }
    return 0;
}