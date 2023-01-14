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
        queue<int>s;
        queue<int>f;

        vector<int>d(n);
        rep(i,0,n)
        {
            int si;
            cin>>si;
            s.push(si);
        }

        rep(i,0,n)
        {
            int fi;
            cin>>fi;
            f.push(fi);
        }

        int t1= 0,t2 = 0,prev = 0;

        rep(i,0,n)
        {            
            t1 = s.front();
            t2 = f.front();
            s.pop();f.pop();

            if(prev<t1)
            {
                d[i] = t2-t1;
            }
            else
            {
                d[i]= t2-prev;
            }

            prev = t2;            
        }

        rep(i,0,n)
        {
            cout<<d[i]<<" ";
        }
        cout<<endl;

    }

    return 0;
}