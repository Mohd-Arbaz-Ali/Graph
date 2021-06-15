#include<bits/stdc++.h>
using namespace std;

struct node{
	int u,v,wt;

	node(int first,int second,int weight){
        u=first;
        v=second;
        wt=weight;
	}
};

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	vector<node> edges;
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		edges.push_back(node(u,v,wt));
	}
	int src;
	cin>>src;
	vector<int>dis(n,1000000);
	dis[src]=0;
	for(int i=0;i<n-1;i++){
		for(auto it : edges){
			if(dis[it.u]+it.wt<dis[it.v])
				dis[it.v]=dis[it.u]+it.wt;
		}
	}
	int check=0;
	for(auto it : edges){
		if(dis[it.u]+it.wt<dis[it.v]){
			check=1;
			break;
		}
	}
	if(!check)
		for(int i=0;i<n;i++)
			cout<<i<<" "<<dis[i]<<endl;
	return 0;
}