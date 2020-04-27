#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'configureProjectPresentation' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY friendships
 */

vector<int> configureProjectPresentation(int n, vector<vector<int>> friendships) {
    vector<int> g[n+1];
    for(auto fr : friendships){
        g[fr[0]].push_back(fr[1]);
        g[fr[1]].push_back(fr[0]);
    }
    vector<bool> arr(n+1,false);
    vector<int> myfriends;
    //friends of 1
    for(auto x:g[1]){
        arr[x]=true;
    }
    //not friends of 2
    for(auto x:g[2]){
        if(x!=1){
            myfriends.push_back(x);
            arr[x]=false;   
        }
    }
    //not friends of friends of 2
    for(auto x:myfriends){
        if(x==1){
            continue;
        }
        for(auto y:g[x]){
            arr[y]=false;
        }
    }
    arr[2]=false;
    vector<int> res;
    for(int i =1;i<=n;i++){
        if(arr[i]){
            res.push_back(i);
        }
    }
    if(res.size()==0){
        res.push_back(-1);
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> freiendships(m);

        for (int i = 0; i < m; i++) {
            freiendships[i].resize(2);

            string freiendships_row_temp_temp;
            getline(cin, freiendships_row_temp_temp);

            vector<string> freiendships_row_temp = split(rtrim(freiendships_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int freiendships_row_item = stoi(freiendships_row_temp[j]);

                freiendships[i][j] = freiendships_row_item;
            }
        }

        vector<int> result = configureProjectPresentation(n, freiendships);

        for (int i = 0; i < (int)result.size(); i++) {
            fout << result[i];

            if (i != (int)result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
