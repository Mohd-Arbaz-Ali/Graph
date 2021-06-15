#include<bits/stdc++.h>
using namespace std;

void articulation_point(int node,int parent,int &timer,vector<int> &vis,vector<int> &tin,
	vector<int>&low,vector<int>&isArticulation,vector<int>adj[]){
	vis[node]=1;
	low[node]=tin[node]=timer++;
	int child=0;
	for(auto it : adj[node]){
		if(parent==it)  continue;
		if(!vis[it]){
			articulation_point(it,node,timer,vis,tin,low,isArticulation,adj);
			low[node]=min(low[node],low[it]);
			if(low[it]>=tin[node] && parent!=-1){
				isArticulation[node]=1;
			}
			child++;
		}
		else
			low[node]=min(low[node],low[it]);
	}
	if(parent==-1 && child>1)
		isArticulation[node]=1;
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	vector<int>adj[n];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	std::vector<int> vis(n,0);
	vector<int>tin(n);
	vector<int>low(n);
	vector<int>isArticulation(n,0);
	int timer=0;
	for(int i=0;i<n;i++){
		if(!vis[i])
			articulation_point(i,-1,timer,vis,tin,low,isArticulation,adj);
	}
	for(int i=0;i<n;i++){
		if(isArticulation[i])  cout<<i<<endl;
	}
	return 0;
}