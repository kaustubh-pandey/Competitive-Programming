#include<bits/stdc++.h>
using namespace std;
int partition(int A[],int low,int high){
	int pivot=A[high];
	int i=low-1;
	for(int j=low;j<=high-1;j++){
		if(A[j]<=pivot){
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[high]);
	return i+1;
}
void quickSort(int A[],int low,int high){
	if(high>low){
		int pi=partition(A,low,high);
		quickSort(A,low,pi-1);
		quickSort(A,pi+1,high);
	
	}
}
int main(){
	int A[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	quickSort(A,0,n-1);
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");

	return 0;
}