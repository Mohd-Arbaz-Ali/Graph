#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&vis,stack<int>&topo,vector<int> adj[]){
	vis[node]=1;
	for(auto it : adj[node])
		if(!vis[it])
			dfs(it,vis,topo,adj);
			
	topo.push(node);
}

void revDfs(int node,vector<int>&vis,vector<int>transpose[]){
	cout<<node<<" ";
	vis[node]=1;
	for(auto it : transpose[node]){
        if(!vis[it])
        	revDfs(it,vis,transpose);
	}
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	vector<int> adj[n];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	vector<int>vis(n,0);
	stack<int>topo;
	for(int i=0;i<n;i++)
		if(!vis[i])
			dfs(i,vis,topo,adj);
			
	vector<int>transpose[n];
	for(int i=0;i<n;i++){
		vis[i]=0;
		for(auto it : adj[i])
			transpose[it].push_back(i);
	}
	while(!topo.empty()){
		int node=topo.top();
		topo.pop();
			if(!vis[node]){
				cout<<"SCC : ";
				revDfs(node,vis,transpose);
				cout<<endl;
			}
	}
	return 0;
}