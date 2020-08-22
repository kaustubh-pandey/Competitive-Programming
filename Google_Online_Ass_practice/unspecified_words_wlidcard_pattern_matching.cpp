#include<bits/stdc++.h>
using namespace std;
string calculate(string s,int n){
	int r = s.size()-1;
	string res="";
	while(r>=0){
		if(n&1){
			res='?'+res;		
		}
		else{
			res=s[r]+res;	
		}
		r--;
		n= n>>1;	
	}
	return res;	
}
void generate(string s,unordered_map<string,int> &dict){
		//use bitmasking to generate all possibilities of ?
		for(int i=0;i<(1<<((int)s.size()));i++){
			string res = calculate(s,i);
			dict[res]+=1;
		}
}
int main(){
	int n,q,m;
	cin>>n>>m;
	unordered_map<string,int> dict;
	string tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		generate(tmp,dict);	
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>tmp;
		cout<<dict[tmp]<<endl;	
	}
	return 0;	
}
