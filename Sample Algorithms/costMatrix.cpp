#include<bits/stdc++.h>
using namespace std;
//A matrix is given with cost to access each of the cell.
//Find the min cost to reach from 0,0 to n-1,n-1 by going only down or right
int minCost(int m[][100],int i,int j,int mem[][100]){

	if(i<0 || j<0){
		return 0;
	}
	if(mem[i][j]!=0){
		return mem[i][j];
	}
	else if(i==0){
		return mem[i][j]=m[i][j]+minCost(m,i,j-1,mem);
	}
	else if(j==0){
		return mem[i][j]=m[i][j]+minCost(m,i-1,j,mem);
	}
	
	else{
	int cost=m[i][j];
	//printf("**%d %d**\n",i,j);
	return mem[i][j]=cost+min(minCost(m,i-1,j,mem),minCost(m,i,j-1,mem));
	}
}
int main(){
	int m[100][100],mem[100][100];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&m[i][j]);
			mem[i][j]=0;
		}
	}
	printf("%d\n",minCost(m,n-1,n-1,mem));
	
	return 0;
}