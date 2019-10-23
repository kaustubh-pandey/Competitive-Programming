#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[4*n];
		int xor_=0;
		for(int i=0;i<4*n;i++){
			cin>>a[i];
			xor_ = xor_^a[i];
		}
		if(xor_==0){
			sort(a,a+(4*n));
			vector<int> ind;
			for(int i=0;i<4*n;i+=2){
				ind.push_back(a[i]);
			}
			if(ind.size()%2){
				cout<<"NO"<<endl;
			}
			else{
				int flag=0;
				int pro = ind[0]*ind[ind.size()-1];
				for(int i=1;i<ind.size()/2;i++){
					if(pro!=ind[i]*ind[ind.size()-1-i]){
						flag=1;
						break;
					}
				}
				if(flag){
					cout<<"NO"<<endl;
				}
				else{
					cout<<"YES"<<endl;
				}
			}
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}