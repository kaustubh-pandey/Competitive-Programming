#include <bits/stdc++.h>
using namespace std;

int main(){
	/*
	O(n log n) complexity
	Two pointers - i finds sum from left side, whenever sum=totalsum/3 store i
				   j finds sum from right side, whenever sum=totalsum/3 store j
				   find all i<j-1 pairs in O(nlogn) using lower_bound
	*/
	int n;
	cin>>n;
	vector<int> a(n,0);
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%3!=0 || n<3){
		cout<<"0"<<endl;
		return 0;
	}
	int i=0,j=n-1;
	long long sumi=0,sumj=0;
	vector<int> is;
	while(i<n){
		sumi+=a[i];
		if(sumi==sum/3){
			is.push_back(i);
			//cout<<i<<endl;
		}
		i++;
	}

	vector<int> js;
	while(j>=0){
		sumj+=a[j];
		if(sumj==sum/3){
			js.push_back(j);
			//cout<<"#"<<j<<endl;
		}
		j--;
	}
	long long res=0;
	if(is.size()!=0 && js.size()!=0){
		for(int k=0;k<js.size();k++){
			vector<int>::iterator low = lower_bound(is.begin(),is.end(),js[k]);
			int elems=low-is.begin();
			if(elems>0 && is[elems-1]<js[k]-1){
				res+=elems;
			}
			else if(elems>1 && is[elems-2]<js[k]-1){
				res+=elems-1;
			}
		}
	}
	cout<<res<<endl;
	return 0;

}