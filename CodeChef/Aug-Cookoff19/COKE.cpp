#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k,l,r;
		cin>>n>>m>>k>>l>>r;
		int c[n];
		int p[n];
		for(int i=0;i<n;i++){
			cin>>p[i]>>c[i];
		}
		for(int i=0;i<n;i++){
			if(p[i]>k){
				p[i]=(p[i]-m<k)?k:p[i]-m;
			}
			else if(p[i]<k){
				p[i]=(p[i]+m>k)?k:p[i]+m;
			}
		}
		// for(int i=0;i<n;i++){
		// 	cout<<p[i]<<" ";
		// }
		// cout<<endl;
		int min_cost=INT_MAX;
		for(int i=0;i<n;i++){
			//cout<<c[i]<<" "<<p[i]<<endl;
			if(l<=p[i] && p[i]<=r){
				if(c[i]<min_cost){
					min_cost=c[i];
				}
			}
		}
		if(min_cost==INT_MAX){
			min_cost=-1;
		}
		cout<<min_cost<<endl;
	}
	return 0;
}