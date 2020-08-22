#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> g[],int src,vector<int> &anc,int visited[],map<int,vector<int> > &m){
	if(!visited[src]){
		visited[src]=1;
		anc.push_back(src);
		m[src]=anc;	
		for(auto y:g[src]){
			if(!visited[y]){
				dfs(g,y,anc,visited,m);
			}	
		}
		anc.pop_back();
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> values(n,0);
		for(int i=0;i<n;i++){
			cin>>values[i];	
		}
		vector<int> g[n+1];
		int src,dest;
		for(int i=0;i<n-1;i++){
			cin>>src>>dest;
			g[src].push_back(dest);
			g[dest].push_back(src);	
		}
		int visited[n+1];
		memset(visited,0,sizeof(visited[0])*(n+1));
		map<int,vector<int> >m;
		vector<int> anc;
		dfs(g,1,anc,visited,m);
		vector< pair<int,int> > v;	
		for(auto x:m){
			int val=-1;
			for(int k=x.second.size()-2;k>=0;k--){
				if(__gcd(values[x.first-1],values[x.second[k]-1])==1){
					val= x.second[k];
					break;	
				}	
			}
			v.push_back(make_pair(x.first,val));	
		}
		for(auto x:v){
			cout<<x.first<<" "<<x.second<<endl;	
		}
	}	
}
