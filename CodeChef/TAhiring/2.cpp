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

int MAX(vector<int> a){
	int maxm =INT_MIN;
	int n=a.size();
	fo(i,n){
		maxm = max(maxm,a[i]);	
	}
	return maxm;	
}
int solve(vector<int> a){	
	//int n=a.size();
	int x=0;
	while(1){
		int y=MAX(a);
		if(y==0){
			return x;	
		}
		x=max(x,x^y);
		vector<int> tmp=a;
		a.clear();
		fo(i,(int)tmp.size()){
			a.pb(min(tmp[i],tmp[i]^y));	
		}	
	}
	return x;
} 
int main(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	fo(i,n){
		cin>>a[i];	
	}
	cout<<solve(a)<<endl;
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/

