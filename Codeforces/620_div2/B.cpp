#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(i=0;i<n;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define Fo(i,q,n) for(i=q;i<n;i++)
#define rFo(i,q,n) for(i=n-1;i>=q;i--)
#define fO(i,n,k) for(i=0;i<n;i+=k)
#define FO(i,q,n,k) for(i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
string pal(string s){
	string tmp="";
	int i;
	rfo(i,s.size()){
		tmp+=s[i];
	}
	return tmp;
}
bool cpal(string s){
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			return false;
		}
	}
	return true;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<string> str;
	map<string,bool> mp;
	int i;
	fo(i,n){
		string tmp;
		cin>>tmp;
		str.push_back(tmp);
		mp[tmp]=true;
	}
	string res="";
	vector<string> el;
	vector<string> ele;
	fo(i,n){
		string tr = pal(str[i]);
		if(str[i]==tr){
			el.push_back(str[i]);
			continue;
		}
		if(mp[tr]==true){
			mp[tr]=false;
			mp[str[i]]=false;
			ele.push_back(str[i]);
		}
	}
	string back="";
	for(i=0;i<ele.size();i++){
		res+=ele[i];
	}
	for(i=res.size()-1;i>=0;i--){
		back+=res[i];
	}
	string mid="";
	for(i=0;i<el.size();i++){
		if(cpal(mid+el[i])){
			mid+=el[i];
		}
	}
	res+=mid;
	res+=back;
	if(res.size()==0){
		cout<<0<<endl;
	}
	else{
		cout<<res.size()<<endl;
		cout<<res<<endl;
	}
	return 0;
}