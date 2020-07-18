class Solution {
public:
    string lcs(string str1,string str2){
        int n = str1.size();
        int m = str2.size();
        int dp[1002][1002];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string res="";
        int i=n;
        int j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                res+= str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string res = lcs(str1,str2);
        //cout<<res<<endl;
        int i=0;
        int j=0;
        int k=0;
        string scs = "";
        while(k<res.size()){
            char curr = res[k];
            while(i<str1.size() && str1[i]!=curr){
                scs+= str1[i];
                i++;
            }
            while(j<str2.size() && str2[j]!=curr){
                scs+= str2[j];
                j++;
            }
            scs+= curr;
            k++;i++;j++;
        }
        while(i<str1.size()){
            scs+= str1[i];
            i++;
        }
        while(j<str2.size()){
            scs+=str2[j];
            j++;
        }
        return scs;
    }
};