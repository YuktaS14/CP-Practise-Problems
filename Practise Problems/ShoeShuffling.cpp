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
        vector<int>s(n);
        bool isEqual = 1;
        bool isDiff = 1;
        map<int,int>m;
        rep(i,0,n)
        {
            cin>>s[i];
            m[s[i]]++;
            if(i>0)
            {
                if(s[i] != s[i-1])
                    isEqual = 0;
                
                if(s[i] == s[i-1])
                    isDiff = 0;
            }

        }

        // if(isEqual)
        // {
        //     rep(i,0,n)
        //         cout<<n-i<<" ";
        //     cout<<endl;
        //     continue;
        // }
        if(isDiff)
        {
            cout<<-1<<endl;
            continue;
        }
        int flag = 0;

        for(auto it: m)
        {
            if(it.second == 1)
            {
                cout<<-1<<endl;
                flag =1;
                break;
            }
        }
        if(flag)
            continue;

        int i = 0;
        while(i<n)
        {
            int freq = m[s[i]];
            for(int j = 0; j<freq;j++)
                cout<<i+ ((j+1)%freq)+1<<" ";
            
            i+=freq;
        }
        cout<<endl;   

        

    }
    return 0;
}