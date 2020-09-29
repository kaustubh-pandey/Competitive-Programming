#include<bits/stdc++.h>
using namespace std;
class Compare{
    public:
    Compare(){
        
    }
    bool operator()(int p1,int p2){
        if(p1<p2){
			return true;	
		}
        return false;
    }
};
int main(){
	vector<int> res = {1,2,3,3,4,7,5,6,9,7,4};
	priority_queue< int, vector<int>, Compare> pq(res.begin(),res.end());
	while(!pq.empty()){
		cout<< pq.top()<<endl;
		pq.pop();	
	}
}
