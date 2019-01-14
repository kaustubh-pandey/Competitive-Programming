#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,a,b,n1=0,n2=0,common=0;
		scanf("%d %d %d",&n,&a,&b);
		vector<ll> z;
		ll temp;
		for(int i=0;i<n;i++){
			scanf("%lld",&temp);
			z.push_back(temp);
		}

		for(int i=0;i<n;i++){
			if(z[i]%(a*b)==0){
				common++;
			}
			if(z[i]%a==0){
				n1++;
			}
			if(z[i]%b==0){
				n2++;
			}
		}
		int flag=0;
		if(n1>n2){
			flag=1;
		}
		else if(n1==n2 && common){
				flag=1;	
		}
		if(flag){
			cout<<"BOB"<<endl;
		}
		else{
			cout<<"ALICE"<<endl;
		}
		
	}
	return 0;
}