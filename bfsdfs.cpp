/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


///-----------------------------bfs traversal of graph--------------------------------------------------
    
vector<int>bfsofgraph(int nodes,vector<int>adj[]){
    vector<int>bfs;
    vector<int>vis(nodes+1,0);
    for(int i=1;i<=nodes;i++){
        if(vis[i]==0){
            std::queue<int>q ;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it:adj[node]){
                    if(vis[it]!=1){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            
        }
    }
    return bfs;
}

///-----------------------------Dfs traversal of graph--------------------------------------------------

void dfs(vector<int>&ans,vector<int>&vis,vector<int>adj[],int node){
    ans.push_back(node);
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]!=1){
            dfs(ans,vis,adj,it);
        }
    }
    
}

vector<int>dfsofgraph(int nodes,vector<int>adj[]){
    vector<int>ans;
    vector<int>vis(nodes+1,0);
    for(int i=1;i<=nodes;i++){
        if(vis[i]==0){
            dfs(ans,vis,adj,i);
        }
    }
    return ans;
    
    
}


int main()
{
    int nodes,edges;
    // nodes=7;
    // edges=8;
    cin>>nodes>>edges;
    vector<int>adj[nodes+1];
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // ----------------------printing bfs--------------------
    vector<int>bfs;
    bfs=bfsofgraph(nodes,adj);
    for(auto i:bfs){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;
    
    //--------------printing dfs------------------------------
    vector<int>dfs;
    dfs=dfsofgraph(nodes,adj);
    for(auto i:dfs){
        cout<<i<<" ";
    }
    

    return 0; 
}



