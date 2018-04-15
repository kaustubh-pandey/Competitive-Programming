#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int low,int mid,int high){
	int b[100],c[100];
	int i;
	for(i=low;i<=mid;i++){
		b[i-low]=a[i];
	}
	b[i-low]=INT_MAX;

	for(i=mid+1;i<=high;i++){
		c[i-mid-1]=a[i];
	}
	c[i-mid-1]=INT_MAX;
	int j=0,k=0;
	i=low;
	for(int y=low;y<=high;y++){
		a[y]=0;
	}
	while(j<mid-low+2 && k<high-mid+1 && i<=high){
		if(b[j]<=c[k]){
			a[i++]=b[j++];
			
		}
		else{
			a[i++]=c[k++];
			
		}
	}

}
void mergeSort(int a[],int low,int high){
	if(low+1==high){
		if(a[low]>a[high]){
			swap(a[low], a[high]);
		}
		//printf("\n**%d %d**\n",a[low],a[high]);
		return;
	}
	if(low==high){
		return;
	}

	int mid=(low+high)/2;
	mergeSort(a,low,mid);
	mergeSort(a,mid+1,high);
	merge(a,low,mid,high);
	
}
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	mergeSort(a,0,n-1);
	//merge(a,0,(n-1)/2,n-1);
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}