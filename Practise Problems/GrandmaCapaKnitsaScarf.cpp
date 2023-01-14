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
        string s;
        cin>>s;

        int ans = 1e9;

        for(int i = 'a'; i<= 'z'; i++)
        {
            int op = 0;
            int l= 0, r=n-1;
            while(l<=r)
            {
                if(s[l] == s[r])
                {
                    l++; r--;
                }
                else if(s[l] == i)
                {
                    op++;
                    l++;
                }
                else if(s[r] == i)
                {
                    op++;
                    r--;
                }
                else
                {
                    op = 1e9;
                    break;
                }
            }

            ans = min(ans,op);
        }
        if(ans == 1e9)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}