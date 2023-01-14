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

        if(n==1)
        {
            cout<<"YES"<<endl;
            continue;
        }

        // int flag = 1;
        // int back = 0;
        
        int flag = 0;
        int first = a[0]-1;
        while(1)
        {
            
            rep(i,0,n)
            {
                int num = first+i;
               
                if(abs(a[i]-num) >1)
                {
                   
                    flag++;
                    break;
                }
            }
            first ++;
            if(first == a[0]+2)
                break;
        }
        if(flag == 3)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
            
    }
    return 0;
}