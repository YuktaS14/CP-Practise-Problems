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
   
    
        int n,q;
        cin>>n>>q;

        string s;
        cin>>s;

        int count = 0;
        rep(i,1,n-1)
        {
            if((s[i-1] == 'a') && (s[i] == 'b') && (s[i+1] == 'c'))
            {   
                 count++;
            }
        }
        
        
         while(q--)
         {
             int pos; char ch;
             cin>>pos>>ch;

             pos--;
             int st = max(0,pos-2);
             int end = min(n-1,pos+2);
             rep(i,st,end-1)
             {
                 if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c')
                     count--;
             }
             s[pos] = ch;
            rep(i,st,end-1)
             {
                 if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c')
                     count++;
             }
             cout<<count<<endl;          

         }
  
    return 0;
}