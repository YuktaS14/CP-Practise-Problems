#include <bits/stdc++.h>
#include <set>
using namespace std;
#define ll long long
//#define fo(i,n) for(ll i=0;i<n;i++)
#define vvi vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define ff first
#define ss second

const int N= 1e7, MOD = 1e9+7;



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;

        int a[n][m];
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                cin>>a[i][j];
            }
        }

        int ans = 0;
        int sum = 0;
        rep(k,0,n)
        {
            rep(l,0,m)
            {
                
                int sum = 0;
                int i = k, j = l;

                while(i >= 1 && j >= 1)
                {
                    sum = sum+ a[i-1][j-1];
                    i--; j--;
                }

                i = k, j =l;
                while(i>=1 && j < m-1)
                {
                    sum = sum+ a[i-1][j+1];
                    i--; j++;
                }

                i = k, j =l;
                while(i < n-1 && j< m-1)
                {
                    sum = sum + a[i+1][j+1];
                    i++;j++; 
                }

                i = k, j =l;
                while(i < n-1 && j>=1)
                {
                    sum = sum + a[i+1][j-1];
                    i++;j--;
                }


                i = k, j =l;
                // if(i == 2 && j == 2)
                //     cout<<sum<<"s"<<endl;

                ans = max(ans,(sum+ a[i][j]));
            }
        
        }

        cout<<ans<<endl;

    }


}