#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	if(s.size()%2){
		int flag=0;
		for(int i=1;i<s.size();i++){
			if(s[i]=='1'){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<(int)s.size()/2+1<<endl;
		}
		else{
			cout<<(int)s.size()/2<<endl;
		}
	}
	else{
		cout<<(int)s.size()/2<<endl;
	}

	return 0;
}