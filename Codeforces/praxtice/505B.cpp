#include<bits/stdc++.h>
#define ll long long
#define xll __int128
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

void dfs(vector< pair<int,int> > g[],int visited[],int u,int v,int color){
	if(!visited[u]){
		visited[u]=1;
		for(auto x:g[u]){
			if(x.S==color){
				dfs(g,visited,x.F,v,color);	
			}	
		}	
	}
} 
int main(){
	int n,m;
	cin>>n>>m;
	vector< pair<int,int> > g[n];
	int a,b,c;
	set<int> colors;
	fo(i,m){
		cin>>a>>b>>c;
		a--;b--;
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
		colors.insert(c);	
	}
	int q;
	int u,v;
	cin>>q;
	while(q--){
		cin>>u>>v;
		u--;v--;
		int visited[n];
		int cnt=0;
		for(auto color:colors){
			memset(visited,0,sizeof(visited[0])*n);
			dfs(g,visited,u,v,color);
			if(visited[v]){
				cnt++;	
			}	
		}
		cout<<cnt<<endl;	
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
