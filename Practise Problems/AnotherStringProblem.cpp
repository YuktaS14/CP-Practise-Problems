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

bool cmp(pair<string,int> a, pair<string,int> b){
    for(int i=0; i< a.first.size(); i++)
    {
        char ch1 = a.first[i];
        char ch2 = b.first[i];

        if(i%2 == 0)
        {
            if(ch1!=ch2){
                return (ch1<ch2);
            }
        }
        else{
            if(ch1!=ch2){
                return (ch1>ch2);
            }
        }
    }

    return(a.second<b.second);
}

int main()
{
    
    int n,m;
    cin>>n>>m;

    
    vector<pair<string,int>>s;

    rep(i,0,n)
    {
        string t;
        cin>>t;
        s.push_back({t,i+1});
    }     

    sort(s.begin(),s.end(),cmp);

    rep(i,0,n)
        cout<<s[i].second<<" ";
    
    
    return 0;
}