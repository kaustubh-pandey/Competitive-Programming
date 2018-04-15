#include <bits/stdc++.h>
using namespace std;
class Graph{
private:
	int V,E;
public:
	vector<pair<int,int> > *adj;
	Graph(int V,int E){
		this->V=V;
		this->E=E;
		adj=new vector<pair<int,int> >[V+1];
	}
	void addEdge(int u,int v,int w){
		adj[u].push_back(make_pair(w,v));
		adj[v].push_back(make_pair(w,u));
	}

	void dijkstra(int src){
		set<pair<int,int> >s;
		vector<int> distance(V+1,INT_MAX);
		s.insert(make_pair(0,src));
		distance[src]=0;

		while(!s.empty()){
			int u= (*(s.begin())).second;
			s.erase(s.begin());
			//cout<<u<<endl;
			vector<pair<int,int> >::iterator j;
			for(j=adj[u].begin();j!=adj[u].end();j++){
				int v=(*j).second;
				int w=(*j).first;
				//cout<<v<<endl;
				if(distance[v]>distance[u]+w){
					if (distance[v] != INT_MAX){
                    s.erase(s.find(make_pair(distance[v], v)));
                }
                distance[v] = distance[u] + w;
                s.insert(make_pair(distance[v], v));
				}
			}
		}

		for(int i=1;i<=V;i++){
			if(distance[i]!=0 && distance[i]!=INT_MAX){
				cout<<distance[i]<<" ";
			}
			else if(distance[i]==INT_MAX){
				cout<<"-1 ";
			}
		}
		cout<<endl;
	}
	
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int V,E,u,v,w,src;
		cin>>V>>E;
		Graph g(V,E);
		for(int i=0;i<E;i++){
			cin>>u>>v>>w;
			g.addEdge(u,v,w);
		}
		cin>>src;
		g.dijkstra(src);
	}
return 0;
}