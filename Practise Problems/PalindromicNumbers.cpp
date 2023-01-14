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
        ll n;
        cin>>n;

        string num1;
        
        cin>>num1;

        
        if(num1[0] == '9')
        {
            string ans = "";
            
            
            int carry = 0;
            for(int i = n-1; i>=0;i--)
            {
                int val = 1-carry;
                int v = num1[i] - '0';
              
                if(val>= v)
                {
                    //char t = (char)(0);
                    ans+= (char)('0' + (val-v));
                    //cout<<t<<"nnn"<<endl;
                    carry = 0;
                }
                else
                {
                   
                    if (val == 0)
                        ans+= (char)('0' + (10-v));
                    else
                    {    ans+= (char)('0' + (11-v));
                       
                    }
                    carry = 1;
                }
            }
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
        }
        else
        { 
            for(int i = 0; i<n; i++)
            {
                int x = num1[i]-'0';
               cout<< 9-x;
            }
            cout<<endl;
        }
        //cout<<"jhu"<<endl;

       

    }

    return 0;
}