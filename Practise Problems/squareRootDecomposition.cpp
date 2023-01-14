#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for(ll i=0;i<n;i++)

const int N = 1e5+2, MOD = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    int blockSize = sqrtl(n) + 1;
    vector<int> block(blockSize);

    for(int i = 0; i<n; i++)
    {
        block[i/blockSize] += arr[i];
    }

    int querries;
    cin>>querries;

    while(querries--)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        int sum = 0;
        int i = l;
        while(i<=r){
            if(i%blockSize == 0 && i+blockSize-1 <= r){
                sum += block[i/blockSize];
                i+=blockSize;
            }
            else{
                sum += arr[i];
                i++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}