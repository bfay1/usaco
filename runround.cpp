/*
ID: jbrenda1
TASK: runround
LANG: C++
 */

#define watch(x) cerr << #x " is: " << x << "\n"

#include <bits/stdc++.h>
using namespace std;

int main()
{

    ifstream fin("runround.in");
    ofstream fout("runround.out");

    unsigned m;

    fin >> m;

    auto bp = [&] (long long a, long long b) {
	    long long ret = 1;

	    while (b) {
		    if (b & 1) ret *= a;
		    a *= a;
		    b >>= 1;
	    }

	    watch(ret);

	    return ret;
    };

    auto v = [&] (unsigned x, int i) {
	    unsigned denom = bp(10, i - 1);

	    watch(i);

	    watch(denom);
	    return (x / denom) % 10;
    };

    auto len = [&] (unsigned x) {
	    unsigned ret = 0;
	    while (x)
		    x /= 10, ret++;
	    return ret;
    };

    auto check = [&] (unsigned x) {
	    unsigned n = len(x);

	    watch(n);

	    for (unsigned f = 0; f < n; f++) {
		    if (v(x, f) == v(x, (f + v(x, f)) % n))
			    return false;
	    }

	    return true;
    };

    while (!check(m))
	    m++;

    fout << m;
}






