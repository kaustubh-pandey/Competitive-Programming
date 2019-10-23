#include<bits/stdc++.h>
#define ll long long
using namespace std;
int intersect(vector<int> x,int x_max,int x_min){
	if(x_min>=x_max){
		if(x.size()==0){
			return x_max;
		}
		int val=x[0];
		for(int i=1;i<x.size();i++){
			if(val!=x[i]){
				return INT_MIN;
			}
		}
		if(val>=x_max && val<=x_min){
			return val;
		}
		return INT_MIN;
	}
	return INT_MIN;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int x_max=-100000;
		int x_min=100000;
		vector<int> x_;
		vector<int> y_;
		int y_max=-100000;
		int y_min=100000;
		int x,y,p,q,r,s;
		for(int i=0;i<n;i++){
			cin>>x>>y>>p>>q>>r>>s;
			if(p==0 && r==0){
				//x fix
				x_.push_back(x);
			}
			else if(p==0 && r==1){
				if(x > x_max){
					x_max=x;
				}
			}
			else if(p==1 && r==0){
				if(x < x_min){
					x_min=x;
				}		
			}

			if(s==0 && q==0){
				//x fix
				y_.push_back(y);
			}
			else if(s==0 && q==1){
				if(y > y_max){
					y_max=y;
				}
			}
			else if(s==1 && q==0){
				if(y < y_min){
					y_min=y;
				}
			}
		}
	int g = intersect(x_,x_max,x_min);
	int h = intersect(y_,y_max,y_min);
	if(g==INT_MIN ||  h==INT_MIN){
		cout<<0<<endl;
	}
	else{
		cout<<1<<" "<<g<<" "<<h<<endl;
	}
	
}
return 0;
}