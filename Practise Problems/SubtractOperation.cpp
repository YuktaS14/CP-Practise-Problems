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

bool binarySearch(vector<ll>& a, ll n, ll num)
{
    ll i = 0 ,j = n-1;
    while(i<=j)
    {
        ll mid = (i+j)/2;
        if(a[mid] == num)
        {
            return true;
        }
        else if(a[mid]>num)
            j = mid-1;
        else
            i = mid+1;
    }

    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;

        vector<ll>a(n);

        rep(i,0,n)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end());

        ll flag = 0;
        for(int i = 0; i<n; i++)
        {
            int num = a[i] + k;

            if(binarySearch(a,n,num))
            {
                flag = 1;
                cout<<"YES"<<endl;
                break;
            }
            
        }

        if(flag == 0)
            cout<<"NO"<<endl;
    }
    return 0;
}