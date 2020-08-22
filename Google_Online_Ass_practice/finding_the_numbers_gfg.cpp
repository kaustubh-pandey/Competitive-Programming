#include<bits/stdc++.h>
using namespace std;
/*Using map*/
/*int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int d;
		unordered_map<int,int> dict;
		for(int i=0;i<2*n+2;i++){
			cin>>d;
			dict[d]++;	
		}
		vector<int> res;
		for(auto x:dict){
			if(x.second%2){
				res.push_back(x.first);	
			}	
		}
		sort(res.begin(),res.end());
		cout<<res[0]<<" "<<res[1]<<endl;
	}
}*/

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(2*n+2,0);
		for(int i=0;i<2*n+2;i++){
			cin>>a[i];	
		}
		int xoor=a[0];
		for(int i=1;i<(int)a.size();i++){
			xoor = xoor ^ a[i];	
		}
		int ind=0;
		while((1&(xoor>>ind))==0){
			ind++;	
		}
		int left=0;
		int right=0;
		for(auto x:a){
			if(1&(x>>ind2)){
				right^=x;	
			}
			else{
				left^=x;	
			}	
		}
		vector<int> res;
		res.push_back(right^0);
		res.push_back(left^0);
		sort(res.begin(),res.end());
		cout<<res[0]<<" "<<res[1]<<endl;	
	}	
}
