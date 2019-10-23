#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<pair<int,int> > v;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(),v.end());
	int flag=1,prev=min(v[0].first,v[0].second);
	for(int i=1;i<n;i++){
		if(prev>v[i].first && prev>v[i].second){
			flag=0;
			break;
		}
		else{
			if(v[i].first<=v[i].second){
				if(prev<=v[i].first){
					prev=v[i].first;
				}
				else{
					prev=v[i].second;
				}
			}
			else{
				if(prev<=v[i].second){
					prev=v[i].second;
				}
				else{
					prev=v[i].first;
				}
			}
		}
	}
	if(flag){
		cout<<prev<<endl;
	}
	else{
		cout<<v[n-1].first<<endl;
	}
	return 0;
}