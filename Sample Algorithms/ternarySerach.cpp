#include<bits/stdc++.h>
using namespace std;
int ternarySearch(int a[],int low,int high,int k){
	int m1,m2;
	m1=(low+high)/3;
	m2=2*m1;
	if(low==high){
		if(a[low]==k){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(low>high){
		return 0;
	}
	if(k==a[m1]){
		return 1;
	}
	else if(k==a[m2]){
		return 1;
	}
	else if(k<a[m1]){
		return ternarySearch(a,low,m1-1,k);
	}
	else if(k>a[m2]){
		return ternarySearch(a,m2+1,high,k);
	}
	else if(k>a[m1] && k<a[m2]){
		return ternarySearch(a,m1+1,m2-1,k);
	}
	else{
		return 0;
	}
}
int main(){
	int k,n,a[100];
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);

	}
	printf("%d\n",ternarySearch(a,0,n-1,k));
return 0;
}

