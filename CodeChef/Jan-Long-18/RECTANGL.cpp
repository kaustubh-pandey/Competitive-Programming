#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		int s=0;
		if(a==b && c==d){s=1;}
		else if(a==c && b==d){s=1;}
		else if(a==d && b==c){s=1;}

		if(s==1){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
	}


	return 0;
}