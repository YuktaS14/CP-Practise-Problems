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
        int pa,pb,qa,qb;
        cin>>pa>>pb>>qa>>qb;

        int maxp = 0, maxq = 0;
        maxp = max(pa,pb);
        maxq = max(qa,qb);

        if(maxp<maxq)
            cout<<"P"<<endl;
        else if(maxq<maxp)
            cout<<"Q"<<endl;
        else
            cout<<"TIE"<<endl;
    }

    return 0;
}