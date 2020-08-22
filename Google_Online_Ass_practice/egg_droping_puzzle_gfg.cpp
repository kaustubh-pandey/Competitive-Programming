#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int count=0;
		while(k){
			k=k>>1;
			count++;	
		}
		cout<<count<<endl;	
	}
return 0;
}
