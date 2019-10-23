#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	/*Start from m to reach n, either divide by 2 if m is even or add 1*/
	if(n>=m){
		cout<<n-m<<endl;
	}
	else{
		int count=0;
		while(m!=n){
			if(m>n && m%2==0){
				m=m/2;
				count++;
			}
			else if(m>n){
				m++;
				count++;
			}
			else{
				count+=n-m;
				m=n;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}