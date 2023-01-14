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



///not complete sol....needs some modification

 vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        
        map<long long, long long>m;
        for (int i = 0; i<nums.size(); i++)
        {
            m[nums[i]] = i;    
        }
        
        vector<int> ans(2);
        //int i = 0, j = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            for(int j =i+1; j< nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                      ans[0] = m[nums[i]];
                    ans[1] = m[nums[j]];
                    return ans;
                    
                }
                else if(nums[i] + nums[j] < target)
                    continue;
                else
                    break;
            }
            
        
        }
     return ans;
    }
int main()
{
    int n;
    cin>>n;
    int target;
    cin>>target;
    
    vector<int> nums;

    rep(i,0,n)
        cin>>nums[i];
    
    
    vector<int> val(2);
    val = twoSum(nums,target);

    cout<<val[0]<<" "<<val[1];

    return 0;
}