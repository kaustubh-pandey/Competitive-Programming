# Competitive-Programming

Collection of some selected problems from various competitve coding websites along with some sample codes of common algorithms

## Editor Settings
### VSCode
For MacOS: Go to $HOME/Library/Application Support/Code/User

For Linux: Go to $HOME/.config/Code/User

Create a file tasks.json with the following content:
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
