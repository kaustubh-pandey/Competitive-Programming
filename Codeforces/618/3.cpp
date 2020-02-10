#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(i=0;i<n;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define Fo(i,q,n) for(i=q;i<n;i++)
#define rFo(i,q,n) for(i=n-1;i>=q;i--)
#define fO(i,n,k) for(i=0;i<n;i+=k)
#define FO(i,q,n,k) for(i=q;i<n;i+=k)
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	int i,j;
	fo(i,n){
		cin>>a[i];
	}
	int bits[32];
	int v[32];
	memset(v,0,sizeof(v));
	memset(bits,0,sizeof(bits));
	fo(i,n){
		fo(j,32){
			if(a[i]&(1<<j)){
				bits[j]++;
				v[j]=i+1;
			}
		}
	}
	// fo(i,32){
	// 	cout<<bits[i]<<" ";
	// }
	// cout<<endl;
	int index=-1;
	rfo(i,32){
		if(bits[i]==1 && v[i]!=0){
			cout<<a[v[i]-1]<<" ";
			index=v[i]-1;
			break;
		}
	}
	fo(i,n){
		if(i!=index){
			cout<<a[i]<<" ";
		}
	}
	cout<<endl;
	return 0;
}