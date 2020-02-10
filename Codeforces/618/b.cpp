#include<bits/stdc++.h>
#define ll long long
using namespace std;

 int main(){
 	int t;
 	cin>>t;
 	while(t--){
 		int n;
 		cin>>n;
 		vector<int> a(2*n,0);
 		for(int i=0;i<2*n;i++){
 			cin>>a[i];
 		}
 		sort(a.begin(),a.end());
 		vector<int> g1;
 		vector<int> g2;
 		for(int i=0;i<2*n;i++){
 				if(i%2){
 					g2.push_back(a[i]);
 				}
 				else{
 					g1.push_back(a[i]);
 				}
 		}

 		if(n%2){
 			cout<<abs(g1[n/2]-g2[n/2])<<endl;
 		}
 		else{
 			
 			cout<<min(abs(g1[(n/2)-1]-g2[n/2]),abs(g2[(n/2)-1]-g1[n/2]))<<endl;
 		}
 	}
 	return 0;
 }