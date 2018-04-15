#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int y;
		scanf("%lld",&y);
		long long int count=0,val;
		for(long long int i=1;i<y && i<=700;i++){
			val=sqrt(y-i);
			count+=val;
		}

		printf("%lld\n",count);
	}
	return 0;
}