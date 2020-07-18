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
	string s;
	cin>>s;
	map<char,bool> m;
	for(int i=0;i<(int)s.size();i++){
		m[s[i]]=true;
	}
	int count=0;
	for(auto x:m){
		count++;
	}
	if(count%2){
			cout<<"IGNORE HIM!"<<endl;
	}
	else{
		cout<<"CHAT WITH HER!"<<endl;
	}
	//cout<<count<<endl;
	return 0;
}
