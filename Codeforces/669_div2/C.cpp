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
void query(int i,int j){
	cout<<"? "<<i+1<<" "<<j+1<<endl;	
}
void execute(vector<int> &indices,vector<int> &a,int &cnt){
	if((int)indices.size()<=1){return;}
	for(int i=0;i<(int)indices.size()-1;i+=2){
			query(indices[i],indices[i+1]);
			cnt--;
			int r1,r2;
			cin>>r1;
			if(cnt==0){return;}
			query(indices[i+1],indices[i]);
			cnt--;
			cin>>r2;
			if(max(r1,r2)==r1){
				a[indices[i]]=r1;
			}
			else{
				a[indices[i+1]]=r2;	
			}
			if(cnt==0){return;}	
	}
	indices.clear();
	fo(i,(int)a.size()){
		if(a[i]==0){indices.pb(i);}	
	}
	if((int)indices.size()<=1){return;}
	execute(indices,a,cnt);
} 
int main(){
	int n;
	cin>>n;
	int target = (n*(n+1))/2;
	vector<int> a(n,0);
	int sum=0;
	int cnt=2*n;
	vector<int> indices(n,0);
	fo(i,n){
		indices[i]=i;	
	}
	execute(indices,a,cnt);
	int emp=-1;
	fo(i,n){
		sum+=a[i];
		if(a[i]==0){emp=i;}	
	}
	if(emp!=-1){
		a[emp]=target-sum;	
	}
	cout<<"! ";
	printvec(a);
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
