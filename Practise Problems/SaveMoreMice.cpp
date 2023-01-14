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
        vector<int>x(k);
        
        rep(i,0,k)
        {
            cin>>x[i];
        }
        sort(x.begin(),x.end());
        //reverse(x.begin(),x.end());

        ll sum = 0,num = 0;
        for(int i = k-1; i>=0; i--)
        {
            if(sum+(n-x[i]) >= n)
            {
                break;
            }
            num++;
            sum+=(n-x[i]);
        }
        cout<<num<<endl;

    }
    return 0;
}