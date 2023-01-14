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
        vector<int>a(n);
        vector<vector<int>> b;
        rep(i,0,n)
        {
            cin>>a[i];
        }

        for(int i=0; i<n; i++)
        {
            int itr = max_element(a.begin(), a.end())-a.begin();
            if(itr != n-i-1){
                b.push_back({itr+1,n-i,1});
            }
            
            a.erase(a.begin()+itr);
            
        }
        cout<<b.size()<<endl;
        for(auto i: b)
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;

        
    }
    return 0;
}