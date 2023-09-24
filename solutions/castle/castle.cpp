/*
ID: jbrenda1
TASK: castle
LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

int g[51][51];

int main()
{

    ifstream fin("castle.in");
    ofstream fout("castle.out");

    int m, n;
    fin >> m >> n;

    for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	    fin >> g[i][j];

    function <bool(int, int)> invalid = [&] (int i, int j) {
	return i < 0 || j < 0 || i >= n || j >= m || g[i][j] == 16;
    };

    function <void(int, int, vector<pair<int, int>>&)> dfs = [&] (int i, int j, vector<pair<int, int>>& component) {
	if (invalid(i, j))
	    return;

	component.push_back({i, j});

	int west = 0, north = 0, east = 0, south = 0;

	if (g[i][j]) {
	    west = g[i][j] & 1;
	    north = g[i][j] & 2;
	    east = g[i][j] & 4;
	    south = g[i][j] & 8;
	}

	g[i][j] = 16;

	if (west == 0)
	    dfs(i, j - 1, component);
	if (north == 0)
	    dfs(i - 1, j, component);
	if (east == 0)
	    dfs(i, j + 1, component);
	if (south == 0)
	    dfs(i + 1, j, component);
    };

    vector<vector<pair<int, int>>> components;
    int mx = 0;

    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    if (g[i][j] != 16) {
		vector<pair<int, int>> component;
		dfs(i, j, component);
		components.push_back(component);
		mx = max(mx, (int) component.size());
	    }
	}
    }

    int ans = 0;
    int z = components.size();
    pair<int, int> y = {0, 0};
    char dir = 'E';

    fout << z << "\n";
    fout << mx << "\n";

    for (int i = 0; i < z; i++) {
	for (int j = i + 1; j < z; j++) {
	    for (auto [a, b] : components[i]) {
		for (auto [c, d] : components[j]) {
		    int h = abs(a - c);
		    int v = abs(b - d);
		    int works = (h == 0 && v == 1) || (h == 1 && v == 0);
		    if (works) {
			int tmp = components[i].size() + components[j].size();
			if (tmp > ans) {
			    pair<int, int> x;
			    char td = 'E';
			    if (b == d) {
				if (a < c)
				    x = {c, d};
				else
				    x = {a, b};
				td = 'N';
			    } else {
				if (b < d)
				    x = {a, b};
				else
				    x = {c, d};
				td = 'E';
			    }
			    y = x;
			    dir = td;
			} else if (tmp == ans) {
			    pair<int, int> x;
			    char td = 'E';
			    if (b == d) {
				if (a < c)
				    x = {c, d};
				else
				    x = {a, b};
				td = 'N';
			    } else {
				if (b < d)
				    x = {a, b};
				else
				    x = {c, d};
				td = 'E';
			    }
			    if (y.second == x.second) {
				if (y.first < x.first)
				    y = x, dir = td;
			    } else if (x.second < y.second) {
				y = x, dir = td;
			    }
			}
			ans = max(tmp, ans);
		    }
		}
	    }
	}
    }

    fout << ans << "\n";
    fout << y.first  + 1 << " " << y.second + 1 << " " << dir << "\n";
}






