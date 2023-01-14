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
        string s;
        cin>>s;

        int ans = 0;

        int n1 = s[0]-'a'+1;
        int n2 = s[1]- 'a'+1;

        if(n1 < n2)
            ans = 25*(n1-1)+n2-1;
        else
            ans = 25*(n1-1)+n2;

        cout<<ans<<endl;
    }

    return 0;

}