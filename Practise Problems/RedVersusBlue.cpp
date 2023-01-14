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
        int n,r,b;
        cin>>n>>r>>b;

        string s(n,'R');
        int g = b+1;
        
        int num = r%g;
        g = r/g;

        

        // int flag = 0;
        // if(r%g <====++]]=(g/2))
        //     g = floor((double)r/(double)g);
        // else
        //     g = ceil((double)r/(double)g);
        // //cout<<g<<"ddd"<<endl;        
        // int i = g;

        //cout<<"g---num"<<g<<" "<<num<<endl;
        
        int i = g;
        while(b--)
        {
            
            if(num != 0)
            {     
                i=i+1;          
                s[i] = 'B';
                num--;
            }
            else
                s[i] = 'B';
            i= i+g+1;              
         
        }
        cout<<s<<endl;
    }
    return 0;
}



// 10 9 1
// 10 8 2
// 11 9 2

// RRRRRBRRRR
// RRRBRRRBRR
// RRRBRRRBRRR
