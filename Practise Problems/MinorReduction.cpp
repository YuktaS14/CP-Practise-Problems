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
        string x;
        cin>>x;

        int sum = 0,ans= 0,maxi = 0,index = 0;
        int flag = 0;
        rep(i,0,x.length()-1)
        {
            sum = (int)(x[i]-'0') + (int)(x[i+1]-'0');

            if((sum/10 == 0) && (flag == 0))
            {

                if(maxi < sum)
                {
                    maxi = sum;
                    index = i;
                } 
               
                if(sum > (int)(x[i]-'0'))
                {

                    flag = 1;     
                }         
            }
            else if(sum/10 != 0)
            {
                flag = 1;
                index = i;
                maxi = sum;
                if(sum/10 > x[i])
                {
                    break;
                }
            }            
        }

        rep(i,0,index)
        {
            cout<<x[i];
        }
        cout<<to_string(maxi);
        index+=2;
        if(index == x.length())
        {
            cout<<endl;
            continue;
        }
        rep(i,index,x.length())
        {
            cout<<x[i];
        }
        cout<<endl;

    }
    return 0;
}