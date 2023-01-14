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

int score(vector<vector<int>>& a,int i ,int j,int n,int m)
{
    int ans = 0;
    int id = i,jd = j;

    while((i-1 >= 0) && (j-1 >= 0))
    {
        ans+=a[i-1][j-1];
        i--;
        j--;
       // cout<<"leftup ";
    }
    i = id; j= jd;
    while((i+1<n) && (j-1>=0))
    {
        ans+=a[i+1][j-1];
        i++;
        j--;
        //cout<<"leftdown ";
    }
     i = id; j= jd;
     while(((i+1)<n) && ((j+1)<m))
    {
        ans+=a[i+1][j+1];
        i++;
        j++;
        //cout<<"rightdown ..(j,m) "<<j+1<<m;
    }
     i = id; j= jd;
     while(((i-1)>=0) && ((j+1)<m))
    {
        ans+=a[i-1][j+1];
        i--;
        j++;
        //cout<<"rightup ";
    }

    return ans;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>a(n,vector<int>(m));

        rep(i,0,n)
        {
            rep(j,0,m)
            {
                cin>>a[i][j];
            }
        }

        int maxSum = 0;
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                int ans = a[i][j];
                //cout<<ans<<"...";
                ans += score(a,i,j,n,m);
                maxSum = max(maxSum,ans);
                //cout<<ans<<"a---i,j---"<<i<<" "<<j<<endl;
                
            }
        }
        cout<<maxSum<<endl;

    }
    return 0;
}