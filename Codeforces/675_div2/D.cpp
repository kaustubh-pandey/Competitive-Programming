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

bool legal(int x,int y,int n){
	if(x>=0 && y>=0 && x<n && y<n){
		return true;
	}
	return false;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int sx,sy,fx,fy;
		cin>>sx>>sy>>fx>>fy;
		sx--;sy--;fx--;fy--;
		//int mat[n][n];
		int dist[n][n];
		fo(i,n){
			fo(j,n){
				//mat[i][j]=0;
				dist[i][j]=INT_MAX-1;
			}
		}
		int x,y;
		map<int,vector<int> > mapx;
		map<int,vector<int> > mapy;
		fo(i,m){
			cin>>x>>y;
			x--;y--;
			//mat[x][y]=1;
			mapx[x].pb(y);
			mapy[y].pb(x);
		}
		dist[sx][sy]=0;
		deque< pair<int,int> > dq;
		dq.push_back(mp(sx,sy));
		int dx[4] = {-1,1,0,0};
		int dy[4] = {0,0,-1,1};
		while(!dq.empty()){
			int currx = dq.front().F;
			int curry = dq.front().S;
			dq.pop_front();
			for(int d=0;d<4;d++){
				int nx = currx + dx[d];
				int ny = curry + dy[d];
				if(!legal(nx,ny,n)){continue;}
				if(dist[nx][ny]>dist[currx][curry]+1){
					dist[nx][ny] = dist[currx][curry]+1;
					dq.push_back(mp(nx,ny));
				}
			}
			for(int magy:mapx[currx]){
				if(dist[currx][magy]>dist[currx][curry]){
					dist[currx][magy] = dist[currx][curry];
					dq.push_front(mp(currx,magy));
				}
			}
			for(int magx:mapy[curry]){
				if(dist[magx][curry]>dist[currx][curry]){
					dist[magx][curry] = dist[currx][curry];
					dq.push_front(mp(magx,curry));
				}
			}
		}
		cout<<((dist[fx][fy]==INT_MAX-1)?-1:dist[fx][fy])<<endl; 
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
