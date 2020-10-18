#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false) ,cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		int ii=1;
		int kk=1;
		int jj=1;
		for(int i=0;i<334;i++){
			for(int j=0;j<201;j++){
				for(int k=0;k<149;k++){
				 	ans=0;
					ans=3*i+5*j+7*k;
					if(ans==n){
						ii=i;
						jj=j;
						kk=k;
						break;
					}
				}
				if(ans == n){
					break;
				}
			}
			if(ans == n){
				break;
			}
		}
		if(ans==n){
			cout<<ii<<" "<<jj<<" "<<kk<<"\n";
		}
		else{
			cout<<"-1\n";
		}
	}
}