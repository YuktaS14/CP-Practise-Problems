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

// int gcd(int m, int n) {
//    int r = 0, a, b;
//    a = (m > n) ? m : n;
//    b = (m < n) ? m : n;
//    r = b;
//    while (a % b != 0) {
//       r = a % b;
//       a = b;
//       b = r;
//    }
//    return r;
// }
// int lcm(int m, int n) {
//    int a;
//    a = (m > n) ? m: n;
//    while (true) {
//       if (a % m == 0 && a % n == 0)
//          return a;
//          ++a;
//    }

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>p(n);

        rep(i,0,n)
        {
            cin>>p[i];
        }

        int j = 0,count = 0;
        
        while(j<n)
        {
            int k = j+1;
            count++;
            if(p[k] > p[j] && k<n)
            {
                while(p[k]>p[j] && k<n)
                {
                    k++;
                    j++;
                    if(j == n-1)
                        count--;
                }
            }
            else
            {
                j++;
            }

            
        }
        cout<<count<<endl;

        if(count == 1)
        {
            cout<<0<<endl;
            continue;
        }
        
        
    }    
    return 0;
}





//q2
//   ll N,K;
//         cin>>N>>K;
        
//         if(N==K)
//         {
//             cout<<0<<endl;
//             continue;
//         }

//         int g = (K%5) ? (K/5 +1) : (K/5) ;

//         int tg = (N%5) ? (N/5 + 1) : (N/5) ;
// //cout<<tg<<" "<<g<<endl;
//         cout<<tg-g<<endl;


// q3
// ll N,X;
//         cin>>N>>X;
//         string s = string(N,'a');



//         if((N%2 == 0 && X > N/2) || (N%2 != 0 && X>(N/2 +1)))
//         {
            
//             cout<<-1<<endl;
//             continue;
//         }
        
//         if(N== 1)
//         {
//             cout<<'z'<<endl;
//             continue;
//         }
//         //ll j = (N%2 == 0)? N/2 : (N/2 +1);

//        // cout<<j<<"j";
//         for(ll i = 0; i< X; i++)
//         {
            
//             s[i] = (char)('a' + i);
//             s[N-1-i] = (char)('a' + i);
       
//         }

//         cout<<s<<endl;


// q3
    // int t;
    // cin>>t;
    // while(t--)
    // {
    //     ll n;
    //     cin>>n;
        
    //     int ans = 0;

    //     for(int i = 1; i*i <= n;i++)
    //     {
    //         if(n%i == 0)
    //         {
    //             int div1 = i, div2 = n/i;
    //             if(div2 == 2) ans++;
    //             else ans += 2;

    //             if(div2 != div1 && div2 != n)
    //             {
    //                 if(div1 == 2) ans++;
    //                 else ans+=2;
    //             }
    //         }
    //     }
    //     cout<<ans<<"\n";
        
