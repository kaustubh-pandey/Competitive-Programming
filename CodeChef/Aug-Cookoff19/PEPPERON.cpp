#include<bits/stdc++.h>
#define ll long long
using namespace std;
int sum_arr(vector<int> a){
	int sum=0;
	for(int i=0;i<a.size();i++){
		sum+=a[i];
	}
	return sum;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int m[n][n];
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			for(int j=0;j<n;j++){
				if(s[j]=='1'){
					m[i][j]=1;
				}
				else{
					m[i][j]=0;
				}
			}

		}
		vector<int> left;
		vector<int> right;
		// int max_left=INT_MIN;
		// int max_right=INT_MIN;
		for(int i=0;i<n;i++){
			int sum=0;
			for(int j=0;j<n/2;j++){
				sum+=m[i][j];
			}
			left.push_back(sum);
			// if(sum>max_left){
			// 	max_left=sum;
			// }
			sum=0;
			for(int j=n/2;j<n;j++){
				sum+=m[i][j];
			}
			right.push_back(sum);
			// if(sum>max_right){
			// 	max_right=sum;
			// }
		}
		int left_sum=sum_arr(left);
		int right_sum=sum_arr(right);
		int res=INT_MAX;
		if(left_sum>right_sum){
			for(int i=0;i<n;i++){
				int val=left[i]-right[i];
				if(abs(left_sum-right_sum-2*val)<res){
					res=abs(left_sum-right_sum-2*val);
				}
			}
		}
		else if(right_sum>left_sum){
			for(int i=0;i<n;i++){
				int val=right[i]-left[i];
				if(abs(right_sum-left_sum-2*val)<res){
					res=abs(right_sum-left_sum-2*val);
				}
			}
		}
		else{
			res=0;
		}
		cout<<res<<endl;
	}
	return 0;
}