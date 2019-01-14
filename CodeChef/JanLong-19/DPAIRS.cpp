#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;

int base(int i,int j,int n,int m){
	if(i==n-1 && j==m-1){
		return 1;
	}
	return 0;
}
int main(){
	int n,m;
	cin>>n>>m;

	vector<ll> a;
	vector<ll> b;
	vector<ll> c;
	map<ll,int> dict_a;
	map<ll,int> dict_b;
	ll temp;
	for(int i=0;i<n;i++){
		scanf("%lld",&temp);
		a.push_back(temp);
		c.push_back(temp);
	}
	for(int i=0;i<n;i++){
		dict_a.insert(mp(a[i],i));
	}

	for(int i=0;i<m;i++){
		scanf("%lld",&temp);
		b.push_back(temp);
		c.push_back(temp);
	}

	for(int i=0;i<m;i++){
		dict_b.insert(mp(b[i],i));
	}

	sort(a.begin(),a.end());sort(b.begin(),b.end());
	int co=0;
	map<ll,pair<int,int> > kaush;
	map<ll,pair<int,int> >::iterator itr;
	int i=0,j=0;
	while(i<n || j<m){
		kaush.insert(mp(a[i]+b[j],mp(dict_a[a[i]],dict_b[b[j]])));
		if(base(i,j,n,m)){
			break;
		}
		co++;
		if(co%2 && i<n-1){i++;}
		else if(j<m-1){j++;}
	}
	for(itr=kaush.begin();itr!=kaush.end();itr++){
		printf("%d %d \n",itr->second.first,itr->second.second);
	}
	return 0;
}