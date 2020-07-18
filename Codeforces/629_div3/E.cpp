#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
#define mp make_pair
#define F first
#define S second
using namespace std;
void dfs(vector<int> g[],int n,bool visited[],int root){
	if(!visited[root]){
		visited[root]=true;
		for(int i=0;i<(int)g[root].size();i++){
			if(!visited[g[root][i]]){
				dfs(g,n,visited,g[root][i]);	
			}	
		}	
	}	
}
bool solve(vector<int> g[],int n,vector<int> v){
	bool visited[n];
		
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> g[n];
	int a,b;
	fo(i,n-1){
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	fo(i,m){
		int siz;
		cin>>siz;
		vector<int> v(siz);
		int tmp;
		for(int j=0;j<siz;j++){
			cin>>tmp;
			v[j]=tmp-1;	
		}
		bool flag = solve(g,n,v);
		if(flag){
			cout<<"YES"<<endl;	
		}
		else{
			cout<<"NO"<<endl;	
		}	
	}
	return 0;
}
