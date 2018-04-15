#include <bits/stdc++.h>
							//O(nlog(n))
using namespace std;
class Item{
public:
	int weight;
	int value;
	Item(int v,int w){
		weight=w;
		value=v;
	}
};

bool cmp(Item a,Item b){
	double r1=(double)a.value/a.weight;
	double r2=(double)b.value/b.weight;
	return r1>r2;
}

int main(){
	int n;
	int W;
	cin>>W;
	cin>>n;
	vector<Item> v;
	int va,we;
	for(int i=0;i<n;i++){
		cin>>va>>we;
		Item a(va,we);
		//cout<<a.value<<endl;
		v.push_back(a);
	}
	sort(v.begin(),v.end(),cmp);	//Sort in descending order based on value/weight ratio.
	/*for(int i=0;i<n;i++){
		cout<<v[i].value<<v[i].weight<<endl;
	}*/
	double final_val=0.0;
	for(int i=0;i<n;i++){
		if(v[i].weight<=W){
			final_val+=(double)v[i].value;
			W=W-v[i].weight;
		}
		else{
			final_val+=(double)(v[i].value/v[i].weight)*W;	//If whole lot can't be added ,add fraction of it.
			W=0;
			break;
		}
	}
	cout<<final_val<<endl;
return 0;
}