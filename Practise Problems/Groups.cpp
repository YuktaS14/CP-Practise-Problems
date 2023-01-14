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
        ll a[n][5];
        rep(i,0,n)
        {
            rep(j,0,5)
            {
                cin>>a[i][j];
            }
        }

        int g = n/2;
        int flag = 0;
        
       
        rep(i,0,4)
        {
            int j = i+1;
            
            while(j<5)
            {
                int grp1= 0, grp2 = 0,grp =0;
                rep(k,0,n)
                {
                    if(a[k][i] == 1 && a[k][j] == 0)
                        grp1++;
                    
                    else if(a[k][i] == 0 && a[k][j] == 1)
                        grp2++;

                    else if(a[k][i] == 1 && a[k][j] == 1)
                        grp++;
                }

                
                if(grp1 <= g && grp2<= g && n == grp1+grp2+grp)
                {
                   cout<<"YES"<<endl;
                   flag = 1;
                   break;
                }
                j++;
            }
            if(flag)
                break;            
        }
        if(flag == 0)
            cout<<"NO"<<endl;
    }
    return 0;
}