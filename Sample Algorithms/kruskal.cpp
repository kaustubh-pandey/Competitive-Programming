#include <bits/stdc++.h>
using namespace std;

class Disjoint_set{

public:
	int V;
	int *parent,*rank;
	Disjoint_set(int n){
		V=n;
		parent=new int[n+1];
		rank=new int[n+1];
		for(int i=0;i<=n;i++){
			parent[i]=i;
			rank[i]=0;
		}
	}
	
	int find(int u){
		if(u!=parent[u]){
			parent[u]=this->find(parent[u]);
		}
		return parent[u];
	}

	void UNION(int x,int y){
		x=this->find(x);
		y=this->find(y);
		if(rank[x]>rank[y]){
			parent[y]=x;
		}
		else{
			parent[x]=y;
		}
		if(rank[x]==rank[y]){
			rank[y]++;
		}
	}

};

class Graph{
private:
	int V,E;
	vector<pair<int,pair<int,int> > > G;
public:
	Graph(int V,int E){
		this->V=V;
		this->E=E;
	}
	void addEdge(int u,int v,int w){
		G.push_back(make_pair(w,make_pair(u,v)));
	}
	int kruskal(){
	int result=0;
	sort(G.begin(),G.end());
	Disjoint_set set(V);
	for(int i=0;i<G.size();i++){
		int u=G[i].second.first;
		int v=G[i].second.second;
		int pu=set.find(u);
		int pv=set.find(v);
		if(pu!=pv){
			cout<<u<<"-"<<v<<endl;
			result+=G[i].first;
			set.UNION(pu,pv);
		}
	}
	return result;
	}
};

int main(){
	//cout<<"Enter no. of vertices and edges\n";
	int V,E;
	cin>>V>>E;
	Graph g(V,E);
	int u,v,w;
	for(int i=0;i<E;i++){
		cin>>u>>v>>w;
		g.addEdge(u,v,w);
	}
	cout<<g.kruskal()<<endl;
return 0;
}