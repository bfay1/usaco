/*
ID: jbrenda1
TASK: frac1
LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{

    ifstream fin("frac1.in");
    ofstream fout("frac1.out");

    int n;
    fin >> n;

    set<pair<int, int>> st;
    vector<pair<int, int>> ans;
    st.insert({0, 1});
    ans.push_back({0, 1});

    for (int i = 1; i <= n; i++) {
	for (int j = n; j >= i; j--) {
	    int g = gcd(i, j);
	    pair<int, int> child = {i / g, j / g};
	    if (st.find(child) == st.end()) {
		ans.push_back({i, j});
		st.insert(child);
		st.insert({i, j});
	    }
	}
    }

    sort(ans.begin(), ans.end(), [&] (pair<int, int> a, pair<int, int> b) {
	    return a.first * b.second < a.second * b.first;
	    });

    for (auto [n, d] : ans)
	fout << n << "/" << d << "\n";
}






