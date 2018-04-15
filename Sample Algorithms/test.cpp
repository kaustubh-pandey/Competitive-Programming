#include <bits/stdc++.h>
using namespace std;

string nines_comp (string x, string y)      //x - y using nines compliment
{

    string tempsum = "";
    int xint, yint, zint, zdig, carry = 0;
    char c;
    while (x.length() < y.length()) x = "0"+x;       //making both strings same str size
    while (y.length() < x.length()) y = "0"+y;

    for (int i=0;i < x.length();i++)       //put in nines compliment

    {
        xint = x[i] - '0';      //puting in int for manipulation
	    yint = y[i] - '0';

        xint = 9 - xint;        //getting 9's comp

        zint = xint + yint+carry;   //using addition of 9's comp to preform subtraction

        carry = zint/10;

        zdig = zint%10;

        c = zdig+'0';

        tempsum = c + tempsum;      //this '+' is pasting a a number to the left of tempsum

    }

    //cout<< tempsum << endl;       //geting empty string

    //tempsum.erase (tempsum.length()-1, 1);       //drop the 1 (carry)
    return tempsum;

}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		string a,b;
		cin>>a;
		cin>>b;
		string s=nines_comp(a,b);
		int i;
		for(i=s.length()-1;i>=0;i--){
			if(s[i]!='9'){
				break;
			}
		}
		string r="";
		while(i>=0){
			r+=s[i];
			i--;
		}
		if(r==""){
			r='9';
		}
		cout<<r<<endl;
	}
}
