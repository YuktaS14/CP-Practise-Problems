#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+2, MOD = 1e9+7;

vector<vector<int>> graph;
vector<bool> visited;
vector<int>color;


bool colorVertex(int v,int c)
{
    bool isBipartite = true;
    if(visited[v])
    {
        if(c!=color[v]){
            // isBipartite = false;
            return false;
        }
        return true;
    }
    visited[v] = true;
    color[v] = c;
    for(auto i:graph[v]){
        isBipartite &= colorVertex(i, c xor 1);
    }
    
    return isBipartite;
}

int main()
{
    int n,m;
    cin>>n>>m;
    graph = vector<vector<int>>(n);
    visited = vector<bool>(n,false);
    color = vector<int>(n,-1);

    for(int i = 0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bool isBipartite = true;
    for(int i = 0; i<n; i++)
    {
        if(!visited[i])
            isBipartite &= colorVertex(i,0);
        
        if(!isBipartite){
            cout<<"Not a bipartite graph. "<<endl;
            break;
        }
    }
    if(isBipartite)
        cout<<"Its a bipartite graph. "<<endl;
    return 0;
}