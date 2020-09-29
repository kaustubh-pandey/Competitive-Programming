#include<bits/stdc++.h>
using namespace std;


int main(){
	deque<int> dq;
	dq.push_front(1);
	dq.push_back(2);
	dq.push_back(3);
	dq.push_back(4);
	dq.push_front(6);
	for(int i=0;i<(int)dq.size();i++){
		cout<<dq[i]<<endl;	
	}
	dq[1]=100;dq[3]=800;
	for(int i=0;i<(int)dq.size();i++){
		cout<<dq[i]<<endl;	
	}
	return 0;	
}
