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
        int a = 0, b = 0,c = 0;
        cin>>a>>b>>c;

        int x = 0,y = 0,z = 0;
        z = c;
        y = b+2*c;
        x = a+b+2*c;

        cout<<x<<" "<<y<<" "<< z<<endl;

        
    }
    return 0;
}