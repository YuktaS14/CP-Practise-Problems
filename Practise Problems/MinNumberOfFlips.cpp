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
    cin >>t;

    while(t--)
    {
        int N;
        cin>>N;

        vector<ll>A(N);

        map<int, int>b;

        rep(i,0,N)
        {
            cin>>A[i];
            b[A[i]]++;
        }

        int temp = abs(b[-1]- b[1]);
        int ans = 0;

        if(temp%2 != 0){
            cout<<-1<<endl;
            continue;
        }
        else if(temp %2 == 0)
        {
            ans = temp/2;
        }

        cout<<ans<<endl; 
        

       
    }
    return 0;
}