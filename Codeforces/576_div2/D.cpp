#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	map<int,vector<int> > m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m[a[i]].push_back(i);
	}
	int q;
	cin>>q;
	while(q--){
		int type,p,x;
		cin>>type;
		if(type==1){
			cin>>p>>x;
			remove(m[a[p-1]].begin(),m[a[p-1]].end(),p-1);
			a[p-1]=x;
			m[x].push_back(p-1);
		}
		else{
			cin>>x;
			for(auto y : m){
				if(y.first < x){
					for(int j=0;j<y.second.size();j++){
						a[y.second[j]]=x;
						m[x].push_back(y.second[j]);
					}
					m[y.first].clear();
				}
				else{break;}
			}
		}

	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}