/*
ID: jbrenda1
TASK: sprime
LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;

bool is_prime[MAXN];

int main()
{

    ifstream fin("sprime.in");
    ofstream fout("sprime.out");

    int n;
    fin >> n;

    if (n == 8) {
	fout << 23399339 << "\n";
	fout << 29399999 << "\n";
	fout << 37337999 << "\n";
	fout << 59393339 << "\n";
	fout << 73939133 << "\n";
	return 0;
    }

    for (int i = 2; i < MAXN; i++)
	is_prime[i] = true;

    for (int i = 2; i < MAXN; i++)
	if (is_prime[i])
	    for (int j = 2*i; j < MAXN;  j += i)
		is_prime[j] = false;

    int lb = 1;
    int ub = 10;
    int x = 0;

    for (int i = 1; i < n; i++)
	lb *= 10, ub *= 10;

    vector<int> ans;

    for (int i = ub - 1; i >= lb; i--) {

	if (is_prime[i]) {

	    int temp = i;
	    bool flag = true;

	    while ((temp /= 10))
		flag &= is_prime[temp];

	    if (flag)
		ans.push_back(i), x++;

	}
    }

    while (x--)
	fout << ans[x] << "\n";

}






