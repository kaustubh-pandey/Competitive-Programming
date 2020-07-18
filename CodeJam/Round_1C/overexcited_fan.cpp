#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dist(pair<int,int> o,pair<int,int> t){
	return abs(o.first-t.first)+abs(o.second-t.second);
}
int main(){
	int t;
	cin>>t;
	for(int z=1;z<=t;z++){
		int x,y;
		cin>>x>>y;
		string path;
		cin>>path;
		map< pair<int,int> , vector<int> > tour;
		tour[make_pair(x,y)].push_back(0);
		int xurr=x,yurr=y,time=0;
		vector< pair<int,int> > inters;
		inters.push_back(make_pair(x,y));
		for(int i=0;i<path.size();i++){
			if(path[i]=='N'){
				yurr++;
			}
			if(path[i]=='S'){
				yurr--;
			}
			if(path[i]=='E'){
				xurr++;
			}
			if(path[i]=='W'){
				xurr--;
			}
			time++;
			tour[make_pair(xurr,yurr)].push_back(time);
			inters.push_back(make_pair(xurr,yurr));
		}
		pair<int,int> origin = make_pair(0,0);
		vector< pair<int, pair<int,int> > > cont;
		for(auto coo:inters){
			int mytime = dist(origin,coo);
			vector<int> your = tour[coo];
			for(int e:your){
				if(mytime<=e){
					cont.push_back(make_pair(e,coo));
				}
			}
		}
		sort(cont.begin(),cont.end());
		if(cont.size()){
			cout<<"Case #"<<z<<": "<<cont[0].first<<endl;
		}
		else{
			cout<<"Case #"<<z<<": IMPOSSIBLE"<<endl;
		}
	}
	return 0;
}