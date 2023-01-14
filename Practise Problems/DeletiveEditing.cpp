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
        string s,t;
        cin>>s>>t;
        
        int n = t.length();
        int m = s.length();
        int i = 0,j = 0;
        int flag = 1;

        while(i<n)
        {
            while(j<m)
            {
                if(s[j] == t[i])
                {
                    j++;
                    break;
                }
                else
                    j++;
                
            }
            if(j == m && s[j-1] != t[i])
            {
                if(i!= n)
                {
                    cout<<"NO"<<endl;
                    flag = 0;
                }
                break;
            }
            i++;
                       
        }

        
        
       // else
        //{
            if(j!=m)
            {
                for(int k = j; k<m;k++)
                {
                    if(t.find(s[k]) != string::npos)
                    {
                        cout<<"NO"<<endl;
                        flag = 0;
                        break;
                    }
                }
          
            }
        //}

        if(flag)
            cout<<"YES"<<endl;
        
    }

    return 0;
}

// int n;
//         cin>>n;
//         vector<int>a(n);

//         rep(i,0,n)
//             cin>>a[i];
        
//         int ans= 0,flag = 1;

//         if(n==1)
//         {
//             cout<<0<<endl;
//             continue;
//         }
//         for(int i = n-1; i>0; i--)
//         {
//             if(a[i]>a[i-1] && a[i]>=i)
//                 continue;
//             else{
//                 if(a[i]<i)
//                 {
//                     flag = 0;
//                     cout<<-1<<endl;
//                     break;
//                 }
//                 else{
//                     while(a[i]<=a[i-1])
//                     {
//                         a[i-1] /=2;
//                         ans++;
//                     }
//                 }
//             }
//         }
//         // rep(i,0,n)
//         //     cout<<a[i]<<" ";
//         // cout<<endl;

//         if(flag)
//         {
//             rep(i,0,n-1)
//             {
//                 if(a[i]>= a[i+1])
//                 {
//                     flag = 0;
//                     cout<<-1<<endl;
//                     break;
//                 }
//             }
//         }
//         if(flag)
//             cout<<ans<<endl;