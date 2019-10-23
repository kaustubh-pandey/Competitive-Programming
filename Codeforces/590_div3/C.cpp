#include<bits/stdc++.h>
//#define int long long
#define pb push_back
using namespace std;

int32_t main()
{
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int m[2][n];
		string s,s2;
		cin>>s;
		for(int i=0;i<n;i++){
			if(s[i]=='1' || s[i]=='2'){
				m[0][i]=1;
			}
			else{
				m[0][i]=0;
			}
		}
		cin>>s2;
		for(int i=0;i<n;i++){
			if(s2[i]=='1' || s2[i]=='2'){
				m[1][i]=1;
			}
			else{
				m[1][i]=0;
			}
		}

		int dir=0;
		int i=1,j=n-1;
		int count=0;
		while(j>=0){
			if(count>2*n){
				break;
			}
			//cout<<i<<" "<<j<<" "<<dir<<"  "<<m[i][j]<<endl;
			if(m[i][j]==0){
				if(dir==0){
					if(i==0){
						dir=-1;
						i=1;
					}
					else{
						dir=1;
						i=0;
					}
				}
				else{
					dir=0;
					j-=1;
				}
			}
			else{
				if(dir==0){
					j-=1;
				}
				else{
					break;
				}
			}
			//cout<<i<<" "<<j<<" "<<dir<<endl;
			if(j==-1 && dir==0){
				break;
			}
			count++;
		}
		//cout<<i<<j<<dir<<endl;
		if(i==0 && j==-1 && dir==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}