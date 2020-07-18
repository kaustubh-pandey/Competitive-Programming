#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
#define mp make_pair
#define F first
#define S second
using namespace std;
bool cmp(pair<int,pair<int,int> > p1, pair<int,pair<int,int> > p2){
	if(p1.first>p2.first){
			return false;
	}
	if(p1.first==p2.first){
		if(p1.second.first<p2.second.first){
				return false;
		}
		if(p1.second.first==p2.second.first){
			if(p1.second.second<=p2.second.second){return false;}
			return true;
		}
		return true;
	}
	return true;
}
int main(){
	priority_queue< pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > > ,function<bool(pair<int,pair<int,int> >, pair<int,pair<int,int> >)> > v(cmp);
	v.push(mp(1,mp(4,4)));
	v.push(mp(1,mp(3,8)));
	v.push(mp(1,mp(1,7)));
	v.push(mp(1,mp(2,3)));
	v.push(mp(2,mp(4,4)));
	v.push(mp(2,mp(3,8)));
	v.push(mp(2,mp(1,7)));
	v.push(mp(2,mp(2,3)));
	//sort(v.begin(),v.end());
	while(!v.empty()){
		auto x = v.top();
		v.pop();
		cout<< x.first << x.second.first << x.second.second<<endl;	
	}
	return 0;
}
