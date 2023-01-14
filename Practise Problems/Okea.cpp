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
        int n,k;
        cin>>n>>k;
        int a[n][k];

        if(k==1)
        {
            cout<<"YES"<<endl;
            rep(i,1,n+1)
            {
                cout<<i<<endl;
            }
            continue;
        }

        int odd = 1,even = 2;
        int maxi = 0;
        rep(i,0,n)
        {
            rep(j,0,k)
            {
                if(i%2 == 0)
                {
                    a[i][j] = even;
                    even = even +2;
                }
                else
                {
                    a[i][j] = odd;
                    odd+=2;
                }
                maxi = max(maxi,a[i][j]);
            }
        }
        if (maxi> (n*k))
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            rep(i,0,n)
            {
                rep(j,0,k)
                {
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }

        }


    }
    return 0;
}