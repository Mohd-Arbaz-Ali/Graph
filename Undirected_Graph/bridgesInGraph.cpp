#include<bits/stdc++.h>
using namespace std;

void bridgesUsingDFS(int node,int parent,int &timer,vector<int>&low,
	                vector<int>&tin,vector<int>&vis,vector<int>adj[]){
    vis[node]=1;
    tin[node]=low[node]=timer++;
    for(auto it : adj[node]){
        if(it==parent)
        	continue;
        if(!vis[it]){
        	bridgesUsingDFS(it,node,timer,low,tin,vis,adj);
        	low[node]=min(low[node],low[it]);
        	if(low[it]>tin[node])
        		cout<<node<<"  "<<it<<endl;
        }
        else
        	low[node]=min(low[node],tin[it]);
    }
}

int main(int argc, char const *argv[])
{
	int N,m;
	cin>>N>>m;
	vector<int>adj[N];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
	}
	vector<int>low(N);
	vector<int>tin(N);
	vector<int>vis(N,0);
	int timer=0;
	for(int i=0;i<N;i++){
		if(!vis[i])
			bridgesUsingDFS(i,-1,timer,low,tin,vis,adj);
	}
	return 0;
}