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
    ll t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int>m;

        rep(i,0,n)
        {
            int t;
            cin>>t;
            m[i+1] = t;
        }

        string s;
        cin>>s;

        vector<pair<int,int>>liked;
        vector<pair<int,int>>disliked;

        rep(i,0,n)
        {
            if(s[i] == '1')
                liked.push_back({m[i+1],i+1});
            else
                disliked.push_back({m[i+1],i+1});
        }

        sort(liked.begin(),liked.end());
        reverse(liked.begin(),liked.end());
        sort(disliked.begin(),disliked.end());
        reverse(disliked.begin(),disliked.end());

        vector<int> q(n);

        int val = n;
        rep(i,0,liked.size())
        {
            q[liked[i].second - 1] = val;
            val--;
        }

        rep(i,0,disliked.size())
        {
            q[disliked[i].second - 1] = val;
            val--;
        }

        rep(i,0,n)
        {
            cout<<q[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}

// 1 2 3 4 5 6 7 8
// 2 3 1 8 5 4 7 6
// 0 1 1 1 0 0 0 1
//dislike 1,5,6,7
//like  2,3,4,8
//liked -- 3,1,8,6   3,2,8,4 songs -- 5,6,7,8
//disliked- 2,5,4,7


//3,2  1,3  8,4  6,8

//1,3  3,2  6,8  8,4  