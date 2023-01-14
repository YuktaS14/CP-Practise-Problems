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
        int h1,h2,h3;
        int n;
        cin>>n;

        if(n==7)
        {    cout<<2<<" "<<4<<" "<<1<<endl;
            continue;
        }
        if(n%3 == 2)
        {
            cout<<(n/3 + 1)<<" "<< n/3 +2<<" "<<n/3 -1<<endl;
        }
        else if(n%3 == 1)
        {
            cout<< (n/3 + 1)<<" "<< n/3 +2<<" "<<n/3 -2<<endl;
        }
        else
        {
            cout<<n/3 <<" "<< n/3 +1<<" "<<n/3 -1<<endl;
        }

    }


    return 0;
}