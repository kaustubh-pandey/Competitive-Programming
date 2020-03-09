class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(),paragraph.end(),paragraph.begin(),::tolower);
        for(int i=0;i<paragraph.size();i++){
            if(paragraph[i]=='.' || paragraph[i]==',' || paragraph[i]==';' || paragraph[i]=='!' || paragraph[i]=='?'||paragraph[i]=='\''){
                paragraph[i]=' ';
            }
            if(paragraph[i]=='\''){
                if((i+1<paragraph.size() && paragraph[i+1]==' ')||(i-1>=0 && paragraph[i-1]==' ')){
                    paragraph.erase(i,1);   
                }
            }
        }
        unordered_map<string,bool> ban;
        for(string x:banned){
            ban[x]=true;
        }
        map<string,int> m;
        string tmp="";
        for(int i=0;i<paragraph.size();i++){
            if(paragraph[i]==' '){
                if(!ban[tmp] && tmp!=""){
                  m[tmp]++;   
                }
                tmp="";
                continue;
            }
            tmp+=paragraph[i];
        }
        if(tmp!=""){
         m[tmp]++;   
        }
        vector< pair<int,string> > con;
        for(auto x:m){
            con.push_back(make_pair(x.second,x.first));
        }
        sort(con.rbegin(),con.rend());
        return con[0].second;
    }
};