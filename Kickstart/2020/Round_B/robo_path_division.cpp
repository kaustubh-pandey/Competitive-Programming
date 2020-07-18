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
#define MOD 1000000000
using namespace std;
//This code uses division and hence didn't pass 2nd test case
pair<ll,ll> solve(string s){
	map<char,ll> m;
	ll col=1,row=1;
	ll pro=1;
	stack<int> st;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]=='N' || s[i]=='S' || s[i]=='E' || s[i]=='W'){
				if(s[i]=='N'){	
					row = (row-(pro%MOD))%MOD;
					if(row<1){
						row+=MOD;	
					}	
				}
				else if(s[i]=='S'){
					row = (row+(pro%MOD))%MOD;
					if(row<1){
						row+=MOD;	
					}
				}
				else if(s[i]=='E'){
					col = (col+(pro%MOD))%MOD;
					if(col<1){
						col+=MOD;	
					}
				}
				else{
					col = (col-(pro%MOD))%MOD;
					if(col<1){
						col+=MOD;	
					}
				}
		}
		else if(s[i]!=')' && s[i]!='('){
			//number
			int val = s[i]-'0';
			pro=(pro*val)%MOD;
			st.push(val);	
		}
		else if(s[i]==')'){
			if(!st.empty()){
				int tmp = st.top();
				st.pop();
				pro=(pro/tmp)%MOD;	
			}	
		}
	}
	
	return mp(col,row);
}

int main(){
	int t;
	cin>>t;
	for(int z=1;z<=t;z++){
		string s;
		cin>>s;
		pair<int,int> coord = solve(s);
		cout<<"Case #"<<z<<": "<<coord.first<<" "<<coord.second<<endl;
	}
	return 0;
}
