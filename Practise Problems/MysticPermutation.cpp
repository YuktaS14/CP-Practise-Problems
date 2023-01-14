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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>p(n);
        vector<int>q(n);

        stack<int>s;
        

        rep(i,0,n)
            cin>>p[i];

        if(n==1)
        {       
            cout<<-1<<endl;
            continue;
        }
   
        for(int i = n; i> 0; i--)
        {
            s.push(i);
        }

        rep(i,0,n-1)
        {
            int temp = s.top();
            if(temp!= p[i])
            {
                q[i] = temp;
                s.pop();
            }
            else
            {
                  
                    s.pop();
                    q[i] = s.top();
                    s.pop();
                    s.push(temp);
                
            }
            
        }
        //cout<<"t--"<<s.top()<<p[n-1]<<" ";
        int next = s.top();
        if(next == p[n-1])
        {
            //cout<<"hyyy";
            q[n-1] = q[n-2];
            
            q[n-2] = next;
            s.pop();
        }
        else
         {
             q[n-1] = s.top();
             s.pop(); 
         }

        rep(i,0,n)
            cout<<q[i]<<" ";
        cout<<endl;

        

    }

    return 0;
}