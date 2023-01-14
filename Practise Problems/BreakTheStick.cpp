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
        int N,X;
        cin>>N>>X;
        
        if(X == 1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        
        if(N%2 == 0)
            cout<<"YES"<<endl;
        
        else if(N%2 != 0 && X%2 == 0)
            cout<<"NO"<<endl;

        else if(N%2 != 0 && X%2 != 0)
            cout<<"YES"<<endl;
       
    }
}