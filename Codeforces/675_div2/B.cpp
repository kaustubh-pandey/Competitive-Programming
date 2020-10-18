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
ll avg(int a,int b,int c,int d){
	ll sum =  a;
	sum+=b;
	sum+=c;
	sum+=d;
	return sum/4;
}
ll avg2(int a,int b){
	ll sum=a;
	sum+=b;
	return sum/2;
}
ll absl(ll a){
	if(a<0){return -a;}
	return a;
}
ll min(ll a,ll b){
	if(a<b){return a;}
	return b;
} 
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int mat[n][m];
		fo(i,n){
			fo(j,m){
				cin>>mat[i][j];
			}
		}
		ll count=0;
		fo(i,n/2){
			fo(j,m/2){
				int li,lj,di,dj,ci,cj;
				li = i;
				lj = m-j-1;
				di = n-i-1;
				dj = j;
				ci = n-i-1;
				cj = m-j-1;
				// print(i,j,mat[i][j]);
				// print(li,lj,mat[li][lj]);
				// print(mat[li][lj],mat[di][dj],mat[ci][cj],mat[i][j]);
				ll ag = avg(mat[li][lj],mat[di][dj],mat[ci][cj],mat[i][j]);
				vector<int> vals = {mat[li][lj],mat[di][dj],mat[ci][cj],mat[i][j]};
				ll sum1=0,sum2=0,sum3=0;
				sum1+= absl(mat[li][lj]-ag);
				sum1+= absl(mat[di][dj]-ag);
				sum1+= absl(mat[ci][cj]-ag);
				sum1+= absl(mat[i][j]-ag);
				sum2+= absl(mat[li][lj]-ag-1);
				sum2+= absl(mat[di][dj]-ag-1);
				sum2+= absl(mat[ci][cj]-ag-1);
				sum2+= absl(mat[i][j]-ag-1);
				sum3+= absl(mat[li][lj]-ag+1);
				sum3+= absl(mat[di][dj]-ag+1);
				sum3+= absl(mat[ci][cj]-ag+1);
				sum3+= absl(mat[i][j]-ag+1);
				ll minm=INT_MAX;
				for(auto x:vals){
					ll op=0;
					for(auto y:vals){
						op+= abs(x-y);	
					}
					minm = min(minm,op);
				}
				count+= min(min(min(sum1,sum2),sum3),minm);
			}
		}
		if(n%2){
			fo(j,m/2){
				if(mat[n/2][j]!=mat[n/2][m-j-1]){
					ll val = avg2(mat[n/2][j],mat[n/2][m-j-1]);
					ll sum1=0,sum2=0;
					sum1+= absl(mat[n/2][j]-val);
					sum2+= absl(mat[n/2][j]-val-1);
					sum1+= absl(mat[n/2][m-j-1]-val);
					sum2+= absl(mat[n/2][m-j-1]-val-1);
					count+= min(min(sum1,sum2),abs(mat[n/2][j]-mat[n/2][m-j-1]));
				}
			}
		}
		if(m%2){
			fo(i,n/2){
				if(mat[i][m/2]!=mat[n-i-1][m/2]){
					ll val = avg2(mat[i][m/2],mat[n-i-1][m/2]);
					ll sum1=0,sum2=0;
					sum1+= absl(mat[i][m/2]-val);
					sum2+= absl(mat[i][m/2]-val-1);
					sum1+= absl(mat[n-i-1][m/2]-val);
					sum2+= absl(mat[n-i-1][m/2]-val-1);
					count+= min(min(sum1,sum2),abs(mat[i][m/2]-mat[n-i-1][m/2]));
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
