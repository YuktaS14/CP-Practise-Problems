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
        string s;

        cin>>s;

        int ans = 0;

        if(n == 2){
            ans = 2;
            cout<<ans<<endl;
            continue;
        }
        
    
        int mid = n/2;

        if(n%2 == 0 && n!=2)
        {
            int i  = 1;
            while((mid+i-1) < n)
            {
                if(s[mid+i-1] == s[mid])
                {
                    ans++;
                    i++;
                }
                else
                    break;
            }
            cout<<(2*ans)<<endl;

        }

        else
        {
            int i  = 1;
            
            while((mid+i) < n)
            {
                if(s[mid+i] == s[mid])
                {
                    //cout<<mid+i<<endl;
                    ans++;
                    i++;
                }
                else
                    
                    break;
            }
            cout<<(2*ans)+1<<endl;
            

        }

        
    }
}