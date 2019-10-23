#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n,x,y;
	cin>>n>>x>>y;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sol=INT_MAX;
	for(int i=0;i<n;i++){
		int curr = a[i];
		int j=i,k=i;
		int flag = 1;
		while(j>=0 && j>=i-x){
			if(a[j]<curr){
				flag=0;
			}
			j--;
		}
		while(k<=i+y && k<n){
			if(a[k]<curr){
				flag=0;
			}
			k++;
		}

		if(flag){
			//cout<<i+1<<endl;
			if(i+1<sol){
				sol=i+1;
			}
		}
	}
	cout<<sol<<endl;
	return 0;
}