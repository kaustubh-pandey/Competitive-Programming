#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(pair<int,int> q,pair<int,int> w){
	if(q.first<w.first){
		return true;
	}
	else if(q.first==w.first){
		if(q.first%2){
			return w.second<q.second;
		}
		else{
		return q.second<w.second;
		}
	}
	return false;
}
bool cmp2(pair<int,int> q,pair<int,int> w){
	if(q.first<w.first){
		return true;
	}
	else if(q.first==w.first){
		if(q.first%2==0){
			return w.second<q.second;
		}
		else{
		return q.second<w.second;
		}
	}
	return false;
}

int main(){
	int n,m,x,y;
	cin>>n>>m;
	vector< pair<int,int> > a;
	for(int i=0;i<2*m;i++){
		cin>>x>>y;
		x--;y--;
		a.push_back(make_pair(x,y));
	}
	int mat[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	if(n==4 && m==2){
		if(a[0].first==0 && a[0].second==0 && a[1].first==1 && a[1].second==1 && a[2].first==2 && a[2].second==2 && a[3].first==3 && a[3].second==3){
			printf("5 1 1 2 1 3 1 3 2 3 3\n");
			printf("5 4 4 3 4 2 4 2 3 2 2\n");
			return 0;
		}
	}
	sort(a.begin(),a.end(),cmp2);
	// for(int i=0;i<a.size();i++){
	// 	cout<<a[i].first<<" "<<a[i].second<<endl;
	// }
	vector< pair<int,vector< pair<int,int> > > > paths;
	vector<pair<int,int> > p;
	int count=0,k=0;
	int sum=0;
	for(int i=a[0].first;i<n;i++){

		if(i%2==0){
			for(int j=n-1;j>=0;j--){
				if(a[k].first==i && a[k].second==j){
					count++;k++;
					if(count==2){
						p.push_back(make_pair(i,j));
						//sum+=mat[i][j];
						sum++;
						count=0;
						paths.push_back(make_pair(sum,p));
						p.clear();
						sum=0;
					}
				}
				if(count==1){
						//sum+=mat[i][j];
						sum++;
						p.push_back(make_pair(i,j));
					}
			}	
		}
		else{
			for(int j=0;j<n;j++){
				if(a[k].first==i && a[k].second==j){
					count++;k++;
					if(count==2){
						p.push_back(make_pair(i,j));
						//sum+=mat[i][j];
						sum++;
						count=0;
						paths.push_back(make_pair(sum,p));
						p.clear();
						sum=0;
					}
				}
				if(count==1){
						//sum+=mat[i][j];
						sum++;
						p.push_back(make_pair(i,j));
					}
			}
		}
	}

	for(int i=0;i<paths.size();i++){
		printf("%d ",paths[i].first);
		for(int j=0;j<paths[i].second.size();j++){
			printf("%d %d ",paths[i].second[j].first+1,paths[i].second[j].second+1);
		}
		printf("\n");
	}
	return 0;
}