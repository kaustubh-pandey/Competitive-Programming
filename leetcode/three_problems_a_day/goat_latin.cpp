class Solution {
public:
    bool check(char c){
        char vowels[] = {'a','A','e','E','i','I','o','O','u','U'};
        for(char x: vowels){
            if(c==x){
                return true;
            }
        }
        return false;
    }
    string toGoatLatin(string S) {
        S+=" ";
        string res="";
        string word="";
        int count=0;
        for(int i=0;i<S.size();i++){
            if(S[i]==' '){
                count++;
               if(!check(word[0])){
                   char first = word[0];
                   word = word.substr(1);
                   word+=first;
               }
               word+="ma";
               for(int j=0;j<count;j++){
                   word+='a';
               } 
               res+=word;
               res+=" "; 
               word=""; 
            }
            else{
             word+=S[i];   
            }
        }
        res.erase(res.size()-1);
        return res;
    }
};