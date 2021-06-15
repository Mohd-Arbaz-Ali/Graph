#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	int E;
	vector<vector<int>>adj;
public:
	Graph(int V,int E){
         this->V=V;
         this->E=E;
         for(int i=0;i<V;i++){
         	vector<int>list;
         	adj.push_back(list);
         }
	}
	void insert(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
    void print(){
    	for(int i=0;i<V;i++){
    		for(auto it:adj[i])
    			cout<<it<<" ";
    		cout<<endl;
    	}
    }
    void bfs(){
    	vector<int>vis(V,0);
    	if(!vis[0]){
            vis[0]=1;
            queue<int>q;
            q.push(0);
            while(!q.empty()){
            	int node=q.front();
            	q.pop();
            	cout<<node<<" ";
            	for(auto it:adj[node])
            		if(!vis[it]){
            			q.push(it);
            			vis[it]=1;
            		}
            }
    	}
    	cout<<endl;
    }
    void dfs_util(int i,vector<int>&vis){
        if(!vis[i]){
        	vis[i]=1;
        	cout<<i<<" ";
        	for(auto it:adj[i]){
        		if(!vis[it]){
        			dfs_util(it,vis);
        		}
        	}
        }
    }
    void dfs(){
    	vector<int>vis(V,0);
    	dfs_util(0,vis);
    	cout<<endl;
    }
    void shortestPaths(){
        vector<int>dis(V,INT_MAX);
        queue<int>q;
        q.push(0);
        dis[0]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: adj[node]){
                if(dis[node]+1<dis[it]){
                    dis[it]=dis[node]+1;
                    q.push(it);
                }
            }
        }
        for(auto it:dis)
            cout<<it<<" ";
        cout<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Graph g(9,10);
    g.insert(0,1);
    g.insert(0,3);
    g.insert(1,2);
    g.insert(3,4);
    g.insert(4,6);
    g.insert(2,6);
    g.insert(5,6);
    g.insert(6,7);
    g.insert(6,8);
    g.insert(7,8);
    g.shortestPaths();
    return 0;
}