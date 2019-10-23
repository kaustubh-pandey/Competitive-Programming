#include<bits/stdc++.h>
using namespace std;
int* T(){
	int temp;
	return &temp;
}
int main(){
	int *ptr;
	ptr=T();
	int r=42;
	ptr=&r;
	cout<<*ptr<<endl;
	return 0;
}