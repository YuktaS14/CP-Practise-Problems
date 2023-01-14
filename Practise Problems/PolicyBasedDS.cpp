#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5+2, MOD = 1e9+7;

int main()
{
    oset<int>s;
    int queries;
    cin>>queries;
    while(queries--)
    {
        int c; cin>>c;
        if(c==1){
            int v; cin>>v;
            s.insert(v);
        }
        else if(c==2){
            int v; cin>>v;
            cout<<*s.find_by_order(v)<<"\n";
        }
        else{
            int v; cin>>v;
            cout<<s.order_of_key(v)<<"\n";
        }

    }
    return 0;
}