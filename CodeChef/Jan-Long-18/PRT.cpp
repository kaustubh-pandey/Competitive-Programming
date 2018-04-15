#include <bits/stdc++.h>
#define l long int
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		l x,n;
		scanf("%ld %ld",&x,&n);
		//cout<<(l)(n*(n+1)/2)<<endl;
		if(n<4 || x>n){
			printf("impossible\n");
			
		}
		else if(((l)(n*(n+1)/2)-x)%2!=0){
			printf("impossible\n");
		}
		else{
			l cost= ((l)(n*(n+1)/2)-x)/2;

			int a[n+1];
			for(l i=0;i<=n;i++){
				a[i]=1;
			}
			a[0]=-1;
			a[x]=2;
			l sum=0,sum1;
			l i=n;
			l j;
			while(sum<=cost && i>=1){
				if(a[i]!=2){
					sum+=i;
					a[i]=0;
					
				}
				i--;
			}
			sum-=i+1;
			a[i+1]=1;
			l ncost=cost-sum;
			j=i+2;
			i=ncost;
			if(a[ncost]!=2 && a[ncost]!=0){
				a[ncost]=0;
				sum+=ncost;
			}
			else{
				if(ncost>=3){
					sum+=ncost;
					a[ncost-1]=0;
					a[1]=0;
				}
				else{
					sum-=j;
					a[j]=1;
					ncost=cost-sum;
					//cout<<ncost<<endl;
					if(a[ncost]==1){
						sum+=ncost;
						a[ncost]=0;
					}
					else{
						l k=ncost;
						while(sum!=cost && k>=1){
							if(a[k]==1 && a[ncost-k]==1){
								sum+=ncost;
								a[k]=0;
								a[ncost-k]=0;
							}
							k--;
						}
					}
				}
			}


			
			if(sum>cost){
				cout<<"impossible";
			}
			else{
				for(l i=1;i<=n;i++)	{
					printf("%d",a[i]);
				}
			}
			cout<<endl;
		}
	}
	return 0;
}