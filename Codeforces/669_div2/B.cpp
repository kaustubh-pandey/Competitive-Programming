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
		vector<int> a(n,0);
		fo(i,n){
			cin>>a[i];
		}
		sort(a.begin(),a.end());
		vector<int> res;
		res.pb(a[n-1]);
		a[n-1]=-1;
		int maxi = n-2;
		int count=0;
		int gc = res[0];
		while(count<n-1){
			int ind=-1;
			int maxmgcd=1;
			for(int j=0;j<=maxi;j++){
				if(a[j]!=-1){
					if(__gcd(gc,a[j])>maxmgcd){
						maxmgcd = __gcd(gc,a[j]);
						ind=j;	
					}	
				}	
			}
			if(ind!=-1){
				//found
				gc = __gcd(gc,a[ind]);
				res.pb(a[ind]);
				count++;
				a[ind]=-1;	
			}
			else{
				while(maxi>=0 && a[maxi]==-1){maxi--;}
				gc = __gcd(gc,a[maxi]);
				res.pb(a[maxi]);
				count++;
				a[maxi]=-1;
				maxi--;
				while(maxi>=0 && a[maxi]==-1){maxi--;}
				if(maxi==-1){break;}	
			}	
		}
		printvec(res);			
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
