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
        int x,y;
        cin>>x>>y;

        int num = y%x;
        int a= 1, b= 0;
    
        
        //cout<<int(y/x)<<endl;

        if((num != 0))
        {           
            cout<<0<<" "<<0 <<endl;
            continue;
        }
        
        else
        {
            b = y/x;
            cout<<a<<" "<< b<<endl;
            
        }
            
    }
    return 0;
}