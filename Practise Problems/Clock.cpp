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
        string s;
        int x;
        cin>>s>>x;

        int n = s.length();
        int flag = 0;
        int hr = 0, min = 0;
        rep(i,0,n)
        {
            if(s[i] == ':')
            {
                flag = 1;
                continue;
            }
            if(flag == 0)
                hr = hr*10 + s[i] - '0';
            
            else
                min = min*10 + s[i] - '0';
        }
        int t = 0;
        int ans = 0;
        int check;

        while(1)
        {
            t+=x;
            min += x;
            hr += min/60;
            min %= 60;

            hr %= 24;

            string p;

            if(hr<10)
                p+='0';
            p+=to_string(hr);

            p+=':';
            if(min<10)
                p+='0';
            p+=to_string(min);

            string q = p;
            reverse(p.begin(),p.end());

            //cout<<" p--"<<p<<" q--"<<q<<endl;
            check = 1;
            rep(i,0,n)
            {
                if(p[i] != q[i])
                {
                    //cout<<"--"<<endl;
                    check = 0;
                }
            }

            if(check != 0)
                ans++;
            
            if(t%1440 == 0)
                break;
        }

        cout<<ans<<endl;
    }
    return 0;
}