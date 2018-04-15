#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
	int k;
	cin>>k;
	vector< vector<int> >v;
	vector <int> a;
	string s1,s2;
	cin>>s1;
	cin>>s2;
	for(int i=0;i<=s1.length();i++){
		a.push_back(0);
	}
	for(int i=0;i<=s2.length();i++){
		v.push_back(a);
	}
	int c;
	for(int i=0;i<=s1.length();i++){
		for(int j=0;j<=s2.length();j++){
			v[i][j]=0;
			if(i==0 || j==0){
				continue;
			}
			c=1;
			while(i-c>=0 && j-c>=0 && s1[i-c]==s2[j-c]){
				if(c>=k){
					v[i][j]=max(v[i][j],c+v[i-c][j-c]);
				}
				c++;
			}
			v[i][j]=max(v[i][j],v[i][j-1]);
			v[i][j]=max(v[i][j],v[i-1][j]);
		}
	}
	cout<<v[s1.length()][s2.length()]<<endl;
}
return 0;
}