#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a;
	long long int sum=0;
	int mx=INT_MIN;
	for(int i=0;i<n;i++){
		cin>>a;
		sum+=a;
		mx=max(mx,a);
	}
	
	if(sum%2==0 && mx<=(sum/2)){
		cout<<"YES"<<endl;
	}	
	else{
		cout<<"NO"<<endl;
	}
	
	return 0;
}