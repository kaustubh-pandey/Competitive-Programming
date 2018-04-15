#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
int *a=new int[n];
for(int i=0;i<n;i++){
	cin>>a[i];
}
int max=0;
for(int i=0;i<n;i++){
	if(a[i]>max){
		max=a[i];
	}
}
int *key=new int[max+1];
for(int i=0;i<=max;i++){
	key[i]=0;
}
for(int i=0;i<n;i++){
	key[a[i]]++;
}
for(int i=1;i<=max;i++){
	key[i]+=key[i-1];
}
int *sorted=new int[n+1];
for(int i=0;i<n;i++){
	//key[a[i]] sorted[key[a[i]]]=a[i]
	sorted[key[a[i]]]=a[i];
	key[a[i]]--;
}
for(int i=1;i<n+1;i++){
	cout<<sorted[i]<<" ";
}
cout<<endl;

return 0;	
}