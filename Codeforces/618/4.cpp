#include<bits/stdc++.h>
#define ll long long
using namespace std;
//Didn't work
/*
 int main(){
 	int n;
 	cin>>n;
 	vector<double> a;
 	int x;
 	for(int i=0;i<n;i++){
 		cin>>x;
 		a.push_back(x);
 	}
 	int i=0;
 	while(i<n-1){
 		if(a[i]>a[i+1]){
 			int j=i+1;
 			double sum = a[i]+a[j];
 			while(j<n-1 && (double)(sum/(j-i+1))>a[j+1]){
 				j++;
 				sum+=a[j];
 			}
 			for(int k=i;k<=j;k++){
 				a[k]=(double)(sum/(j-i+1));
 			}
 			i=j;
 		}
 		i++;
 	}
 	std::cout << std::fixed;
    std::cout << std::setprecision(9);
 	for(int k=0;k<a.size();k++){
 		cout<<a[k]<<endl;
 	}
 	return 0;
 }
 */
