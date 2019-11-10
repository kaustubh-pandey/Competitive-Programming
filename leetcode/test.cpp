#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> a;
	int d;
	for(int i=0;i<n;i++){
		cin>>d;
		a.pb(d);
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" \n"[i==n-1];
	}
	return 0;
}