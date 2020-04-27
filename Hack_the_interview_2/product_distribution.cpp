#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maxScore' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER m
 */

int maxScore(vector<int> a, int m) {
    sort(a.begin(),a.end());
    ll start=0;
    ll rem = a.size()%m;
    ll seg=0;
    ll res=0;
    ll sum;
    while((start+m-1)<((ll)a.size()-rem)){
        sum=0;
        for(int j=start;j<start+m;j++){
            sum = (sum%MOD+a[j]%MOD)%MOD;
        }
        seg++;
        res = ((res%MOD) + ((seg%MOD)*(sum%MOD))%MOD)%MOD;
        start+=m;
    }
    //cout<<res<<endl;
    sum=0;
    while(start<(ll)a.size()){
        sum = (sum%MOD+a[start]%MOD)%MOD;
        start++;
    }
    res = ((res%MOD) + ((seg%MOD)*(sum%MOD))%MOD)%MOD;
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int ans = maxScore(a, m);

    fout << ans << "\n";

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
