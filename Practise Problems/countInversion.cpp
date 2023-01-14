#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+2, MOD = 1e9+7;

ll merge(int arr[], int l, int mid, int r){
    ll inversions = 0;
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1];
    int b[n2];

    for(int i = 0; i<n1; i++)
        a[i] = arr[i+l];
    for(int i = 0; i<n2; i++)
        b[i] = arr[mid+1+i];
    
    int i = 0,j = 0, k= l; 
    while(i<n1 && j<n2)
    {
        if(a[i]<= b[j]){
            arr[k] = a[i];
            i++;k++;
        }
        else{
            arr[k] = b[j];
            inversions+=n1-i; 
            j++;k++;
        }
    }
    while(i<n1){
        arr[k] = a[i];
        i++;k++;
    }
    while(j<n2){
        arr[k] = b[j];
        j++;k++;
    }
    return inversions;
}

ll mergeSort(int arr[],int l, int r)
{
    ll inversions = 0;
    if(l<r){
        int mid = (l+r)/2;
        inversions += mergeSort(arr,l,mid);
        inversions += mergeSort(arr,mid+1,r);
        inversions += merge(arr,l,mid,r);
    }
    return inversions;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0;i<n; i++)
        cin>>arr[i];
    
    ll inversions = mergeSort(arr,0,n-1);
    cout<<inversions<<endl;

    return 0;
}