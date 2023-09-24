/*
ID: jbrenda1
TASK: hamming
LANG: C++
 */

#include <bits/stdc++.h>

int main()
{

    std::ifstream fin("hamming.in");
    std::ofstream fout("hamming.out");

    int n, b, d;
    fin >> n >> b >> d;

    std::vector<int> ans;

    std::function <int(int, int)> hd = [&] (int x, int y) {
	int ret = 0;
	for (int i = 0; i <= b; i++)
	    ret += (x & (1 << i)) != (y & (1 << i));
	return ret;
    };

    for (int i = 0; i <= (1 << b); i++) {
	bool flag = true;
	for (auto x : ans) {
	    if (hd(i, x) < d) {
		flag = false;
		break;
	    }
	}

	if (flag) {
	    ans.push_back(i);
	}
    }

    for (int i = 0; i < n; i++)
	fout << ans[i] << " \n"[((i + 1) % 10 == 0) || i == n - 1];

}






