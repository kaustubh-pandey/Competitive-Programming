#include<bits/stdc++.h>
#define ll long long
using namespace std;
void print(ll a[],int n){
	for(int i=0;i<n;i++){
			printf("%lld ",a[i]);
		}
}
int main(){
	ll t;
	cin>>t;
	ll a[50001];
	a[0]=6;a[1]=10;a[2]=15;
	for(int i=3;i<50000;i++){
		if(i%3==0){
			a[i]=a[i-1]+3;
		}
		else if(i%3==1){
			a[i]=a[i-1]+2;
		}
		else{
			a[i]=a[i-1]+25;
		}
	}
	while(t--){
		int n;
		cin>>n;
		if(n%3==1){
			print(a,n-2);
			printf("%d %d\n",500009*5,500009*3);
		}
		else if(n%3==2){
			print(a,n-3);
			printf("%d %d %d\n",500009*5,500009*11,11*3);
		}
		else{
			print(a,n);
			printf("\n");
		}
		
	}
	return 0;
}