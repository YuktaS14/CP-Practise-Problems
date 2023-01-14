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
        ll N,K;
        cin>>N>>K;

        if(K==1)
        {
            if(N%2== 0)
                cout<<"EVEN"<<endl;
            else
                cout<<"ODD"<<endl;
        }

        else if (K == 2)
            cout<<"ODD"<<endl;
        else
        {
            cout<<"EVEN"<<endl;

        }


    }
    return 0;
}