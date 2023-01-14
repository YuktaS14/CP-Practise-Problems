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

        int a,b,c;

        if(n%2 == 0)
        {
            a= n-3;
            b= 2;
            c= 1;
        }
        else
        { //n= 9
            int h = n/2;
            if(h%2 == 0)
            {
                a = n/2 + 1; //5
                b= n/2 - 1; //3

                c= 1;
            }
            else
            {//n= 11
                a= h-2;  //3
                b= h+2;  //7
                c= 1;
            }
        }

        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;
}

// n-even
//6 -- 3 3
//1 4 