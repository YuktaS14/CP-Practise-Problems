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
        int n,m;
        cin>>n>>m;
        vector<vector<char>>a(n,vector<char>(m));
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                cin>>a[i][j];
            }
        }

        for(int j = 0; j<m; j++)
        {
            int k = n-1;
            for(int i =n-1; i>=0; i--)
            {
                if(a[i][j] == '.')
                    continue;
                else if(a[i][j] == '*')
                {
                    a[i][j] = '.';
                    a[k][j] = '*';                    
                    k--;
                }
                else if(a[i][j]== 'o')
                {
                    k= i-1;
                }
            }
        }

        rep(i,0,n)
        {
            rep(j,0,m)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        }
        

    }
    return 0;
}