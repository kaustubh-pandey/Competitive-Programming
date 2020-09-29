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
const ll INF = (ll)1e16;
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

ll minl(ll a,ll b){
	if(a<b){return a;}
	return b;	
}
ll maxl(ll a,ll b){
	if(a>b){return a;}
	return b;	
}
ll absl(ll a){
	if(a>=0){return a;}
	return -a;	
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int a[n];
	fo(i,n){
		cin>>a[i];
	}
	sort(a,a+n);
	long double maxm = a[n-1];
	long double k = 1.0L/(n-1);
	
	long double root = powl(maxm,k);
	ll b1 = root;
	ll minm = INF;
	ll start = maxl(b1-1,1);
	for(ll j=start;j<=b1+1;j++){
		ll sum1=0;
		ll p1=1;
		fo(i,n){
			sum1+= absl(a[i]-p1);
			if(sum1>minm){break;}
			p1 = p1*j;
		}
		if(sum1>INF){break;}
		minm = minl(minm,sum1);
	}
	cout<< minm<<endl;
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
