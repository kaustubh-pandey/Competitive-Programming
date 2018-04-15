//Activity selection problem greedy way
#include <bits/stdc++.h>
using namespace std;
void printmaxAct(int *start,int *finish,int n){
	vector<pair<int,int> >v;
	//finish,start
	for(int i=0;i<n;i++){
		v.push_back(make_pair(finish[i],start[i]));
	}
	sort(v.begin(),v.end());
	int prev=0;
	for(int i=0;i<n;i++){
		
		if(prev<=v[i].second){
		cout<<v[i].second<<" "<<v[i].first<<endl;
		prev=v[i].first;	
		}
	}
}
int main(){
	int start[]={1,3,5,7,9,11};
	int finish[]={3,9,7,12,10,13};
	printmaxAct(start,finish,6);
	return 0;
}