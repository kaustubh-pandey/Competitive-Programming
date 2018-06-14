#include<bits/stdc++.h>
using namespace std;

void segment_tree(int *tree,int *a,int i,int start,int end){
	if(start==end){
		tree[i]=a[start];
	}
	else{
		int mid=(start+end)/2;
		segment_tree(tree,a,2*i+1,start,mid);
		segment_tree(tree,a,2*i+2,mid+1,end);

		//Edit here---------------------------------------------------------------------------------------------
		tree[i]=min(tree[2*i+1],tree[2*i+2]);	//This line decides if we store sum,or max or min of given range
	}	
}

//Updates a single value at index idx of array a
void update(int *tree,int *a,int i,int start,int end,int idx,int val){
	//idx is index of a to update by adding value val
	if(start==end){
		a[idx]+=val;
		tree[i]+=val;
	}
	else{
		int mid=(start+end)/2;
		if(start<=idx && idx<=mid){
			update(tree,a,2*i+1,start,mid,idx,val);
		}
		else{
			update(tree,a,2*i+2,mid+1,end,idx,val);
		}

		//Edit here---------------------------------------------------------------------------------------------
		tree[i]=min(tree[2*i+1],tree[2*i+2]);	//This line decides if we store sum,or max or min of given range
	}
}

//Query in range l to r
int query(int *tree,int i,int start,int end,int l,int r){
	if(r<start || l>end){
		//Edit here---------------------------------------------------------------------------------------------
		return INT_MAX;	//return 0 for sum case , return INT_MAX for min case
	}
	if(l<=start && end<=r){
		return tree[i];
	}
	int mid=(start+end)/2;
	//Edit here---------------------------------------------------------------------------------------------
	int result=min(query(tree,2*i+1,start,mid,l,r),query(tree,2*i+2,mid+1,end,l,r));

	return result;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//Build segment tree-----------------------------------------------------------------------------|
	int h=floor(log(2*n-1)/log(2));
	int size=(1<<(h+1))-1;
	int *tree=new int[size];
	segment_tree(tree,a,0,0,n-1);
	//Segment tree of len=size-----------------------------------------------------------------------|
	//update(tree,a,0,0,n-1,idx,val);
	int l=3,r=5;
	//range l to r min value
	printf("%d\n",query(tree,0,0,n-1,l,r));
	return 0;
}