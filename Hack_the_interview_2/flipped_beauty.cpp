#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minStringCoeff' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER p
 */
int coef(string s){
    int sum1 = 0;
    int sum2 = 0;
    int i=0;
    int j;
    int n = s.size();
    while(i<n && s[i]!='1'){
        i++;
    }
    while(i<n){
        j = i+1;
        while(j<n && s[j]!='1'){
            j++;
        }
        if(j==n && s[j-1]!='1'){
            break;
        }
        sum1+=j-i-1;
        i=j;
    }
    
    i=0;
    j=0;
    while(i<n && s[i]!='0'){
        i++;
    }
    while(i<n){
        j = i+1;
        while(j<n && s[j]!='0'){
            j++;
        }
        if(j==n && s[j-1]!='0'){
            break;
        }
        sum2+=j-i-1;
        i=j;
    }
    return sum1+sum2;
}
int len(pair<int,int> seg1){
    return (seg1.second-seg1.first+1);
}
bool isValid(pair<int,int> seg){
    if(seg.first<=seg.second){
        return true;
    }
    return false;
}
void print(pair<int,int> seg){
    cout<<"first: "<<seg.first<<" second: "<<seg.second<<endl;
}
void printArr(vector< pair<int,pair<int,int> > > segs){
    cout<<"Segs"<<endl;
    for(auto x:segs){
        cout<<x.first<<" ";
        print(x.second);
    }
    cout<<"-----------"<<endl;
}
void process(string &s , pair<int,int> seg, char val){
    //print(seg);
    for(int i=seg.first;i<=seg.second;i++){
        if(s[i]==val){
            break;
        }
        s[i]=val;
    }
}
int f(string s, int p){
    if(p<0){
        return INT_MAX;
    }
    int n = s.size();
    if(p==0){
        return coef(s);
    }
    int i=0;
    while(i<n-1 && s[i]==s[i+1]){
        i++;
    }
    if(i==n-1){
        //all same
        return 0;
    }
    pair<int,int> first_seg = make_pair(0,i);
    i=n-1;
    while(i>0 && s[i]==s[i-1]){
        i--;
    }
    if(i==0){
        //all same
        return 0;
    }
    //cout<<"her"<<endl;
    pair<int,int> last_seg = make_pair(i,n-1);
    //int parity = (s[0]==s[n-1]);
    char left_char = s[0];
    char right_char = s[n-1];
    vector< pair<int,int> > segs;
    int seg_s = first_seg.second+1;
    int seg_e;
    while(seg_s<last_seg.first){
        seg_e = seg_s;
        while(seg_e<last_seg.first && s[seg_s]==s[seg_e]){
            seg_e++;
        }
        segs.push_back(make_pair(seg_s,seg_e-1));
        seg_s = seg_e;
    }
    int segs_num = segs.size();
    if(segs_num==0){
        return 0;
    }
    if(segs_num==1){
        process(s,segs[0],left_char);
    }
    //prefix arr
    vector< pair<int,pair<int,int> > > prefix;
    int sum=0;
    for(int i=0;i<segs_num;i++){
        prefix.push_back(make_pair(len(segs[i])+sum,segs[i]));
        sum+=len(segs[i]);
    }
    //printArr(prefix);
    
    sum=0;
    vector< pair<int,pair<int,int> > > suffix;
    for(int i=segs_num-1;i>=0;i--){
        suffix.push_back(make_pair(len(segs[i])+sum,segs[i]));
        sum+=len(segs[i]);
    }
    //printArr(suffix);
    //cout<<p<<" "<<segs_num<<endl;
    if(segs_num%2==0 && p>=segs_num/2){
        return 0;
    }
    if(p> (int)segs_num/2){
        //process all segs
        return 0;
    }
    int max_val=0;
    int max_i=-1,max_j=-1;
    for(int k=0;k<=p;k++){
        int curr_val = ((k!=0)?prefix[2*k-1].first:0)+((p-k!=0)?suffix[2*(p-k)-1].first:0);
        if(curr_val>max_val){
            max_val = curr_val;
            max_i = 2*k-1;
            max_j = 2*(p-k)-1;
        }
    }
    //cout<<max_i<<" "<<max_j<<endl;
    for(int i=max_i-1;i>=0;i-=2){
        process(s,prefix[i].second,left_char);
    }
    for(int i=max_j-1;i>=0;i-=2){
        process(s,suffix[i].second,right_char);
    }
    return coef(s);
}
int minStringCoeff(string s, int p) {
    string copy=s;
    //complement mid of copy
    int n = copy.size();
    int i=0;
    while(i<n-1 && copy[i]==copy[i+1]){
        i++;
    }
    if(i==n-1){
        //all same
        return 0;
    }
    pair<int,int> first_seg = make_pair(0,i);
    i=n-1;
    while(i>0 && copy[i]==copy[i-1]){
        i--;
    }
    if(i==0){
        //all same
        return 0;
    }
    pair<int,int> last_seg = make_pair(i,n-1);
    if(first_seg.second+1<last_seg.first){
        //valid segs and not empty mid
        //complement mid
        for(int j=first_seg.second+1;j<=last_seg.first-1;j++){
            if(copy[j]=='1'){
                copy[j]='0';
            }
            else{
                copy[j]='1';
            }
        }
        return min(f(s,p),f(copy,p-1));
    }
    return f(s,p);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    //int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);
    //n = s.size();
  
    int res = minStringCoeff(s, p);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
