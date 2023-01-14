#include <bits/stdc++.h>
#include <set>
// #include "stdafx.h"
// #pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;

#define ll long long
#define fo(i,n) for(ll i=0;i<n;i++)




int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        int ans = 0;
        fo(i,n)
            cin>>a[i];
            
        
        if(n == 1)
        {
            cout << 0<<endl;
            continue;
        }

            bool final = false;

            while(1){
                int i = 1;
                bool flag = true;
                while(i<n){
                    if(a[i-1] == 0 && a[i] == 0){
                        final = true;
                        break;
                    }

                    if(a[i-1] >= a[i]){
                        ans++;
                        a[i-1]/= 2;
                        flag = false;
                        break;
                    }

                    i++;
                }

                if (flag) break;

            }
            if(!final)
                cout<<ans<<endl;
            else
                cout<< -1<<endl;            
        }

    
    

    return 0;
}