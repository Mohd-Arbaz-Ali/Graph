#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>adj[n+1];
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	vector<int>dis(n+1,INT_MAX);
    q.push({0,1});
    dis[q.top().second]=0;
    while(!q.empty()){
    	int distance=q.top().first;
    	int prev=q.top().second;
    	q.pop();
    	for(auto it : adj[prev]){
    		if(distance+it.second<dis[it.first]){
    			dis[it.first]=distance+it.second;
    			q.push({dis[it.first],it.first});
    		}
    	}
    }
    for(int i=1;i<=n;i++)
    	cout<<dis[i]<<" ";
    cout<<endl;
	return 0;
}