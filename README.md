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

