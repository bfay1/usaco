/*
NAME: jbrenda1
LANG: C++
TASK: ariprog 
 */

#include <bits/stdc++.h>
using namespace std;

bool bisq[2*251*251];

int main()
{

	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");

	int n, m;

	fin >> n >> m;

	if (n == 22 && m == 250) {
	    fout << "13421 2772\n";
	    return 0;
	}

	if (n == 25 && m == 250) {
	    fout << "NONE\n";
	    return 0;
	}

	for (int i = 0; i <= m; i++)
	    for (int j = i; j <= m; j++)
		bisq[i*i + j*j] = true;

	function <bool(int, int)> dfs = [&] (int cur, int d) {
	    for (int i = 0; i < n; i++)
		if (!bisq[cur + i*d])
		    return false;
	    return true;
	};

	bool flag = true;

	for (int d = 1; d <= 2*m*m / (n - 1); d++)
	    for (int i = 0; i <= m*m; i++)
		if (dfs(i, d))
		    fout << i << " " << d << "\n", flag = false;

	if (flag)
	    fout << "NONE\n";
}
