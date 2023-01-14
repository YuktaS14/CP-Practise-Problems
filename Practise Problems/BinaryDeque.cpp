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
        int n,s;
        cin>>n>>s;

        vector<int>a(n);
        int sum = 0;
        rep(i,0,n)
        {
            cin>>a[i];
            sum+=a[i];
        }

        if(sum<s)
        {
            cout<<-1<<endl;
            continue;
        }
        if(sum == s)
        {
            cout<<0<<endl;
            continue;
        }
        
        int l = 0, r = 0;
        int size= 0;

        sum = 0;

        while(l<=r && r<n)
        {
            while((sum+a[r])<=s && r<n)
            {

                sum+=a[r];
                r++;
            }
            size = max(size,r-l);
            //cout<<size<<"s "<<endl;
            
            l++;
            if(a[l-1] == 1)
                sum--;            
        }

        cout<<n-size<<endl;


        
    }

    return 0;
}


//  int mid = n/2;
//         int l,r;
//         l = mid; r = mid;

//         int ans = 0;
//         while(l>=0 && r<n && ans <= s)
//         {
//             if(a[l] == 1 && ((ans+a[l]) <= s))
//             {
//                 ans+=a[l];
//                 l--;
//             }
//             if(a[r] == 1 && ((ans+a[r]) <= s))
//             {
//                 ans+=a[r];
//                 r++;
//             }
//           }