#include <bits/stdc++.h>
#include <set>
using namespace std;
#define ll long long
//#define fo(i,n) for(ll i=0;i<n;i++)
#define vvi vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define ff first
#define ss second

const int N= 1e7, MOD = 1e9+7;

int main()
{
    ll n, q, ans = 0;
    cin >> n >> q;
    vector<ll>a(n+1);
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans+=a[i];
    }
 
    ll t, i, x;
    map< ll , ll > m;
 
    ll current = -1;
    while(q--){
        cin >> t;
        if(t == 2){
            cin >> x;
            ans = n*x;
            cout<<ans;
            m.clear();
            current = x;
        }
        else{
            cin >> i >> x;
            if(current == -1){
                ans-=a[i]; ans+=x; a[i] = x;
                cout<<ans;
            }
            else{
                if(m[i] == 0) {
                    ans-=current;
                    ans+=x;
                    cout<<ans;
                    m[i] = x;
                }
                else{
                    ans-=m[i];
                    ans+=x;
                    m[i] = x;
                    cout<<ans;
                }
            }
        }
 
        cout<<endl;
    }
    return 0;
}