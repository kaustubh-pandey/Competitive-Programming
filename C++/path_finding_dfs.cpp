#include<bits/stdc++.h>
using namespace std;
// add edge from u to v
void addEdge(vector<int> g[],int u,int v){
	g[u].push_back(v);
}
//print path fro src to dest
void dfs(vector<int> g[],int src,int dest,bool visited[],int &flag){
	if(!visited[src]){
		visited[src]=true;
		for(auto i=g[src].begin();i!=g[src].end();i++){
			if(*i==dest){
				cout<<dest<<" ";
				flag=1;
				break;
			}
			if(!visited[*i]){
				dfs(g,*i,dest,visited,flag);
			}
		}
	}
	if(flag==1){
		cout<<src<<" ";
	}
}
void dfsW(vector<int> g[],int src,int dest,int n){
	bool visited[n];
	memset(visited,false,sizeof(visited));
	int flag=0;
	dfs(g,src,dest,visited,flag);
	cout<<endl;
}
int main(){
	int n=6;
	vector<int> g[n];
	addEdge(g,0,1);
	addEdge(g,1,4);
	addEdge(g,0,2);
	addEdge(g,2,3);
	addEdge(g,4,2);
	//1 to 3 path
	dfsW(g,1,3,6);
	return 0;
}