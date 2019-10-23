#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n,0);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int min_=a[n-1];
		int count=0;
		for(int i=n-2;i>=0;i--){
			if(a[i]>min_){
				count++;
			}
			if(a[i]<min_){
				min_=a[i];
			}
		}
		cout<<count<<endl;
	}
	return 0;
}