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
        int n;
        cin>>n;

        vector<int >a(n);

        int sum =0;

        rep(i,0,n)
        {
            cin>>a[i];
            sum+= a[i];
        }

        int flag = 0;

        rep(i,0,n)
        {
            if(((sum -a[i])/(n-1) == a[i]) && (sum-a[i])%(n-1) == 0)
            {

                cout<<"YES"<<endl;
                //cout<<a[i]<<endl;
                flag = 1;
                break;
            }
        }

        if(flag == 0)
            cout<<"NO"<<endl;
    }
}