#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a,n) memset(a,0,sizeof(a[0])*n)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl "\n"
#define Endl "\n"
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
using namespace std;
const int MOD=1000000007;
void print(){cout <<endl;}
template <typename T, typename... Types> 
void print(T var1, Types... var2){cout << var1 << " " ;print(var2...) ;}
//ceil of a/b
template <typename T>
T fceil(T a,T b){return (T)(a+b-1)/b;}
template <typename T>
void printvec(vector<T> v){ for(int i=0;i<(int)v.size();i++){ cout<<v[i]<<" ";} cout<<endl;}
template <typename T>
void printarr(T a[],int n){ for(int i=0;i<n;i++){ cout<<a[i]<<" ";} cout<<endl;}
//const int N=2e5;
//int arr[N+1];

void dfs(vector<int> g[],int src,int visited[],set< pair<int,int>  > &edges,int parent){
	if(!visited[src]){
		visited[src]=1;
		for(auto x:g[src]){
			if(!visited[x]){
				dfs(g,x,visited,edges,src);
			}
			else if(x!=parent){
				//print(src,x,parent);
				edges.insert(mp(min(src,x),max(src,x)));
				}	
		}	
	}	
}
void DFS(vector<int> g[],int n){
	int visited[n];
	memset(visited,0,sizeof(visited[0])*n);
	set< pair<int,int>  > edges;
	fo(i,n){
		if(!visited[i]){
			dfs(g,i,visited,edges,-1);	
		}	
	}
	cout<<edges.size()<<endl;
} 
int main(){
	int n,m;
	cin>>n>>m;
	int src,dest;
	vector<int> g[n];
	fo(i,m){
		cin>>src>>dest;
		src--;dest--;
		g[src].pb(dest);
		g[dest].pb(src);	
	}
	DFS(g,n);
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
