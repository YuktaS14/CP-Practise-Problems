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
        string s;
        cin>>s;

        if(n==1)
        {
            if(s[0]== 'R' || s[0] == 'B')
            {      
                cout<<"NO"<<endl;
            }
            else
                cout<<"YES"<<endl;
             continue;
        }
        
        ll b = 0, r = 0,flag = 1;

        for(ll i = 0;i<n;i++)
        {
            if(s[i] == 'W')
            {
                if((r != 0 && b== 0) || (r==0 && b!=0))
                {
                    cout<<"NO"<<endl;
                    flag = 0;
                    break;
                }
                r = 0;b=0;
            }
            else{
                if(s[i] == 'R')
                    r++;
                else
                    b++;
            }
        }

        if(flag == 0)
            continue;
        if((r != 0 && b== 0) || (r==0 && b!=0))
        {
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;


    }
    return 0;
}