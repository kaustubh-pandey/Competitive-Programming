#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,s;
		cin>>n>>s;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];	
		}
		ll sum=0;
		int low=0;
		int high=0;
		while(low<=high && high<n){
			while(sum<s && high<n){
				sum+=a[high++];	
			}
			while(sum>s && low<=high){
				sum-=a[low++];	
			}
			if(sum==s){
				break;	
			}	
		}
		if(sum==s){
			cout<<low+1<<" "<<high<<endl;	
		}
		else{
			cout<<-1<<endl;	
		}
	}	
}
