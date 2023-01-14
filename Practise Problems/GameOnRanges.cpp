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
       
       set<pair<int,int>>s;
       rep(i,0,n)
       {
           int l,r;
           cin>>l>>r;
           s.insert(make_pair(l,r));
       }

    
       
       
        
        for(auto it: s)
        {
            auto t = it;
            int l = t.first,r = t.second,d = 0;
            //s.erase({l,r});
           
            rep(i,l,r+1)
            {
                if(l == r)
                {
                    cout<<l<<" "<<r<<" "<<l<<endl;
                    break;
                }
                if((i+1 <= r) && (s.find({i+1,r}) != s.end()))
                {
                    cout<<l<<" "<<r<<" "<<i<<endl;
                    break;
                }
                else if((l<=i-1) && (s.find({l,i-1}) != s.end()))
                {
                    cout<<l<<" "<<r<<" "<<i<<endl;
                    break;
                }
            }
        }

       cout<<endl;
    }
    return 0;
}
