#include <bits/stdc++.h>
// #include "stdafx.h"
// #pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;

#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        int arr[4];
        cin>>n;
        fo(i,4) cin>>arr[i];

        int maxi = 0;
        fo(i,4){
            maxi = max(maxi,arr[i]);
        }

        cout<<maxi<<endl;        
    }

    return 0;
}