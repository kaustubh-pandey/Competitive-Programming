#include<bits/stdc++.h>
using namespace std;
int bsearch(vector<int> a,int low,int high,int x){
	if(low<=high){
		int mid = (low+high)/2;
		if(a[mid]==x){
			return 1;
		}
		else if(x>a[mid]){
			return bsearch(a,low,mid-1,x);
		}
		else{
			return bsearch(a,mid+1,high,x);
		}
	}
	return 0;
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int q;
	cin>>q;
	vector< vector<int> > v;
	int count=0;
	int max_i,max_val=INT_MIN;
	while(q--){
		int type,p,x;
		cin>>type;
		if(type==1){
			cin>>p>>x;
			vector<int> temp;
			temp.push_back(1);
			temp.push_back(p-1);
			temp.push_back(x);
			v.push_back(temp);
		}
		else{
			cin>>x;
			vector<int> temp;
			temp.push_back(2);
			temp.push_back(x);
			if(x>max_val){
				max_val=x;
				max_i=count;
			}
			v.push_back(temp);
		}
		count++;
	}
	vector<pair<int,int> > t;
	for(int i=max_i;i<v.size();i++){
		if(v[i][0]==2){
			t.push_back(make_pair(v[i][1],i));
			//cout<<v[i][1]<<endl;
		}
	}
	max_val=INT_MIN;
	vector<int> index;
	for(int i=t.size()-1;i>=0;i--){
		if(t[i].first>max_val){
			max_val=t[i].first;
			index.push_back(t[i].second);
		}
	}
	// for(int i=0;i<index.size();i++){
	// 	cout<<index[i]<<endl;
	// }
	//cout<<max_i<<endl;
	//excute from max_i
	for(int i=0;i<v.size();i++){
		if(v[i][0]==1){
			a[v[i][1]]=v[i][2];
		}
		else if(i>=max_i && bsearch(index,0,index.size(),i)){
			for(int j=0;j<a.size();j++){
				if(a[j]<v[i][1]){
					a[j]=v[i][1];
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}