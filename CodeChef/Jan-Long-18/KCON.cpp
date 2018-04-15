#include <bits/stdc++.h>
using namespace std;
long int find1(long int a[],int n){
	//Fix the left
	//End of repetition
	long int m=a[0];
	long int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(sum>m){
			m=sum;
		}
	}
	return m;
}
long int find2(long int a[],int n){
	//Fix right, start of repetition
	long int m=a[n-1];
	long int sum=0;
	for(int i=n-1;i>=0;i--){
		sum+=a[i];
		if(sum>m){
			m=sum;
		}
	}
	return m;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		long int a[300000];
		for(int i=0;i<n;i++){
			scanf("%ld",&a[i]);
		}
		long int net_sum=0;
		for(int i=0;i<n;i++){
			net_sum+=a[i];
		}
		long int result=0;
		if(net_sum>0 && k>2){
			result+=net_sum*(k-2);
			result+=(find1(a,n)>0)?find1(a,n):0;
			result+=(find2(a,n)>0)?find2(a,n):0;
		}
		else{
			int s=0;
			if(k>1){s=1;}

			long int curr=INT_MIN,m=0;
			for(int i=0;i<n;i++){
				m+=a[i];
				if(curr<m){curr=m;}
				if(m<0){m=0;}
				if(s==1 && i==n-1){i=-1;s=0;}
			}
			result=curr;
		}
		printf("%ld\n",result);
		
	}
	return 0;
}