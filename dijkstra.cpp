/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


vector<int>dijkstra(vector<pair<int,int>>adj[],int source,int nodes){
    
    vector<int>ans(nodes+1,INT_MAX);
    ans[source]=0;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push(make_pair(0,source));
    while(!pq.empty()){
        int dist=pq.top().first;
        int prev=pq.top().second;
        
        pq.pop();
        for(auto it:adj[prev]){
            int next=it.first;
            int nextdist=it.second;
            if(ans[next]>ans[prev]+nextdist){
                ans[next]=ans[prev]+nextdist;
                pq.push(make_pair(ans[next],next));
            }
        }
    }
    return ans;
}

int main()
{
    int n=5,m=6,source=1;
	vector<pair<int,int> > g[n+1]; 	// assuming 1 based indexing of graph
	// Constructing the graph
	g[1].push_back({2,2});
	g[1].push_back({4,1});
	g[2].push_back({1,2});
	g[2].push_back({5,5});
	g[2].push_back({3,4});
	g[3].push_back({2,4});
	g[3].push_back({4,3});
	g[3].push_back({5,1});
	g[4].push_back({1,1});
	g[4].push_back({3,3});
	g[5].push_back({2,5});
	g[5].push_back({3,1});	
	
	vector<int>ans=dijkstra(g,source,n);
	
	for(int i=1;i<ans.size();i++){
	    cout<<ans[i]<<" ";
	}
	
	
    return 0;
}
