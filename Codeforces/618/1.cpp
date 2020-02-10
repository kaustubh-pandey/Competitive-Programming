#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f(int a[],int n){
	int pro = 1,sum=0;
		int count0=0,count1=0;
		for(int i=0;i<n;i++){
			int x=a[i];
			pro*=x;
			sum+=x;
			if(x==0){
				count0++;
			}
			if(x==-1){
				count1++;
			}
		}
		if(pro==0){
			if(sum+count0!=0){
				return count0;
			}
			return count0+1;
		}
		else if(sum==0){
			return 1;
		}
		return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<f(a,n)<<endl;
	}
	return 0;
}