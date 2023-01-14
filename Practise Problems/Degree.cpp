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
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>A(n);
        
        
        fo(i,n){
            cin>>A[i];
        }

        for(int i = n-1; i >= 0 ; i--){
            if(A[i] != 0)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}