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
        vector<int>a(n);

        rep(i,0,n)
            cin>>a[i];

        int index = 0;
        rep(i,0,n-1)
        {
            if(a[i] == a[i+1])
                index++;
        }

        if(index == 1 || index == 0)
        {
            cout<<0<<endl;
            continue;
        }

        int i = 0;
        int first =0,last = 0;
        while(i<n)
        {
            if(a[i]==a[i+1] && first== 0)
            {
                first = i+1;
                i++;
                continue;
            }
            if(a[i] == a[i+1])
            {
                last = i;
            }
            
            i++;
        }

        if(first == last && first != 0)
        {
            cout<<1<<endl;
            continue;
        }
        cout<<last-first<<endl;

    }
    return 0;
}