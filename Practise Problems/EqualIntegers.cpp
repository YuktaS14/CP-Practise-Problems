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
        ll X,Y;
        cin>>X>>Y;

    
        if(X<=Y)
        {
            cout<<(Y-X)<<endl;
        }
        else
        {
            ll temp = (X-Y)/2;

            if((X-Y) % 2 == 0)
                cout<< temp <<endl;
            else
                cout<< temp + 2<<endl;
        }
    }
    return 0;
}