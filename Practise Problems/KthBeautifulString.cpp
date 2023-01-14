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
        int n,k;
        cin>>n>>k;

        string s(n,'a');
        //cout<<s<<endl;

        
        int j = 0;
        rep(i,1,n+1)
        {
            j+=i;
            if(k<=j)
            {
                s[n-1-i] = 'b';
                int m = j-k;
                s[(n-1-i)+ m+1] = 'b';
                break;
            }
        }

        cout<<s<<endl;
    }
    return 0;
}