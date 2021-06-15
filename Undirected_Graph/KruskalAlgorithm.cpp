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

bool comp(node a,node b){
	return a.wt<b.wt;
}

int find(int a,vector<int>&parent){
	if(parent[a]==a)
		return a;
	return parent[a]=find(parent[a],parent);
}

void Union(int u,int v,vector<int>&parent,vector<int>&rank){
	int uset=find(u,parent);
	int vset=find(v,parent);
	if(rank[uset]>rank[vset])
		parent[vset]=uset;
	else if(rank[vset]>rank[uset])
		parent[uset]=vset;
	else{
		parent[vset]=uset;
		rank[uset]++;
	}
}

int main(int argc, char const *argv[])
{
	int N,m;
	cin>>N>>m;
	vector<node>edge;
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		edge.push_back(node(u,v,wt));
	}
	sort(edge.begin(),edge.end(),comp);
	vector<int>parent(N+1);
	vector<int>rank(N+1,0);
	int cost=0;
	for(int i=1;i<=N;i++)
		parent[i]=i;
	vector<pair<int,int>>mst;
	for(auto it : edge){
		if(find(it.u,parent)!=find(it.v,parent)){
			cost+=it.wt;
			mst.push_back({it.u,it.v});
			Union(it.u,it.v,parent,rank);
		}
	}
	cout<<"Cost of MST = "<<cost<<endl;
	for(auto it : mst)
		cout<<it.first<<"--"<<it.second<<endl;

	return 0;
}