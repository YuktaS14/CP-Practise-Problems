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

       rep(i,0,n)
        cin>>a[i];
        
        int flag = 0;
        if(n %2 == 0)
        {
            flag = 1;
        }
        else
        {
            rep(i,0,n-1)
            {
                
                if(a[i]>=a[i+1])
                {
                    flag =1;
                    break;
                }
            }           
        }
        if(flag)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else
            cout<<"NO"<<endl;
        
    }
    return 0;
}