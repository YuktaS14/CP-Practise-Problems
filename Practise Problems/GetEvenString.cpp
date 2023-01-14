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


int dp[200005];
int solve(string &s, int i)
{
    if(i>=s.size()) return 0;

    if(dp[i]!=-1) return dp[i];

    if(i == s.size() - 1) return 1;
    if(i<s.size()-1 && s[i] == s[i+1])  return solve(s,i+2);

    else
    {
        int j;
        for(j = i+1; j<s.size(); j++)
            if(s[j] == s[i])  break;
        if(j == s.size())
            return 1+solve(s, i+1);
        else
        {
            int c1 = j-i-1+solve(s,j+1);
            int c2 = 1+solve(s,i+1);


            return dp[i] = min(c1,c2);
        }
    }



}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

            
        rep(i,0,n) dp[i] = -1;

        int ans = solve(s,0);
        cout<<ans<<endl;


    }

    return 0;
}