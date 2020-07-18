#include<bits/stdc++.h>
using namespace std;


int main(){

ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int t;
cin>>t;


while(t--){

int n,x;
cin>>n>>x;

int arr[n];

for(int i=0;i<n;i++){
    cin>>arr[i];
}

sort(arr,arr+n);

unsigned long long int val = arr[n-1];

// int power = (log10(val)-log10(x))/log10(2);
// cout<<"power-->"<<power<<"\n";

int extra =0;
int days =1;
unsigned long long int power =x;
int idx =0;
int visited[n];
memset(visited,0,sizeof(visited));
while(power<val){

double req = (double)power/2;

int flag =0;
for(int i=idx;i<n;i++){

    if(visited[i]==0){
    if(arr[i] <= (int)power){

        if(arr[i]>=req){
            power = arr[i]*2;
            extra++;
            flag =1;
            visited[i]=1;
            idx =i;
            break;
        }

    }
    else{
        break;
    }
    }
}

if(flag ==0){

    power=power*2;

}
days++;


}




//  cout<<res<<"---"<<day2<<"\n";cout<<res<<"---"<<day2<<"\n";

// int ans = min(day2+n-1,days+n-1-extra);

cout<<days + n-1 -extra<<"\n";


}

return 0;


}
