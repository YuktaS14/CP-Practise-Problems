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
        ll n,a,b;
        cin>>n>>a>>b;

        ll el = n/2 -1;
        // n-6,a-5
        if((n-a) < el || ((a<b) && (n-a-1) < el))
        {
            cout<<-1<<endl;
            continue;
        }

        if((b-1) < el || ((a<b) && (b-2) < el))
        {
            cout<<-1<<endl;
            continue;
        }

        set<ll>s;
        rep(i,1,n+1)
        {
            s.insert(i);
        }

        ll size = 1,i = n;
        while(size < n/2)
        {
            if(i == a || i== b)
            {
                i--;
                continue;
            }
            cout<<i<<" ";
            s.erase(i);
            i--;
            size++;
        }

        cout<<a<<" "<<b<<" ";
        s.erase(a);s.erase(b);
        for(auto it : s)
        {
            cout<<it<<" ";
        }   
        cout<<endl;    
    }

    return 0;
}