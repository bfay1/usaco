/*
NAME: jbrenda1
LANG: C++
TASK: skidesign
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans = INT_MAX, cur, n;
int hills[1005];

signed main()
{
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");

	fin >> n;

	for (int i = 0; i < n; i++)
		fin >> hills[i];

	sort(hills, hills + n);

	for (int i = 0; i <= 83; i++) {
		for (int j = 0; j < n; j++) {
			if (hills[j] < i)
				cur += (hills[j] - i)*(hills[j] - i);
			if (i + 17 < hills[j])
				cur += (hills[j] - i - 17)*(hills[j] - i - 17);
		}
		ans = min(ans, cur);
		cur = 0;
	}

	fout << ans << "\n";
}
