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
        char c;
        cin>>n>>c;

        string s;
        cin>>s;

        int flag = 0,flag1 = 0;
        

        rep(i,0,n)
        {
            if(s[i] != c)
            {
                flag=1;
                break;               
            }
        }

        if(flag==0)
        {
            cout<<0<<endl;
            continue;
        }
       
       for(int i = n/2; i<n; i++)
       {
           if(s[i] == c)
           {
               cout<<1<<endl;
               cout<<i+1<<endl;
               flag1 = 1;
               break;
           }
       }


        if(flag1 == 0)
        {
            cout<<2<<endl;
            cout<<n<<" "<<n-1<<endl;
        }
    }
    return 0;
}