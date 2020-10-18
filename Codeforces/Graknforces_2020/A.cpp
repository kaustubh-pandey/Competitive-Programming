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

 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int b[n];
		int c[n];
		fo(i,n){cin>>a[i];}
		fo(i,n){cin>>b[i];}
		fo(i,n){cin>>c[i];}
		vector<int> res;
		int first = a[0];
		int last;
		if(a[n-1]!=first){
			last = a[n-1];	
		}
		else if(b[n-1]!=first){
			last = b[n-1];
		}
		res.pb(first);
		Fo(i,1,n-2){
			if(a[i]!=first){
				res.pb(a[i]);
				first = a[i];	
			}
			else if(b[i]!=first){
				res.pb(b[i]);
				first=b[i];	
			}	
		}
		if(first!=a[n-2] && last!=a[n-2]){
			res.pb(a[n-2]);	
		}
		else if(first!=b[n-2] && last!=b[n-2]){
			res.pb(b[n-2]);	
		}
		else{
			res.pb(c[n-2]);	
		}
		res.pb(last);
		printvec(res);			
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
