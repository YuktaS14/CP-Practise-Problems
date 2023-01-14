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

        vector<ll>a(n);

        rep(i,0,n)
            cin>>a[i];

        bool allZeroes = true;
        int l = -1,r = -1;
        rep(i,0,n)
        {
            if(a[i] != 0)
            {
                allZeroes = false;
                if(l == -1) l =i;
                r = i;//stores last non-zero number index

            }
        }

        if(allZeroes)
            cout<<0<<endl;
        else
        {
            bool isAnsOne = true;

            rep(i,0,l)
            {
                if(a[i] != 0)
                    isAnsOne = false;
            }
            rep(i,r+1,n)
            {
                if(a[i] != 0)
                    isAnsOne = false;
            }
            rep(i,l,r+1)
            {
                if(a[i] == 0)
                    isAnsOne = false;
            }

            if(isAnsOne)
                cout<<1<<endl;
            else
                cout<<2<<endl;

        }
        
    }       
    return 0;
}