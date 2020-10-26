# Competitive-Programming

Collection of some selected problems from various competitve coding websites along with some sample codes of common algorithms
### Install g++
For MacOS : brew install gcc (install homebrew first)
## Editor Settings
### VSCode
For MacOS: Go to $HOME/Library/Application Support/Code/User

For Linux: Go to $HOME/.config/Code/User

Create a file tasks.json with the following content:
For Linux:
```
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "shell",
			"label": "C/C++: g++ build active file",
			"command": "/usr/bin/g++",
			"args": [
				"-g",
				"${file}",
				"-std=c++17",
				"-Wshadow",
				"-Wall",
				"-o",
				"a.out",
				"-fsanitize=address",
				"-fsanitize=undefined",
				"-D_GLIBCXX_DEBUG"
			],
			"options": {
				"cwd": "${workspaceFolder}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			}
		}
	]
}

```
For MacOS:
```
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "shell",
			"label": "C/C++: g++ build active file",
			"command": "/usr/local/bin/g++-10",
			"args": [
				"-g",
				"${file}",
				"-std=c++17",
				"-Wshadow",
				"-Wall",
				"-o",
				"a.out",
				"-fsanitize=address",
				"-fsanitize=undefined",
				"-D_GLIBCXX_DEBUG"
			],
			"options": {
				"cwd": "${workspaceFolder}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			}
		}
	]
}

```

Add keybindings:
VSCode
F1: Switch to editor
F2: Switch to terminal
F9: Run build task
Ctrl+F9: Run build task using code runner using input file
Geany:
Same as vscode except Ctrl+F9

## Sample Template
```
#include<bits/stdc++.h>
#define ll long long
#define xll __int128
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a,n) memset(a,0,sizeof(a[0])*n)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl "\n"
#define Endl "\n"
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
#define TIK auto start = chrono::high_resolution_clock::now();
#define TOK auto end = chrono::high_resolution_clock::now();double time_taken =chrono::duration_cast<chrono::nanoseconds>(end - start).count();time_taken *= 1e-9;cerr << "Time taken:" << fixed << time_taken << setprecision(9);cerr << " sec" << endl;
using namespace std;
const int MOD=1000000007;
void print(){cout <<endl;}
template <typename T, typename... Types> 
void print(T var1, Types... var2){cout << var1 << " " ;print(var2...) ;}
//ceil of a/b
template <typename T>
T fceil(T a,T b){return (T)(a+b-1)/b;}
template <typename T>
void printvec(vector<T> v){ for(int i=0;i<(int)v.size();i++){ cout<<v[i]<<" ";} cout<<endl;}
template <typename T>
void printarr(T a[],int n){ for(int i=0;i<n;i++){ cout<<a[i]<<" ";} cout<<endl;}
//const int N=2e5;
//int arr[N+1];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
                    
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!
: While casting to long long 1LL*a*b works while a*b*1LL doesn't*/
```
