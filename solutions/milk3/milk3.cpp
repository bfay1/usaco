/*
ID: jbrenda1
TASK: numtri
LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

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
	    cin >> x;
	    g[i].push_back(x);
	}
    }

    function <int(int, int, int)> dfs = [&] (int row, int col, int cur) {
	if (row == n)
	    return cur;

	cur += g[row][col];

	return max(dfs(row + 1, col, cur), dfs(row + 1, col + 1, cur));
    };

    int ans = dfs(0, 0, 0);

    cout << ans << "\n";
    fout << ans << "\n";

}
