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
        vector<int>b(n);

        vector<pair<int,int>>m(n);

       vector<pair<int,int>>ans;

        //int ans = 0;
        rep(i,0,n)
            cin>>a[i];
        
        rep(i,0,n)
            cin>>b[i];

         rep(i,0,n)
        {
            m[i] = make_pair(a[i],b[i]);
        }
        

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        
        int flag = 1;
        rep(i,0,n)
        {
            flag = 0;
            rep(j,i,n)
            {
                if(m[j] == make_pair(a[i],b[i]))
                {
                    swap(m[i],m[j]);
                    flag =1;
                    if(i!=j)
                        ans.emplace_back(i,j);
                    break;
                } 

            }
            if(flag == 0)
            {
                cout<<-1<<endl;
                break;
            }
            
        }

        if(flag == 1)
        {
            cout<<ans.size()<<endl;
            for(auto it : ans)
                cout<<it.second+1<<" "<<it.first+1<<endl;        }
    }
    return 0;
}