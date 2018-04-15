#include <bits/stdc++.h>
using namespace std;
class Graph{
private:
	int V,E;
public:
	vector<int> *adj;
	Graph(int V,int E){
		this->V=V;
		this->E=E;
		adj=new vector<int>[V+1];
	}
	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void bfs(int src){
		int *visited=new int[V+1];
		int *weight=new int[V+1];
		for(int i=0;i<=V;i++){
			visited[i]=0;
			weight[i]=-1;
		}
		queue<int> q;
		q.push(src);
		visited[src]=1;
		weight[src]=0;
		vector<int>::iterator j;
		while(!q.empty()){
			src=q.front();
			q.pop();
			for(j=adj[src].begin();j!=adj[src].end();j++){
				if(visited[*j]==0){
					q.push(*j);
					visited[*j]=1;
					weight[*j]=6+weight[src];
				}
				
			}
		}
		for(int i=1;i<=V;i++){
			if(weight[i]!=0){
				cout<<weight[i]<<" ";
			}
		}
		cout<<endl;

	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int V,E,u,v,src;
		cin>>V>>E;
		Graph g(V,E);
		for(int i=0;i<E;i++){
			cin>>u>>v;
			g.addEdge(u,v);
		}
		cin>>src;
		g.bfs(src);
	}
return 0;
}