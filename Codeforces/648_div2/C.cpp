#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
#define read_arr(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define mp make_pair
#define F first
#define S second
using namespace std;
const int MOD=1000000007;
const int N=2e5;
int a[N+1];

int main(){
	int n;
	cin>>n;
	int pos[N+1];
	fo(i,n){
		cin>>a[i];
		pos[a[i]] = i;		
	}
	int tmp;
	int arr[N+1];
	memset(arr,0,sizeof(arr[0])*(N+1));
	fo(i,n){
		cin>>tmp;
		int val = pos[tmp]-i;
		if(val<0){
			val+=n;	
		}
		arr[val]++;	
	}
	int maxm=0;
	fo(i,n){
		maxm = max(maxm,arr[i]);	
	}
	cout<<maxm<<endl;
	return 0;
}
/*
 ios::sync_with_stdio(false);
 cin.tie(0);
*/
