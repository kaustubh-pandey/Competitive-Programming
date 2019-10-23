#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		ll m,n;
		cin>>n>>m;
		ll a[10];
		ll sum_=0;
		for(int i=0;i<10;i++){
			a[i]=(m*(i+1))%10;
			sum_+=a[i];
		}
		ll num=n/m;
		ll q = num/10;
		ll r = num%10;
		ll sum=sum_*q;
		ll k=0;
		while(r--){
			sum+=a[k];
			k++;
			if(k>9){
				k=0;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}