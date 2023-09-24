/*
ID: jbrenda1
TASK: subset
LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

long long dp[40*41];

int main()
{

    ifstream fin("subset.in");
    ofstream fout("subset.out");

    int n;
    fin >> n;

    dp[0] = 1;

    if (n*(n + 1) % 4) {
	fout << "0\n";
	return 0;
    }

    for (int i = 1; i <= n; i++) {
	for (int j = n*(n + 1)/4; j >= i; j--) {
	    dp[j] += dp[j - i];
	}
    }

    fout << dp[n*(n + 1)/4] / 2 << "\n";

}






