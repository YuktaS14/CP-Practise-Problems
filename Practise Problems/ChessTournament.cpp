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


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int  n;
        cin>>n;
        string s;
        cin>>s;

        int allOnes = 1,type2 = 0;

        rep(i,0,n)
        {
            if(s[i] -'0' != 1 )
            {
                allOnes = 0;
                type2++;
            }           
        }

        vector <vector<char>> ans(n, vector<char> (n,'0'));
        //int ans[n][n];
        if(allOnes)
        {
            cout<<"YES"<<endl;
            rep(i,0,n)
            {
                rep(j,0,n)
                {
                    if(i==j)
                    {
                        ans[i][j] = 'X';
                    }
                    else
                        ans[i][j] = '=';
                }
            }
            
        }

        else if(type2 == 2 || n == 2 || type2 == 1)
        {
            cout<<"NO"<<endl;
            continue;          
        }

        else
        {
            cout<<"YES"<<endl;

            rep(i,0,n)
            {
                rep(j,0,n)
                {
                    if(i==j)
                    {
                        ans[i][j] = 'X';
                    }
                    else if(s[i] == '1' || s[j] == '1')
                    {
                        ans[i][j] = '=';
                    }                  
                }
            }
        
        
            rep(i,0,n)
            {
                int j = 0;
                int set = 0;;
                while(j<n)
                {
                    if(ans[i][j] == '0' && set == 0)
                    {
                        ans[i][j] = '+';
                        ans[j][i] = '-';
                        set = 1;
                    }
                    else if(ans[i][j] == '0')
                    {
                        ans[i][j] = '-';
                        ans[j][i] = '+';
                    }
                    j++;
                }
            }
        }

        rep(i,0,n)
        {
            rep(j,0,n)
            {
                cout<<ans[i][j];
            }
            cout<<"\n";
        }

    }
    return 0;
}