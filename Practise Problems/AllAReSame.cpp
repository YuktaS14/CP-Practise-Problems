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

int gcd(int a, int b)
{
    int result = min(a, b); 
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    return result; 
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        map<int,int>m;
        int mini = 999999;
        rep(i,0,n)
        {
            cin>>a[i];
            m[a[i]]++;
            mini = min(mini,a[i]);
        }

        int prev = 0,flag = 1;
        for(auto it : m)
        {
            if(it.first == mini)
                continue;
           
            int num = it.first - mini;
            if(prev == 0)
                prev = num;
            else
            {
                prev = gcd(num,prev);
            }

        }
        if(prev == 0)
            cout<<-1<<endl;
        else
            cout<<prev<<endl;       

    }
    return 0;
}