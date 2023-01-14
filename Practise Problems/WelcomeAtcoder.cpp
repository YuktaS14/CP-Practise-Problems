//D - FizzBuzz Sum Hard 



#include <bits/stdc++.h>
#include <set>
using namespace std;
#define ll long long
//#define fo(i,n) for(ll i=0;i<n;i++)
#define vvi vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define ff first
#define ss second

const int N= 1e7, MOD = 1e9+7;


long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    ll N,A,B;
    cin>>N>>A>>B;
    
    ll sum = 0;
    
    sum = N*(N+1) /2;

    ll x1 = N/A;
    ll x2 = N/B;

    ll sum1 = (x1*(2*A + (x1 -1)*A))/2;
    ll sum2 = (x2*(2*B + (x2 -1)*B))/2;

    ll C = lcm(A,B);
    ll x3 = N/C;
    
    ll sum3 = (x3*(2*C + (x3 -1)*C))/2;

    cout<<sum-sum1-sum2+sum3<<endl;    
    return 0;
}