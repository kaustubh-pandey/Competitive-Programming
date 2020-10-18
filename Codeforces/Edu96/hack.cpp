#include <bits/stdc++.h>
 
using namespace std;
 
#define optimize() 		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll				long long
#define yes				cout << "YES"<<"\n"
#define no				cout << "NO"<<"\n"
 
int main()
{
	auto start = chrono::high_resolution_clock::now();
	optimize();
	//.......................//
 
	int t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		int c = 0 ;
		for (int i = 0; i < 101; ++i)
		{
			for (int j = 0; j < 101; j++)
			{
				for (int k = 0; k < 101; k++)
				{
					if (i * 3 + j * 5 + k * 7 == n)
					{
						cout << i << " " << j << " " << k << endl;
						c = 1;
						break;
					}
				}
				if (c)break;
			}
			if (c)break;
		}
 
		if (c == 0)cout << -1 << endl;
	}
 
	auto end = chrono::high_resolution_clock::now();
  
    // Calculating total time taken by the program.
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
  
    cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(9);
    cerr << " sec" << endl;

 
	return 0;
}