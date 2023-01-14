#include <bits/stdc++.h>
#include <set>
// #include "stdafx.h"
// #pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;

#define ll long long
#define fo(i,n) for(ll i=0;i<n;i++)

bool check(vector<ll>arr,int n)
{
    fo(i,n){
        if(arr[i] != 0)
            return false; 
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        ll maxi = 0; 
        vector<ll> A(n);
        fo(i,n){
            cin>>A[i];
            
        }

        int count = 0;
        set<int> B;

        while(!check(A,n))
        {
             
            fo(i,n)
            {
                if(A[i] != 0)
                {
                    int x = floor(log2(A[i]));
                    int y = pow(2,x);

                    for(auto x: B)
                    {
                       cout<<x<<endl;
                    }
                    
                    //cout<<B<<endl;

                    // if(B.find(y) == B.end())
                    // {
                    //     B.insert(y);
                    //     count++;
                    //     A[i] = A[i] - y;
                    // }
                }
            }

        }


        
          
        cout<<count<<endl;
    }

    
    return 0;
}



// while(!check(A,n)){

        //     count++;
            // int k = 0;
            // fo(i,n){
            //     maxi = max(maxi,A[i]);
            //     if (maxi == A[i])
            //     {
            //         k = i;
            //     } 
            // }    
            // float X = pow(2,(floor(log2(maxi))));
            // cout<<"X"<<X<<endl;

            // for(int i = k ;i< n; i++)
            // {
            //     if(A[i]>=X){

            //         A[i] -= X;
            //     }
            //     else
            //         break;

            // }

           
            // for(int i = k-1 ;i>= 0; i--)
            // {
            //     if(A[i]>=X){

            //         A[i] -= X;
            //     }
            //     else
            //         break;

            



// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         ll n;
//         cin>>n;
//         ll maxi = 0; 
//         vector<ll> A(n);
//         fo(i,n){
//             cin>>A[i];
//         }
        


//     }
// }