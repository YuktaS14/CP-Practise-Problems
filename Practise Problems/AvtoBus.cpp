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
    while(t-- )
    {
        ll n;
        cin>>n;

        if(n%2 != 0){
            cout<<-1<<endl;
            continue;
        }

        ll min = 0, max = 0,n2 = n;
        
        if((n%6 == 2) && (n% 4 == 2)){
            if(n == 2 || n==1 || n == 0){
                cout<< -1<<endl;
                continue;
            }
            max = n/4;
            min = n/6+1;
        }           

        else{
            
            while(n%4 != 0)
            {
                n = n-6;
                max++;
            }
            max += n/4;
            while(n2%6 != 0)
            {
                n2 = n2-4;
                min++;
            }
            min += n2/6;
        }

        cout<<min<<" "<<max<<endl;
    }

    return 0;
}