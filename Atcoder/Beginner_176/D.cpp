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
//const int N=2e5;
//int arr[N+1];

bool legal(int x,int y,int h,int w,char mat[][1000]){
	if(x>=h || x<0 || y>=w || y<0 || mat[x][y]=='#'){
		return false;	
	}
	return true;	
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h,w;
	cin>>h>>w;
	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	sx--;sy--;ex--;ey--;
	char mat[1000][1000];
	fo(i,h){
		fo(j,w){
			cin>>mat[i][j];	
		}	
	}
	int dist[h][w];
	fo(i,h){
		fo(j,w){
			dist[i][j]=INT_MAX-1;	
		}	
	}
	dist[sx][sy]=0;
	deque< pair<int,int> > dq;
	dq.push_front(mp(sx,sy));
	int dx[4] = {-1,1,0,0};
	int dy[4] = {0,0,-1,1};
	while(!dq.empty()){
		int currx = dq.front().F;
		int curry = dq.front().S;
		dq.pop_front();
		for(int d=0;d<4;d++){
			int nx = currx+dx[d];
			int ny = curry+dy[d];
			if(!legal(nx,ny,h,w,mat)){continue;}
			if(dist[nx][ny]>dist[currx][curry]){
				dist[nx][ny] = dist[currx][curry];
				dq.push_front(mp(nx,ny));	
			}	
		}
		for(int x=currx-2;x<=currx+2;x++){
			for(int y=curry-2;y<=curry+2;y++){
				if(!legal(x,y,h,w,mat)){continue;}
				if(dist[x][y]>dist[currx][curry]+1){
				dist[x][y] = dist[currx][curry]+1;
				dq.push_back(mp(x,y));	
				}		
			}	
		}	
	}
	cout<<((dist[ex][ey]==INT_MAX-1)?-1:dist[ex][ey])<<endl;
	return 0;
}
