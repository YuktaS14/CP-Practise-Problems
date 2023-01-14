#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+2, MOD = 1e9+7;
int rootN;

struct Q{
    int q;
    int l,r;
};

Q query[N];
bool comp(Q a, Q b)
{
    if(a.l/rootN == b.l/rootN){
        return a.r>b.r;
    }
    return (a.l/rootN) < (b.l/rootN);
}
int main(){
    int n;
    cin>>n;    
    vector<int>arr(n);
    for(int i = 0; i<n; i++)
        cin>> arr[i];

    rootN = sqrtl(n);

    int queries;
    cin>>queries;

    for(int i = 0; i<queries; i++)
    {
        int l,r;
        cin>>l>>r;
        query[i].q = i;
        query[i].l = l;
        query[i].r = r;
    }

    sort(query, query+queries, comp);
    vector<int> ans(queries);
    int curr_l = 0, curr_r = -1, l,r;
    int curr_ans = 0;
    for(int i = 0; i<queries; i++)
    {
        l = query[i].l; r = query[i].r;
        l--;r--;
        while(curr_r < r)
        {
            curr_r ++;
            curr_ans += arr[curr_r];
        }
         while(curr_r > r)
        {
            curr_ans -= arr[curr_r];
            curr_r --;
        }
         while(curr_l < l)
        {
            curr_ans -= arr[curr_l];
            curr_l ++;
        }
         while(curr_l > l)
        {
            curr_l --;
            curr_ans += arr[curr_l];
        }
        ans[query[i].q] = curr_ans;
    }

    for(int i = 0; i<queries; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}