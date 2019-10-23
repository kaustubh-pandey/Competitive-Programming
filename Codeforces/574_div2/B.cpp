#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	ll n,k;
	cin>>n>>k;
	ll l = (ll)sqrt(8*(ll)(n+k)+9);
	l = (l-3)/2;
	cout<<n-l<<endl;
	return 0;
}