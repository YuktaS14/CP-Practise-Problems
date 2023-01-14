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

int checkPalindrome(int num,vector<ll>& a,int n)
{
    int i=0, j= n-1;
    while(i<j)
    {
        if(a[i] == num)
        {
            i++;
            continue;
        }
        if(a[j] == num)
        {
            j--;
            continue;
        }

        if(a[i] == a[j])
        {
            i++;
            j--;
            continue;
        }
        else
        {
            return 0;
        }        
    }
    return 1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>a(n);

        rep(i,0,n)
            cin>>a[i];
        
        if(n<=2)
        {
            cout<<"YES"<<endl;
            continue;
        }

        if(checkPalindrome(-1,a,n))
        {
            cout<<"YES"<<endl;
            continue;
        }
       int i = 0, j= n-1;
       int flag = 0;
       while(i<j)
       {
           if(a[i] == a[j])
           {
               i++;
               j--;
               continue;
           }
          else
          {
               flag += checkPalindrome(a[i],a,n);
               flag += checkPalindrome(a[j],a,n);
               break;
          }
       } 
        if(flag == 0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}