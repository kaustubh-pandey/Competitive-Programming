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
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
using namespace std;
const int MOD=1000000007;

void print() 
{ 
    cout <<endl;
}
template <typename T, typename... Types> 
void print(T var1, Types... var2) 
{ 
    cout << var1 << " " ; 
  
    print(var2...) ; 
}
//ceil of a/b
template <typename T>
T fceil(T a,T b){
    return (T)(a+b-1)/b;			
}
//const int N=2e5;
//int arr[N+1];
void dfs_(vector<int> g[],int k,vector<int> &visited){
	//cout<<k<<endl;
	if(!visited[k]){
		visited[k]=1;
		for(auto x:g[k]){
			dfs_(g,x,visited);
		}	
	}
}
void dfs(vector<int> g[],vector<int> del){
	vector<int> visited(26,0);
	for(int i=0;i<(int)del.size();i++){
		dfs_(g,del[i],visited);	
	}
	fo(i,26){
		if(visited[i]){
			cout<<(char)(i+65)<<" ";	
		}	
	}
	cout<<endl;	
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int k,j;
		cin>>k>>j;
		vector<int> g[26];
		char x,y;
		fo(i,k){
			cin>>x>>y;
			g[y-65].pb(x-65);
		}
		vector<int> del(j,0);
		fo(i,j){
			cin>>x;
			del[i]=x-65;	
		}
		dfs(g,del);			
	}
	return 0;
}

