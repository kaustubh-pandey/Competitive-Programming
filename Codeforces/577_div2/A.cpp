#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int table[m][5];
	for(int i=0;i<m;i++){
		for(int j=0;j<5;j++){
			table[i][j]=0;
		}
	}
	vector<int> v;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			table[j][s[j]-'A']++;
		}
	}
	for(int i=0;i<m;i++){
		int mx=INT_MIN;
		for(int j=0;j<5;j++){
			mx=max(mx,table[i][j]);
		}
		v.push_back(mx);
	}
	// for(int i=0;i<m;i++){
	// 	cout<<v[i]<<endl;
	// }
	int sum=0;
	int d;
	for(int i=0;i<m;i++){
		cin>>d;
		sum+=d*v[i];
	}
	cout<<sum<<endl;

	return 0;
}