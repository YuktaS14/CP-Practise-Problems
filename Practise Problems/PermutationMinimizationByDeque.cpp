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
        
        vector<int>p(n);
        rep(i,0,n)
            cin>>p[i];

         deque<int>d;

        rep(i,0,n)
        {
            if(d.empty())
            {
                d.push_back(p[i]);
            }
            else
            {
                if(p[i]<d.front())
                    d.push_front(p[i]);
                else
                    d.push_back(p[i]);
            }
        }

        for(auto it: d)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}