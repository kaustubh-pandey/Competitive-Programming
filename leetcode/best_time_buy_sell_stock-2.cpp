#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max_profit=0;
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1]){
			max_profit+=a[i]-a[i-1];
		}
	}
	cout<<max_profit<<endl;
	return 0;
}