#include <bits/stdc++.h>
using namespace std;

string sub(string a,string b){
	string c="";
	for(int i=a.length()-1;i>=0;i--){
		int k,l;
		char er;
		k=a[i]-'0';
		l=b[i]-'0';
		if(k>=l){
			er=(k-l)+'0';
			c=er+c;
		}
		else{
			er=(k-l+10)+'0';
			c=er+c;
			l=(a[i-1]-'0')-1;
			//cout<<l<<"//";
			a[i-1]=l+'0';
		}
	}
	return c;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string a,b;
		cin>>a;
		cin>>b;
		int m=0,u;
		if(a.length()>b.length()){
			u=a.length()-b.length();
			while(u){
				b="0"+b;
				u--;
			}
		}
		else if(b.length()>a.length()){
			u=b.length()-a.length();
			while(u){
				a="0"+a;
				u--;
			}
			m=1;
		}
		else{
			int o;
			for(int i=0;i<a.length();i++){
				u=a[i]-'0';
				o=b[i]-'0';
				if(o>u){
					m=1;
					break;
				}
				else if(u>o){
					break;
				}
			}
		}
		string c;
		if(m==0){
			c=sub(a,b);
		}
		else{
			c=sub(b,a);
		}
		//cout<<c<<endl;
		int i;
		for(i=0;i<c.length();i++){
			if(c[i]=='0'){
				continue;
			}
			else{
				break;
			}
		}
		string qw="";
		while(i<c.length()){
			qw+=c[i];
			i++;
		}
		if(qw==""){
			qw="0";
		}
		string nine="";
		for(i=0;i<qw.length();i++){
			nine+='9';
		}
		cout<<sub(nine,qw)<<endl;
	}
return 0;
}