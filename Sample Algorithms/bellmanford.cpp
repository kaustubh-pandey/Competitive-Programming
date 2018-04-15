#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
	int src;
	int dest;
	int w;
	Edge(int src,int dest,int w){
		this->src=src;
		this->dest=dest;
		this->w=w;
	}
};

class Graph{
private:
	int V,E;
	vector<Edge> g;
public:
	int *key;
	Graph(int V,int E){
		this->V=V;
		this->E=E;
		this->key=new int[V];
	}
	void addEdge(int src,int dest,int w){
		Edge e(src,dest,w);
		g.push_back(e);
	}

	void bellmanFord(int src){
		int V=this->V;
		int E=this->E;
		for(int i=0;i<V;i++){
			key[i]=INT_MAX;
		}
		key[src]=0;
		for(int i=1;i<=V-1;i++){
			//Relax
			for(int j=0;j<E;j++){
				int u=this->g[j].src;
				int v=this->g[j].dest;
				int w=this->g[j].w;
				if(key[u]!=INT_MAX && key[u]+w<key[v]){
					key[v]=key[u]+w;
				}
			}
		}
	}
	//Assuming no negative weight cycles
	//IF negative cycles
	/*for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }*/
	int bellFordDistance(int dest){
		return key[dest];
	}
};

int main(){
	int V,E;
	cin>>V>>E;
	Graph G(V,E);
	int src,dest,w;
	for(int i=0;i<E;i++){
		cin>>src>>dest>>w;
		G.addEdge(src,dest,w);
	}
	G.bellmanFord(0);//run bellmanford for source vertex
	//Print distance of every vertex w.r.t source
	for(int i=0;i<V;i++){
		cout<<G.bellFordDistance(i)<<endl;
	}
return 0;
}