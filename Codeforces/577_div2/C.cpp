#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	if(n==1){
		cout<<v[0]+k<<endl;
		return 0;
	}
	sort(v.begin(),v.end());
	int mid = n/2;
	int curr;
	for(int i=mid+1;i<n;i++){
		long long int val = (long long int)(v[i]-v[i-1])*(long long int)(i-mid);
		curr=i;
		if(k>=val){
			k = k-val;
		}
		else{
			//curr=i-1;
			curr--;
			break;
		}
	}
	//cout<<k<<endl;
	cout<<v[curr]+(k/(curr-mid+1))<<endl;
	return 0;
}