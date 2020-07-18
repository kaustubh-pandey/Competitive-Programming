#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f(ll x,ll y, ll z){
	return (x&z)*(y&z);	
}
string binary(ll val){
	string res="";
	while(val){
		char c = ((val&1)+'0');
		res = c+res;
		val = val>>1;	
	}
	return res;	
}
ll getint(string s){
	ll p = 1;
	ll res=0;
	for(ll i=s.size()-1;i>=0;i--){
		res+= p* (s[i]-'0');
		p*=2;	
	}
	return res;	
}
void recurse(vector<string> &v,string low,string high,string curr, ll index,bool flag){
	if(index>= (ll)high.size()){return;}
	if(high[index]=='1'){
		string tmp = curr+'0';
		ll j = index+1;
		while(j<(ll)high.size()){
			tmp+='1';
			j++;	
		}
		v.push_back(tmp);		
	}
	if(high[index]=='1'){
		recurse(v,low,high,curr+'1',index+1,flag);
		recurse(v,low,high,curr+'0',index+1,true);	
	}
	if(high[index]=='0'){
		if(flag){
			string tmp = curr;
			ll j = index;
			while(j<(ll)high.size()){
				tmp+='1';
				j++;	
			}
			v.push_back(tmp);	
		}
		recurse(v,low,high,curr+'0',index+1,flag);	
	}	
}
ll find_max(vector<string> v, ll a,ll b){
	ll max_f = 0;
	ll max_val=0;
	for(auto x:v){
		ll i = getint(x);
		ll val = f(a,b,i);
		if(val>max_f){
			max_f = val;
			max_val = i;	
		}
		else if(val==max_f && i<max_val){
			max_val=i;	
		}	
	}
	return max_val;	
}
void brute_force(ll x,ll y,ll l,ll r){
	ll max_f = 0;
	ll max_val=0;
	for(ll i=l;i<=r;i++){
		ll val = f(x,y,i);
		if(val>max_f){
			max_f=val;
			max_val = i;	
		}
		if(i==549755813887){
			break;	
		}	
	}
	cout<<max_val<<endl;	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll x,y,l,r;
		cin>>x>>y>>l>>r;
		string low = binary(l);
		string high = binary(r);
		if(low.size()<high.size()){
			string tmp="";
			for(ll k=0;k<(ll)(high.size()-low.size());k++){
				tmp+='0';	
			}
			low = tmp+low;	
		}
		string prefix="";
		ll i=0;
		for(i=0;i<(ll)high.size();i++){
			if(low[i]!=high[i]){
				break;	
			}
			prefix+=low[i];	
		}
		//ll n = high.size();
		vector<string> v;
		string curr= prefix;
		//cout<<curr<<" "<<low<<" "<<high<<endl;
		recurse(v,low,high,curr,curr.size(),false);
		v.push_back(low);
		v.push_back(high);
		//for(auto w:v){
			//cout<<w<<endl;	
		//}
		cout<< find_max(v,x,y)<<endl;
		//cout<<f(x,y,549755813887)<<" "<<f(x,y,15)<<endl;
		//brute_force(x,y,l,r);
	}
	return 0;	
}
