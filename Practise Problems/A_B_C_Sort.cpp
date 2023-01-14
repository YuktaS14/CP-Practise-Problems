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
        vector<int> a(n), b(n),c(n);

        rep(i,0,n) cin>>a[i];

        int j = 0;
        if(a.size()%2 != 0)
        {
            c[j] = a[0];
            j ++;            
        }

        int i = j;
       while(i<(n-1))
       {
           if(a[i+1]<a[i])
           {
               c[i] = a[i+1];
               c[i+1] =  a[i];
           }
           else
           {
               c[i+1] = a[i+1];
               c[i] =  a[i];
           }
           i += 2;

       }
        int flag = 0;

        rep(i,0,n-1)
        {
            if(c[i]>c[i+1])
            {
                cout<<"NO"<<endl;
                flag = 1;
                break;
            }

        }
    

       

        if(flag == 0)
            cout<<"YES"<<endl;
        
            

    }
    return 0;
}