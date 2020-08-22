#include<bits/stdc++.h>
using namespace std;
int bitOverlap(int x,int y){
	int count=0;
	for(int i=0;i<32;i++){
		if(((x>>i)&1)==((y>>i)&1)){
			count++;	
		}	
	}
	return count;	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n,0);
		for(int i=0;i<n;i++){
			cin>>a[i];	
		}
		int orval=0;
		for(int x:a){
			orval = orval|x;	
		}
		set<int> st;
		while(orval>0){
			int maxcount=0;
			int maxval=0;
			for(auto x:a){
				int val = bitOverlap(x,orval);
				if(val>maxcount){
					maxcount=val;
					maxval = x;	
				}	
			}
			st.insert(maxval);
			orval = orval&(~maxval); //fix this
			//cout<<orval<<endl;	
		}
		cout<<st.size()<<endl;
	}	
	return 0;
}
