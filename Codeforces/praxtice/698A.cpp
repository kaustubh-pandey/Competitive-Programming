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

int con(int a[],int n ,int val){
	int cnt=0;
	fo(i,n-1){
		if(a[i]==a[i+1] && a[i]==val){
			cnt++;	
		}	
	}
	return cnt;	
}
int three(int a[],int n){
	vector< pair<int,int>  > v;
	int i=1;
	while(i<n){
		if(a[i]==3){
			int low=i-1;
			while(i<n && a[i]==3){
				i++;	
			}
			if(i!=n){
				v.pb(mp(low,i));	
			}
			i--;
		}
		i++;	
	}
	int cnt=0;
	for(auto x:v){
		if((x.S-x.F)%2 && a[x.S]==a[x.F] && a[x.S]!=0){
			cnt++;	
		}
		else if((x.S-x.F)%2==0 && a[x.S]!=a[x.F] && a[x.S]!=0 && a[x.F]!=0){
			cnt++;	
		}	
	}
	return cnt;	
} 
int main(){
	int n;
	cin>>n;
	int a[n];
	int sum=0;
	fo(i,n){
		cin>>a[i];	
		if(a[i]==0){sum++;}
	}
	print(sum);
	sum+= con(a,n,1);
	print(sum);
	sum+= con(a,n,2);
	print(sum);
	sum+= three(a,n);
	cout<<sum<<endl;
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
