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
        string w;
        cin>>w;
        int p;
        cin>>p;

        map<int,vector<int>>m;

        int price = 0;

        rep(i,0,w.length())
        {
            int v = (int)(w[i] - 'a');
            v++;
            price+=v;
            m[v].push_back(i);
        }

        
        while(price> p)
        {
        for(int i = 26; i>0; i--)
        {
            
            
            for(auto it: m[i])
            {
                price-=i;
                w[it] = '.';
                if(price<= p)
                    break;
            }
            
            if(price<=p)
                break;
        }
        }

        string ans = "";
        for(auto it:w)
        {
            if(it != '.')
                ans+=it;
        }

        cout<<ans<<endl;
    }
    return 0;
}