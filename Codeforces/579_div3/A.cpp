#include<bits/stdc++.h>
#define ll long long 
using namespace std;
bool check(int a[],int n,int index,int flag){
	int val=2;
	if(flag==0){
		index++;
		if(index==n){
			index=0;
		}
		while(index<n && a[index]==val && a[index]!=1){
			val++;
			index++;
			if(index==n){
				index=0;
			}
		}
	}
	if(flag==1){
		index--;
		if(index==-1){
			index=n-1;
		}
		while(index>=0 && a[index]==val && a[index]!=1){
			//cout<<a[index]<<endl;
			val++;
			index--;
			if(index==-1){
				index=n-1;
			}
		}
	}
	if(a[index]!=1){
			return false;
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int index=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==1){
				index=i;
			}

		}
		//cout<<check(a,n,index,0)<<endl;
		//cout<<check(a,n,index,1)<<endl;
		if(check(a,n,index,0) || check(a,n,index,1)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

	}
	return 0;
}