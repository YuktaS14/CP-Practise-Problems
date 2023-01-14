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
        ll n;
        cin>>n;

        
        //cout<<n<<endl;

        if(n/100 == 0){

            
           int ans = n%10;
           cout<<ans<<endl;
            continue;
        }

        int mini = 9;
        while(n > 0)
        {
            int d = n%10;
            mini = min(mini, d);
            n= n/10;
                      
        }

        cout<<mini<<endl;
    }

}