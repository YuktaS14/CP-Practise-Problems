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
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;

        vector<int>a(n);
        ll sum = 0;

        rep(i,0,n)
        {
            cin>>a[i];
            sum+=a[i];
        }
        
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());

        //int i = 0,j = 0;
            ll s = 0;
        
        rep(i,0,n)
        {
            s+=a[i];
            a[i] = s;
        }
        
        while(q--)
        {
            ll x;
            cin>>x;
            if(x>sum)
            {
                cout<<-1<<endl;
                continue;
            }
           
                // while(j<n)
                // {
                //     s+=a[j];
                //     if(s>=x)
                //     {
                //         //flag = 0;
                //         while(i<j && (s-a[i])>= x)
                //         {
                //             i++;
                //         }
                //         cout<<(j-i+1)<<endl;
                //         break;
                //     }
                //     j++;
                // }

            ll  r = n-1, l = 0,ans = 0;

            while(l<=r)
            {
                ll mid = (l+r)/2;
                if(a[mid]>=x)
                {
                    ans = mid+1;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }

            cout<<ans<<endl;
             
            
        }
    }
}