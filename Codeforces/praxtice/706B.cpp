#include <bits/stdc++.h>
using namespace std;
int MAX(vector<int> a){
	int res=a[0];
	for(int i=1;i<a.size();i++){
		res=max(res,a[i]);
	}
	return res;
}
int main(){
	/*
	1. Sort the shop
	2. For each query use upper bound
	Complexity O((n+q)logn)
	*/
	int n;
	cin>>n;
	vector<int> shop(n,0);
	for(int i=0;i<n;i++){
		cin>>shop[i];
	}
	/*sort(shop.begin(),shop.end());
	int q,temp;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>temp;
		vector<int>::iterator low=upper_bound(shop.begin(),shop.end(),temp);
		int start = low-shop.begin()-1;
		//cout<<start<<endl;
		if(start==n-1 && shop[n-1]<=temp){
			cout<<n<<endl;
		}
		else{
			cout<<start+1<<endl;
		}
	}*/

	/*
	O(n+q) solution
	calculate frequency of each element in O(n)
	Find prefix sum of this
	Process each query in O(1)
	*/

	vector<int> dp(MAX(shop)+1,0);
	for(int i=0;i<n;i++){
		dp[shop[i]]++;
	}
	int curr_sum=0;
	for(int i=0;i<dp.size();i++){
		curr_sum+=dp[i];
		dp[i]=curr_sum;
	}
	int q,temp;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>temp;
		if(temp>=dp.size()){
			cout<<n<<endl;
		}
		else{
			cout<<dp[temp]<<endl;
		}
		
	}	
	return 0;
}