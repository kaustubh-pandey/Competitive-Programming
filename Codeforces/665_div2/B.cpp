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

 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		int x1,y1,z1,x2,y2,z2;
		int sum=0;
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		if(z1>y2){
			sum+= 2*y2;
			int extra = z1-y2;
			if(extra+x1 < z2){
				sum-= (z2-extra-x1)*2;	
			}	
		}
		else{
			sum+= 2*z1;
			if(z2>x1){
				sum-=(z2-x1)*2;	
			} 	
		}
		cout<<sum<<endl;
	}
	return 0;
}
