#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        string num;
        cin>>num;
        string res = "";
        int count=0;
        for(int i=0;i<num.size();i++){
            int curr = num[i]-'0';
            if(curr==count){
                res+=num[i];
            }
            else if(curr>count){
                string tmp="";
                for(int k=0;k<curr-count;k++){
                    tmp+="(";
                }
                count=curr;
                tmp+=num[i];
                res+=tmp;
            }
            else{
                string tmp="";
                for(int k=0;k<count-curr;k++){
                    tmp+=")";
                }
                count=curr;
                tmp+=num[i];  
                res+=tmp;
            }
        }
        while(count--){
            res+=")";
        }
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
}