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
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
using namespace std;
const int MOD=1000000007;

void print() 
{ 
    cout <<endl;
}
template <typename T, typename... Types> 
void print(T var1, Types... var2) 
{ 
    cout << var1 << " " ; 
  
    print(var2...) ; 
}
//ceil of a/b
template <typename T>
T fceil(T a,T b){
    return (T)(a+b-1)/b;			
}
//const int N=2e5;
//int arr[N+1];
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int a[n];
	int b[n];
	unordered_map<int,int> index;
	fo(i,n){
		cin>>a[i];
		index[a[i]]=i;	
	}
	fo(i,n){
		cin>>b[i];
	}
	int cost=0;
	vector< pair<int,int> > swaps;
	fo(k,n){
		int minm = INT_MAX;
		int id1=-1,id2=-1;
		fo(i,n){
			//print(b[i],i,index[b[i]]);
			int val = abs(i-index[b[i]]);
			if(val<minm && val>0){
				minm = val;
				id1=i;
				id2=index[b[i]];	
			}	
		}
		//trace(id1);
		//trace(id2);
		if(id1!=id2){
			int d1 = a[id1];
			int d2= a[id2];
			swap(a[id1],a[id2]);
			swaps.pb(mp(id1+1,id2+1));
			cost+= minm;
			index[d1]=id2;
			index[d2]=id1;	
		}	
	}
	cout<<cost<<endl;
	cout<<swaps.size()<<endl;
	for(auto x:swaps){
		cout<<x.first<<" "<<x.second<<endl;	
	}
	return 0;
}
