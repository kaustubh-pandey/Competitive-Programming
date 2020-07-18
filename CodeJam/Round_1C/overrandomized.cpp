#include<bits/stdc++.h>
#define ll long long
using namespace std;
void print(vector< pair<int,string> > queries){
	for(auto x:queries){
		cout<< x.first<<" "<<x.second<<endl;
	}
}
bool isRep(int n){
	int dig= (n%10);
	n=n/10;
	while(n){
		int d = n%10;
		n=n/10;
		if(dig!=d){
			return false;
		}
	}
	return true;
}
bool isSame(string s){
	char c = s[0];
	for(int i=1;i<s.size();i++){
		if(c!=s[i]){
			return false;
		}
	}
	return true;
}
bool match(string a,string b,int index){
	if(a.size()!=b.size()){
		return false;
	}
	for(int k=0;k<a.size();k++){
		if(k!=index){
			if(a[k]!=b[k]){
				return false;
			}
		}
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	for(int z=1;z<=t;z++){
		int u;
		cin>>u;
		set< pair<int,string> > tmp;
		int count=0;
		unordered_map<char,bool> isThere;
		for(int i=0;i<10000;i++){
			int val;
			string s;
			cin>>val;
			cin>>s;
			if(count<10){
				for(int j=0;j<s.size();j++){
					if(!isThere[s[j]]){
						isThere[s[j]] = true;
						count++;
					}
				}
			}
			tmp.insert(make_pair(val,s));
		}
		// for(auto y:isThere){
		// 	cout<<y.first<<" "<<y.second<<endl;
		// }
		vector< pair<int,string> > queries;
		vector< pair<int,string> > repeated;
		for(auto x:tmp){
			queries.push_back(x);
			if(isRep(x.first) && isSame(x.second)){
				repeated.push_back(x);
			}
		}
		sort(queries.begin(),queries.end());
		int start=1;
		char arr[10];
		for(int i=0;i<10;i++){
			arr[i]='-1';
		}
		for(auto x:queries){
			if(x.first<=9 && x.first==start && arr[x.first]=='-1'){
				arr[x.first]=x.second[0];
				isThere[x.second[0]]=false;
				start++;
			}
			else{
				string num = to_string(x.first);
				int er=0;
				int index=-1;
				for(int k=0;k<num.size();k++){
					if(arr[num[k]-'0']!='-1'){
						num[k] = arr[num[k]-'0'];
					}
					else{er++;index=k;}
				}
				if(er==1){
					if(match(num,x.second,index)){
						arr[num[index]-'0']=x.second[index];
						isThere[x.second[index]]=false;
					}
				}
			}
		}
		for(auto x:repeated){
			if(isThere[x.second[0]]==true){
				arr[x.first]=x.second[0];
				isThere[x.second[0]]=false;
			}
		}
		for(auto ch:isThere){
			if(ch.second==true){
				arr[0]=ch.first;
			}
		}
		string res = "";
		for(int i=0;i<10;i++){
			res+=arr[i];
		}
		//print(queries);
		cout<<"Case #"<<z<<": "<<res<<endl;
	}
	return 0;
}