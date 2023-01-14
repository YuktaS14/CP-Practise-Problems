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
        {
            cin>>a[i];
        }

        if(n%2 != 0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        sort(a.begin(),a.end());

        int mid = n/2;

        vector<int>b(n);
        int k = 0;
        //cout<<"YES"<<endl;
        for(int i = 0; i<mid; i++)
        {
            b[k++] = a[i];
            b[k++] = a[mid+i];

        }


        int flag = 0;
        rep(i,0,n-1)
        {
            if(b[i] == b[i+1])
            {
                flag = 1;
                break;
            }
        }
        if(flag) cout<<"NO";
        else
        {
            cout<<"YES"<<endl;
            rep(i,0,n) 
                cout<<b[i]<<" ";
        }
        cout<<endl;
        


    }

    return 0;
}