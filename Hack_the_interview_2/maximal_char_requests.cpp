//Square root decomp didn't work TLE
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getMaxCharCount' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. 2D_INTEGER_ARRAY queries
 */
//using prefix array and suffix array for each character
vector<int> getMaxCharCount(string s, vector<vector<int>> queries) {
    // queries is a n x 2 array where queries[i][0] and queries[i][1] represents x[i] and y[i] for the ith query.
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    map<int, vector<int> > dict;
    vector<int> arr(26,0);
    char maxcha[3*100000+1];//prefix
    char maxcha2[3*100000+1];//suffix
    char tmpchar = 'a';
    for(int i=0;i<(int)s.size();i++){
        arr[s[i]-'a']++;
        for(int j=0;j<26;j++){
            dict[j].push_back(arr[j]);
        }
        if(s[i]>tmpchar){
            tmpchar=s[i];
        }
        maxcha[i]=tmpchar;
    }
    tmpchar='a';
    for(int i=(int)s.size()-1;i>=0;i--){
        if(s[i]>tmpchar){
            tmpchar=s[i];
        }
        maxcha2[i]=tmpchar;
    }
    vector<int> res;
    for(auto query:queries){
        int l = query[0];
        int r = query[1];
        char maxchar = 'a';
        int val=-1;
        if(maxcha[l]!=maxcha[r]){
            maxchar = maxcha[r];
            val = dict[maxchar-'a'][r] - ((l>0)?dict[maxchar-'a'][l-1]:0);
        }
        else if(maxcha2[l]!=maxcha2[r]){
            maxchar = maxcha2[l];
            val = dict[maxchar-'a'][r] - ((l>0)?dict[maxchar-'a'][l-1]:0);
        }
        else{
            char e1,e2;
            e1 = maxcha[r];
            e2 = maxcha2[l];
            int some1 = dict[e1-'a'][r] - ((l>0)?dict[e1-'a'][l-1]:0);
            int some2 = dict[e2-'a'][r] - ((l>0)?dict[e2-'a'][l-1]:0);
            if(some1==0 && some2==0){
                maxchar='a';
                for(int i=l;i<=r;i++){
                    if(s[i]>maxchar){
                        maxchar = s[i];
                    }
                }
                val = dict[maxchar-'a'][r] - ((l>0)?dict[maxchar-'a'][l-1]:0);
            }
            else if(some1!=0){
                val = some1;
            }
            else{
                val=some2;
            }
              
        }
        res.push_back(val);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    //int n;// = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);
    //n = s.size();
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> query(q);

    for (int i = 0; i < q; i++) {
        query[i].resize(2);

        string query_row_temp_temp;
        getline(cin, query_row_temp_temp);

        vector<string> query_row_temp = split(rtrim(query_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int query_row_item = stoi(query_row_temp[j]);

            query[i][j] = query_row_item;
        }
    }

    vector<int> ans = getMaxCharCount(s, query);

    for (int i = 0; i < (int)ans.size(); i++) {
        fout << ans[i];

        if (i != (int)ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
