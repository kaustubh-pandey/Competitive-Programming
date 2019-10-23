#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	vector<int> s(n,0);
	vector<long long> s1(n,0);
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s[i]=a[i];
		sum+=a[i];
		s1[i]=sum;
	}
	sort(s.begin(),s.end());
	vector<long long> s2(n,0);
	s2[0]=s[0];
	for(int i=1;i<n;i++){
		s2[i]=s2[i-1]+s[i];
	}
	int q,type,l,r;
	cin>>q;
	while(q--){
		cin>>type>>l>>r;
		if(type==1){
			cout<<s1[r-1]-s1[l-1]+a[l-1]<<endl;
		}
		else{
			cout<<s2[r-1]-s2[l-1]+s[l-1]<<endl;
		}
	}
	return 0;
}