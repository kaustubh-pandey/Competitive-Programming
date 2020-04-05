class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        while(i<chars.size()){
            int j=i;
            while(j<chars.size() && chars[i]==chars[j]){
                j++;
            }
            int freq = j-i;
            if(freq>1){
                string s = to_string(freq);
                int l=0;
                for(int k=i+1;k<j;k++,l++){
                    if(l<s.size()){
                     chars[k]=s[l];   
                    }
                    else{
                        chars[k]=' ';
                    }
                }
            }
            i=j;
        }
        // for(auto y:chars){
        //     cout<<y<<" ";
        // }
        // cout<<endl;
        chars.erase( remove( chars.begin(), chars.end(), ' ' ), chars.end() );
        return chars.size();
    }
};