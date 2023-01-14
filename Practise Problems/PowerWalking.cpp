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

         vector<int> a(n);
         map<int,int>m;

         vector<int>ans;

         rep(i,0,n)
         {
            cin>>a[i];
            m[a[i]]++;
         }

         rep(i,0,n)
        {
            if(m.size()>i)
                ans.push_back(m.size());

            else
                ans.push_back(i+1);
        }

        for(auto it: ans)
            cout<<it<<" ";

        cout<<endl;

        
        
    }
    return 0;
}