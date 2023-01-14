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

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        set<int> s;
       

        int flag0 = 0, flag1 = 0;
        rep(i,0,n)
        {
            cin>>a[i];
            if(a[i] == 0)
            {
                flag0++;
            }
            s.insert(a[i]);

        }
        // int size = a.size();

        int ans = 0;

        // auto it = unique(a.begin(),a.end());
        // a.resize(distance(a.begin(),it));


        if(flag0 != 0 )
        {
            
            ans = a.size()-flag0;
        }
        else if (s.size() < a.size()){
            ans= a.size();
        }
        else
        {
            ans = 1+a.size();
        }

        cout<<ans<<endl;    
    }
}