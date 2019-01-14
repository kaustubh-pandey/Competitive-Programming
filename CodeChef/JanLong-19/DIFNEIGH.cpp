#include<bits/stdc++.h>
#define ll long long
using namespace std;

void fillRow(int a[][81],int row,int col,int num){
	int count=num;
	for(int j=col;j<80;j+=2){
		a[row][j]=count;
		a[row][j+1]=count;
		count++;
		if(count==5){count=1;}
	}
	
}

void copy(int a[][81]){
	int curr_row=3;
	int copy_row=0;
	while(curr_row<=80){
		for(int j=0;j<80;j++){
			a[curr_row][j]=a[copy_row][j+1];
		}
		curr_row++;copy_row++;
	}
}
int main(){
	int t;
	cin>>t;
	int a[81][81];
	int b[2][81];
	int c[81][2];

	int fl=1;
	for(int i=0;i<80;i++){
		c[i][0]=fl;
		c[i][1]=fl;
		fl++;
		if(fl==4){fl=1;}
	}
	
	int count=1;
	for(int j=0;j<80;j+=2){
		b[0][j]=count;
		b[0][j+1]=count;
		count++;
		if(count==4){count=1;}
	}
	count=3;
	b[1][0]=2;
	for(int j=1;j<80;j+=2){
		b[1][j]=count;
		b[1][j+1]=count;
		count++;
		if(count==4){count=1;}
	}

	//fill a
	fillRow(a,0,0,1);
	a[1][0]=2;
	fillRow(a,1,1,3);
	fillRow(a,2,0,4);
	copy(a);

	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		if(n==1){
			if(m>2){
				printf("2\n");
				for(int j=0;j<m;j++){
					if(j%4==0 || j%4==1){
						printf("1 ");
					}
					else{
						printf("2 ");
					}
				}
				printf("\n");
			}
			else{
				printf("1\n");
				for(int j=0;j<m;j++){
					printf("1 ");
				}
				printf("\n");
			}
		}
		else if(m==1){
			if(n>2){
				printf("2\n");
				for(int j=0;j<n;j++){
					if(j%4==0 || j%4==1){
						printf("1\n");
					}
					else{
						printf("2\n");
					}
				}
			}
			else{
				printf("1\n");
				for(int j=0;j<n;j++){
					printf("1\n");
				}
			}
		}
		else if(m==2){
			if(n==2){
				printf("2\n");
				printf("1 1\n2 2\n");
			}
			else{
				printf("3\n");
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						printf("%d ",c[i][j]);
					}
				printf("\n");
				}
			}
		}
		else if(n==2){
			if(m==2){
				printf("2\n");
				printf("1 1\n2 2\n");
			}
			else{
				printf("3\n");
				//printf("THis\n");
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						printf("%d ",b[i][j]);
					}
				printf("\n");
				}
				}

			}
		else{
			printf("4\n");
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					printf("%d ",a[i][j]);
				}
			printf("\n");
			}
		}


	}
	return 0;
}