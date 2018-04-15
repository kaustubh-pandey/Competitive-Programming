#include <bits/stdc++.h>
using namespace std;

void seq(vector < pair<pair<int,int> ,int> > a,int *prev,int i,vector < int > &s){
	s.push_back(a[i].second);
	if(prev[i]==-1){
		return;
	}
	seq(a,prev,prev[i],s);
		
}
int lis(vector < pair<pair<int,int> ,int> > a,int n, vector < int > &s){
	int *dp=new int[n];
	int *prev=new int[n];
	for(int i=0;i<n;i++){
		dp[i]=1;
		prev[i]=-1;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i].first.first>a[j].first.first && a[i].first.second>a[j].first.second && dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
				prev[i]=j;
			}
		}
	}
	int m=dp[0];
	int k=0;
	for(int i=1;i<n;i++){
		if(dp[i]>m){
			m=dp[i];
			k=i;
		}
	}
	seq(a,prev,k,s);
	return m;
}
int main(){
	int n;
	cin>>n;
	int h,t;
	vector < pair<pair<int,int> ,int> > a;
	for(int i=0;i<n;i++){
		cin>>h>>t;
		a.push_back(make_pair(make_pair(h,t),i+1));
	}
	sort(a.begin(),a.end());
	/*for(int i=0;i<n;i++){
		cout<<a[i].first.first<<","<<a[i].first.second<<","<<a[i].second<<endl;
	}*/
	vector < int > s;
	int k=lis(a,n,s);
	cout<<k<<endl;
	for(int i=s.size()-1;i>=0;i--){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}
