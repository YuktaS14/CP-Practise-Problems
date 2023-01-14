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
        string s;
        cin>>s;

        int l = 0,r = 0;
        int size = 0;
        int ans = 0;
        int mini = n+2;
        while(l<=r && r<=n)
        {
            while(r<k)
            {                 
                if(s[r] != 'B')
                    ans++; 
                r++;
                mini = ans;
            }
            //int ans = 0;
            // for(int i = l; i<r; i++)
            // {
                
            // }

            
            if(l !=0 && (r-l) == k && r<=n)
            {
                if(s[l-1] == 'B')
                    ans++;
                if(s[r-1] == 'B')
                {
                    ans--;
                }
                mini = min(mini,ans);
            }
            l++;r++;
        }

        cout<<mini<<endl;
    }

    return 0;
}