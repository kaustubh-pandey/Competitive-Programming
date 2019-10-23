#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n,t;
	cin>>n>>t;
	int d;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>d;
		sum+=d;
	}
	sum+=(n-1)*10;
	if(sum >t){
		cout<<-1<<endl;
	}
	else{
		cout<<2*(n-1)+(int)(t-sum)/5<<endl;
	}

return 0;
}