#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	int even=0,odd=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]%2){
			odd++;
		}
		else{
			even++;
		}
	}
	cout<<min(odd,even)<<endl;
	return 0;
}