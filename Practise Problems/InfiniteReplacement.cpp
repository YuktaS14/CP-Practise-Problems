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

    int q;
    cin>>q;

    while(q--)
    {
        string s, t;
        cin>>s;
        cin>>t;

        ll ans = 0;

        if(t.find("a") != string::npos)
        {
            if(t.length() == 1)
                cout<<1<<endl;
            else
                cout<<-1<<endl;

            continue;
        }

        else{
            
            // while(s.find('a') != string::npos)
            // {
            //     int pos = s.find('a');
            //     s.replace(pos,1,t);

                

            // }

            ans = pow(2,(s.length()));
            cout<<ans<<endl;
        }
        


    }


    return 0;
}