#include <bits/stdc++.h>
#define l long int
using namespace std;

int main(){
	l x,n;
	for(n=1;n<100;n++){
	for(x=1;x<=n;x++){
		// scanf("%ld %ld",&x,&n);
		//cout<<(l)(n*(n+1)/2)<<endl;
		cout<<x<<" "<<n<<endl;
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
			sum1=sum;
			a[i+1]=1;
			l ncost=cost-sum;
			j=i+2;
			i=ncost;
			while(sum<cost && i>=1){
				//cout<<sum<<" "<<ncost<<endl;
				if(a[i]!=2 && a[i]!=0){
					sum+=i;
					a[i]=0;
					
				}
				i--;
			}
			while(cost!=sum){
				
				//cout<<"ldlladl"<<endl;
			if(cost!=sum){
				for(l i=ncost;i>=1;i--){
				if(i!=x){a[i]=1;}
				}
				sum=sum1-j;
				a[j]=1;
				/*for(l i=1;i<=n;i++)	{
					printf("%d",a[i]);
				}
				cout<<endl;*/
				a[j-1]=0;
				sum+=j-1;
				ncost=cost-sum;
				i=ncost;
				//cout<<ncost<<" "<<sum<<endl;
				while(sum<cost && i>=1){
					//cout<<sum<<" "<<ncost<<endl;
					if(a[i]!=2 && a[i]!=0){
						sum+=i;
						a[i]=0;
						
					}
					i--;
				}

			}
			j--;
		}
			
			if(sum>cost){
				cout<<"impossible";
			}
			else{
				for(l i=1;i<=n;i++)	{
					printf("%d",a[i]);
				}
				cout<<cost<<endl;
				l zs=0,os=0;
				for(l i=1;i<=n;i++){
					if(a[i]==0){
						zs+=i;
					}
					else if(a[i]==1){
						os+=i;
					}
				}
				if(zs==os){
					cout<<"true";
				}
				else{
					cout<<"false";
					return 0;
				}
				cout<<endl;
			}
			cout<<endl;
		}
	}
	}
	return 0;
}