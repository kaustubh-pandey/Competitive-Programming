#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
#define mp make_pair
#define F first
#define S second
using namespace std;

int main(){
	int mat[5][5];
	int px=0,py=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>mat[i][j];
			if(mat[i][j]==1){
				px=i;py=j;
			}
		}
	}
	cout<< abs(px-2)+abs(py-2)<<endl;
	return 0;
}
