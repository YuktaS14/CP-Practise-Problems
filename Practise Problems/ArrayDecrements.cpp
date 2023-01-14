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
        vector<int> b(n);

        rep(i,0,n)
            cin>>a[i];
        
        rep(i,0,n)
            cin>>b[i];
        int val = a[0]-b[0];
        
        set<int>s;
        
        int flag = 1;
        
        
        for(int i = 0; i<n; i++)
        {
            
            if(b[i] != 0)
            {
                if(b[i]>a[i])
                {
                    cout<<"N--O"<<endl;
                    flag = 0;
                    break;
                }
                
        
                val = a[i]-b[i];
                s.insert(val);                            
            }
            
        }

        if(flag == 0)
            continue;

        if(s.size() == 0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(s.size() != 1)
        { 
            cout<<"NO"<<endl;
            continue;
        }
        val = *s.begin();

        rep(i,0,n)
        {
            if(b[i] == 0)
            {
                if((a[i]-b[i]) > val)
                {
                    cout<<"NO"<<endl;
                    flag = 0;
                    break;
                }
            }
        }


        if(flag)
            cout<<"YES"<<endl;
        
    }

    return 0;
}