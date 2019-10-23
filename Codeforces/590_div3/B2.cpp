#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int32_t main()
{
	int n,k;
	cin>>n>>k;
	vector<int> v;
	int tmp;
	unordered_map<int,int> m;
	int y=0;
	for(int i=0;i<n;i++){
		cin>>tmp;
		if(m[tmp]==1){
			continue;
		}
		v.pb(tmp);
		m[tmp]=1;
		if(v.size()-y>k){
			m[v[y]]=0;
			v[y]=-1;
			y++;
		}
	}
	cout<<v.size()-y<<endl;
	for(int i=0;i<v.size();i++){
		if(v[v.size()-i-1]==-1){
			break;
		}
		cout<<v[v.size()-i-1]<<" ";
	}
	cout<<endl;
	return 0;
}