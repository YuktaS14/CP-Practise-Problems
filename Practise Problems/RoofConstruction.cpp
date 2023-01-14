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

        int x = n-1;
        x = log2(x);
       
        x = pow(2,x);
        //cout<<x<<"JJJ"<<endl;
        int y = x-1;
        while(y!= 0)
        {
            cout<<y<<" ";
            y--;
        }
        cout<<0<<" ";
        
        while(x<n)
        {
            cout<<x<<" ";
            x++;
        }
        cout<<endl;
    }
    return 0;
}