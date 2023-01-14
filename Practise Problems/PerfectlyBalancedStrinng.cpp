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

        string s;
        cin>>s;

        bool AllEqual = true;

        rep(i,0,s.length()-1)
        {
            if(s[i] != s[i+1])
            {
                AllEqual = false;
                break;
            }
        }

        if(AllEqual)
        {
            cout<<"YES"<<endl;
            continue;
        }

        set<char>l;
        rep(i,0,s.length())
        {
            if(l.find(s[i]) == l.end())
            {
                l.insert(s[i]);
            }
        }

        int m = l.size();
        int flag = 1;
        int n = s.length();
        for(int i = 0; i<n;i++)
        {
                       
            if((i+m) <n && s[i+m] != s[i])
            {
                
                flag = 0;
                 cout<<"NO"<<endl;    
                break; 
            }
        }
        if(flag)
            cout<<"YES"<<endl;
    }
    return 0;
}