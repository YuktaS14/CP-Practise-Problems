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
        int n,x;
        cin>>n>>x;
        vector<int>a(n);
        rep(i,0,n)
        {
            cin>>a[i];
        }

      
        int flag = 1;
        rep(i,0,n-1)
        {
            if(a[i]> a[i+1])
            {
                flag = 0;
                break;
            }
        }

        if(flag==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(flag == 0 && n== x)
        {
            cout<<"NO"<<endl;
            continue;
        }

        vector<int>b(n);
        rep(i,0,n)
        {
            b[i]= a[i];
        }
        sort(b.begin(),b.end());

        if(x<= (n/2))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            int i = n-x;
            while(i<x)
            {
                if(a[i] != b[i])
                {
                    flag = 1;
                    break;
                }
                i++;
            }
            if(flag)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }


        



    }
    return 0;
}