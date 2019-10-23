#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		ll sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		//cout<<"sum "<<sum<<endl;
		if(!((sum%2) ^ (k%2))){
			ll count = 0;
			vector<int> ind;
			for(int i=0;i<n && ind.size()<k-1;i++){
				count+=a[i];
				if(count%2){
					ind.push_back(i);
					count=0;
				}
			}
			//cout<<ind.size()<<" "<<k<<endl;
			if(ind.size()==k-1){
				cout<<"YES"<<endl;
				for(int i=0;i<ind.size();i++){
					cout<<ind[i]+1<<" ";
				}
				cout<<n<<endl;	
			}
			else{
				cout<<"NO"<<endl;
			}
			
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}