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
	//cin>>t;
	while(t--){
		int n;
		cin>>n;
		string a,b;
		cin>>a;
		cin>>b;
		int sum=0;
		fo(i,n-1){
			if((a[i]-'0')+(a[i+1]-'0'==1) && (b[i]-'0')+(b[i+1]-'0')==1){
				if(a[i]!=b[i] && a[i+1]!=b[i+1]){
					//cout<<"ash"<<endl;
					swap(a[i],a[i+1]);
					sum++;	
				}	
			}	
		}
		//cout<<a<<endl;
		fo(i,n){
			if(a[i]!=b[i]){sum++;}	
		}
		cout<<sum<<endl;			
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
