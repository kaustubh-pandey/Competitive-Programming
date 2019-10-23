//Reference : https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/
#include<bits/stdc++.h>
using namespace std;
void build(int node,int start,int end,vector<int> &tree,int arr[]){
	if(start==end){
		tree[node]=arr[start];
	}
	else{
		int mid = (start+end)/2;
		build(2*node+1,start,mid,tree,arr);
		build(2*node+2,mid+1,end,tree,arr);
		tree[node]=tree[2*node+1]+tree[2*node+2];
	}
}
//update value at index idx with val
void update(int node,int start,int end,int idx,int val,vector<int>&tree,int arr[]){
	if(start==end){
		arr[idx]=val;
		tree[node]=val;
	}
	else{
		int mid = (start+end)/2;
		if(start<=idx && idx<=mid){
			update(2*node+1,start,mid,idx,val,tree,arr);
		}
		else{
			update(2*node+2,mid+1,end,idx,val,tree,arr);
		}
		tree[node]=tree[2*node+1]+tree[2*node+2];
	}
}
//query
int query(int node,int start,int end,int l,int r,vector<int>tree){
	if(r<start || l>end){
		return 0;
	}
	if(l<=start && end<=r){
		return tree[node];
	}
	int mid = (start+end)/2;
	int q1=query(2*node+1,start,mid,l,r,tree);
	int q2=query(2*node+2,mid+1,end,l,r,tree);
	return q1+q2;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> tree((1<<(int)(ceil(log(n)/log(2))+1)),0);
	build(0,0,n-1,tree,arr);
	int q;
	cin>>q;
	int type,x,y;
	while(q--){
		cin>>type>>x>>y;
		if(type==1){
			//update val at index x with y
			update(0,0,n-1,x,y,tree,arr);
		}
		else{
			cout<<query(0,0,n-1,x,y,tree)<<endl;
		}
	}
	return 0;
}
