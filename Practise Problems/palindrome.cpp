#include <bits/stdc++.h>
// #include "stdafx.h"
// #pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;

#define ll long long
#define fo(i,n) for(ll i=0;i<n;i++)

bool palindrome(string B, int n)
{
    fo(i,n)
    {   
        if(B[i] != B[n-i-1])
        {
            return false;
        }
    }
    
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string A;
        cin>>A;

        string B = A;
        int count1 = 0;
        int count2 = 0;
        fo(i,n)
        {
            if(A[i] != A[n-i-1]){

                if(i< (n-i-1))
                {
                    count1++;
                    
                    //cout<<"A--"<<A<<endl;

                    // A[i] = '1';
                    // A[n-1-i] = '1';
                }
                else
                    break;
            }
        }

        if(count1%2 == 0)
                cout<<count1/2<<endl;
            else
                cout<<(count1/2)+1 <<endl;
            
        // if(!palindrome(B,n))
        //     count2 = count1;
        // cout<<min(count1,count2)<<endl;
    }
    return 0;
}