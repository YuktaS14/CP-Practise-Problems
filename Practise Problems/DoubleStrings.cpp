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


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s[n];
        int ans[n];

        set<string> set1;
        rep(i,0,n)
        {
            string s1;
            cin>>s1;
            s[i] = s1;
            set1.insert(s1);
            ans[i] = 0;
        }
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 1; j< s[i].size(); j++)
            {
                string s1 = "",s2 = "";
                for(int k = 0; k<j ;k++)
                    s1+=s[i][k];
                for(int k = j; k<s[i].size(); k++)
                    s2+=s[i][k];
                
                if(set1.find(s1) != set1.end() && set1.find(s2) != set1.end())
                {
                    ans[i] = 1;
                    break;
                }
            }
        }
        rep(i,0,n)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}