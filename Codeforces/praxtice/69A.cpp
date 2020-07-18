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
	int n;
	cin>>n;
	int s1=0,s2=0,s3=0;
	fo(i,n){
		int a,b,c;
		cin>>a>>b>>c;
		s1+=a;
		s2+=b;
		s3+=c;
	}
	if(!s1 && !s2 && !s3){
		cout<<"YES"<<endl;
	}
	else{
			cout<<"NO"<<endl;
	}
	return 0;
}
