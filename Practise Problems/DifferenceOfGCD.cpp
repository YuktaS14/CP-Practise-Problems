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


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,l,r;
        cin>>n>>l>>r;

        vector<int>ans;
        ans.push_back(l);
        int count = 1;
        rep(i,2,n+1)
        {
            if(l%i == 0)
            {
                ans.push_back(l);
                count++;
            }
            else
            {
                int next = l/i;
                next = (next+1)*i;
                if(next>r)
                {
                     count = 0;
                    break;                   
                }
                else
                    ans.push_back(next);

            }

        }
        if(count == 0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            rep(i,0,n)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
        
            

    }
    return 0;
}