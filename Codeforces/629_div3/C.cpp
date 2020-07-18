#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
#define mp make_pair
#define F first
#define S second
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string x;
		cin>>x;
		string a="1";
		string b="1";
		bool flag=false;
		Fo(i,1,n){
			if(x[i]=='0'){
				a+='0';
				b+='0';	
			}
			else if(x[i]=='1'){
				if(flag){
					a+='1';
					b+='0';
				}
				else{
					a+='0';
					b+='1';
					flag=true;		
				}
			}
			else{
				if(a==b){
					a+='1';
					b+='1';			
				}
				else if(flag){
					a+='2';
					b+='0';	
				}
				else{
					a+='0';
					b+='2';	
				}
			}	
		}
		cout<<a<<endl;
		cout<<b<<endl;
	}
	return 0;
}
