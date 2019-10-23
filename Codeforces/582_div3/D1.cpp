#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f(int x){
	if(x==1){
		return 1;
	}
	return (int)(ceil(log(x)/log(2)*1.0))+(1-(x%2));
}
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];

	int min_ = INT_MAX;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<min_){
			min_=a[i];
		}
	}
	sort(a,a+n);
	//0 case
	int zero=0;
	int other=0;
	int index=1;
	while(a[index]==min_){
		index++;
	}
	for(int i=index;i<k;i++){
		//cout<<f(a[i])<<endl;
		zero+=f(a[i]);
		other+=f(a[i])-f(min_);
	}
	
	cout<<min(zero,other)<<endl;
	return 0;
}