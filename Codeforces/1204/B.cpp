#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n,l,r;
	cin>>n>>l>>r;
	ll min_sum=0;
	for(int i=0;i<l;i++){
		min_sum += (ll)(1<<i);
	}
	min_sum+=(n-l);
	ll max_sum=0;
	for(int i=0;i<r;i++){
		max_sum += (ll)(1<<i);
	}
	max_sum+=(n-r)*((ll)1<<(r-1));
	cout<<min_sum<<" "<<max_sum<<endl;
	return 0;	
}