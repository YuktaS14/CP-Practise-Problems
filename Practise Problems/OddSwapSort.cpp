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
        vector<int>a,odd,even;
        int flag = 0;

        rep(i,0,n)
        {
            int t = 0;
            cin>>t;
            a.push_back(t);
            if(a[i]%2 == 0)
                even.push_back(a[i]);
            else
                odd.push_back(a[i]);        
        }

        

       rep(i,1,even.size())
       {
           if(even[i] < even[i-1])
           {
               flag = 1;
               break;
           }
       }
 
        rep(i,1,odd.size())
       {
           if(odd[i] < odd[i-1])
           {
               flag = 1;
               break;
           }
       }

        

        if(flag== 0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    return 0;
}