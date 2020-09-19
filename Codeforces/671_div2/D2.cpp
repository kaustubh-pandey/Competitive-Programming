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

int f(vector<int> a){
	int cnt=0;
	Fo(i,1,(int)a.size()-1){
		if(a[i]<a[i-1] && a[i]<a[i+1]){cnt++;}	
	}
	return cnt;	
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		fo(i,n){
			cin>>a[i];	
		}
		sort(a,a+n);
		//cout<<(n-1)/2<<endl;
		queue<int> low,high;
		fo(i,(n-1)/2){
			low.push(a[i]);	
		}
		Fo(i,(n-1)/2,n){
			high.push(a[i]);	
		}
		int sw=0;
		vector<int> res;
		if(n%2==0){
			res.pb(high.front());
			high.pop();
		}
		while(!low.empty() && !high.empty()){
			if(sw==0){
				res.pb(high.front());
				high.pop();
				sw=1;	
			}
			else{
				res.pb(low.front());
				low.pop();
				sw=0;
			}	
		}
		while(!high.empty()){
			res.pb(high.front());
			high.pop();	
		}
		cout<<f(res)<<endl;
		printvec(res);
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
