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
        string s;
        cin>>s;
        
        int n = s.length();
        int count = 0;

        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }

        if((s[n-1] == '1') || (s[0] == '0'))
        {
            cout<<1<<endl;
            continue;
        }

        int all = 1;
        rep(i,0,n-1)
        {
            if(s[i] != '?')
            {
                all = 0;
                break;
            }
        }
        if(all)
       {
            cout<<n<<endl;
            continue;
        }
        int zero = 0,one = 0;
        
        rep(i,0,n)
        {
            if(s[i] == '1')
            {
                one= i+1;
            }
        }
        rep(i,0,n)
        {
            if(s[i] == '0')
            {
                zero= i+1;
                break;
            }
        }
        if(one== 0)
        {
            cout<<zero<<endl;
            continue;
        }
        if(zero == 0)
        {
            cout<<n-one+1<<endl;
            continue;
        }

        cout<<abs(zero-one)+1<<endl;
        

    }

    return 0;
}