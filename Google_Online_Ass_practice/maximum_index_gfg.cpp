#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<ll> a(n,0);
		for(int i=0;i<n;i++){
			cin>>a[i];	
		}
		for(int k=0;k<n;k++){
			int l = 0;
			int h= n-k-1;
			while(h<n && a[l]>a[h]){
				h++;
				l++;	
			}		
			if(h<n && a[l]<=a[h]){
				cout<<h-l<<endl;
				break;	
			}
		}	
	}	
}
