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

int checkPal(string & s)
{
    int flag = 1;
    for(int i = 3;i<s.size()+1; i++)
    {
        flag = 1;
        int mid = i/2;
        for(int j= 0; j<mid; j++)
        {
            if(s[j] != s[i-j-1])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            return i;
        }        
    }
    return 0;
}

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

        int flag = 1,flag1=1;
       
        
        int i = 0,ans = 0;
        while(s.size()>1)
        {
            if(s[0] == '(' && s[1] == '(')
                flag = 0;
            else if(s[0] == '(' && s[1] == ')')
                flag = 0;
            else if(s[0] == ')' && s[1] == ')')
                flag = 0;
            else 
                flag = 1;
            if(flag == 0)
            {
                s.erase(0,2);
                ans++;
                //i=0;
            }
            else
            {
                int t = checkPal(s);
                //cout<<t<<"kk";
                if(t!= 0)
                {
                    ans++;
                    s.erase(0,t);
                   // i=0;
                }
                else
                {
                    flag1 = 0;
                   
                    break;
                }
            }   
            //cout<<s.size()<<" "<<s<<endl;            
        }
        if(flag1 == 0)
        {
            cout<<ans<<" "<<s.size()<<endl;
        }
        else
            cout<<ans<<" "<<s.size()<<endl;
    }
    return 0;
}