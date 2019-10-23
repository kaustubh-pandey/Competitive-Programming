#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	int freq[k+1];
	memset(freq,0,sizeof(freq));
	for(int i=0;i<n;i++){
		cin>>a[i];
		freq[a[i]]++;
	}
	vector< pair<int,int> > v;
	for(int i=1;i<=k;i++){
		v.push_back(make_pair(freq[i],i));
	}
	sort(v.begin(),v.end());
	int val = (int)ceil((float)n/2);
	int leftover=0;
	int res=0;
	for(int i=v.size()-1;i>=0;i--){
		if((v[i].first)/2 <= val){
			res+=(v[i].first)/2 *2;
			val-=(v[i].first)/2;
			v[i].first%=2;
		}
		else{
			res+=val*2;
			val=0;	
		}
	
	}

	if(val!=0){
		res+=val;
	}
	cout<<res<<endl;
	return 0;	
}