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

int maxi = 0;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>a(n);
        rep(i,0,n)
            cin>>a[i];

        if(n == 1)
        {
            cout<<"Mike"<<endl;
            continue;
        }
        
        int mini = INT_MAX; 
        int index = 0;
        if(n%2 == 1)
            cout<<"Mike"<<endl;
        else
        {
            rep(i,0,n)
            {
                if(a[i]<mini)
                {
                    mini = a[i];
                    index = i;
                }
            }

            if(index%2 == 0)
                cout<<"Joe"<<endl;
            else
                cout<<"Mike"<<endl;
        }

            
    } 
    
    return 0;
}




    //     int j = 0;
    //     if(n%2 == 1)
    //     {
    //         cout<<"Mike"<<endl;
    //     }
    //     else{
    //         rep(i,0,n)
    //         {
    //             if(mini > a[i])
    //             {   
    //                 j = i;
    //                 mini = a[i];     
                            
    //             }
                
                
    //         }
    //         if(j%2 == 0)
    //             cout<<"Joe"<<endl;
    //         else
    //             cout<<"Mike"<<endl;
    //     }

