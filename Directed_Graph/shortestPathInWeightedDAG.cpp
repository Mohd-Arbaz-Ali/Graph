#include<bits/stdc++.h>
using namespace std;

void topoSort(int i,vector<int>&vis,stack<int>&s,vector<pair<int,int>>adj[]){
	vis[i]=1;
	for(auto it:adj[i]){
		if(!vis[it.first])
			topoSort(it.first,vis,s,adj);
	}
	s.push(i);
}

void shortestPath(int V,vector<pair<int,int>>adj[]){
	vector<int>vis(V,0);
	vector<int>dis(V,INT_MAX);
	stack<int>s;
	for(int i=0;i<V;i++){
		if(!vis[i])
			topoSort(i,vis,s,adj);
	}
	dis[0]=0;
	while(!s.empty()){
		int node=s.top();
		s.pop();
		if(dis[node]!=INT_MAX){
			for(auto it : adj[node]){
				if(dis[node]+it.second<dis[it.first])
					dis[it.first]=dis[node]+it.second;
			}
		}
	}
	for(auto itr : dis)
		cout<<itr<<" ";
	cout<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++){
    	int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    shortestPath(n,adj);

	return 0;
}