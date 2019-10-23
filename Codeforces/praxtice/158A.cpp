#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int c;
	vector<int> a;
	for(int i=0;i<n;i++){
		cin>>c;
		if(c>0){
			a.push_back(c);
		}
	}
	//cout<<a.size()<<endl;
	if(a.size()==0){
		cout<<0<<endl;
		return 0;
	}
	sort(a.begin(),a.end());
	int count;
	if(k>a.size()){
		count=a.size();
	}
	else{
		count=k;
		int val = a[a.size()-k];
		for(int i=a.size()-k-1;i>=0;i--){
			if(a[i]==val){
				count++;
			}
		}
	}
	
	cout<<count<<endl;
	return 0;
}