/*
ID: jbrenda1
TASK: numtri
LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

int v[1005][1005];

int main()
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");

    int n;
    fin >> n;

    vector<vector<int>> g(n);

    for (int i = 0; i < n; i++) {
	int j = i + 1;
	while (j--) {
	    int x;
	    fin >> x;
	    g[i].push_back(x);
	}
    }

    for (int row = n - 1; row >= 0; row--) {
	for (int col = row - 1; col >= 0; col--) {
	    g[row - 1][col] += max(g[row][col], g[row][col + 1]);
	}
    }

    fout << g[0][0] << "\n";

}
