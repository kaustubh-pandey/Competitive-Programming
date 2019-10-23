#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n,m,a;
	cin>>n>>m>>a;
	ll res = (ll)((n+a-1)/a)*(ll)((m+a-1)/a);
	cout<<res<<endl;
	return 0;
}