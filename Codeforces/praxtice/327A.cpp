#include <bits/stdc++.h>
using namespace std;

//not so efficient code of O(n^3)
/*
int setBits(vector<int> a,int i,int j){
	int count=0;
	for(int k=i;k<=j;k++){
		if(a[k]==0){
			count++;
		}
	}
	return count;
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int max_set=INT_MIN;
	int totalOnes=n-setBits(a,0,n-1);
	//cout<<totalOnes<<endl;
	for(int len=n;len>0;len--){
		for(int i=0;i<=n-len;i++){
			int val=2*setBits(a,i,i+len-1)-len+totalOnes;
			if(val>max_set){
				max_set=val;
			}
		}
	}

	cout<<max_set<<endl;

	return 0;
}
*/

//efficient code of O(n)
int maxSubArraySum(vector<int> b,int n){
	int max_ending_here=b[0];
	int max_so_far=b[0];
	for(int i=1;i<n;i++){
		max_ending_here=max(b[i],max_ending_here+b[i]);
		max_so_far=max(max_so_far,max_ending_here);
	}
	return max_so_far;
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	vector<int> b(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]= -2*a[i]+1;// if ai==0 bi=1 else bi=-1
	}
	int totalOnes=0;
	for(int i=0;i<n;i++){
		if(a[i]){
			totalOnes++;
		}
	}
	cout<<totalOnes+maxSubArraySum(b,n)<<endl;
	return 0;
}