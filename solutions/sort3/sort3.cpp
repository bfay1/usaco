/*
ID: jbrenda1
TASK: sort3
LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{

    ifstream fin("sort3.in");
    ofstream fout("sort3.out");

    int one = 0;
    int two = 0;
    int three = 0;

    int n;
    fin >> n;

    vector<int> a(n);

    for (auto& x : a) {
	fin >> x;
	one += (x == 1);
	two += (x == 2);
	three += (x == 3);
    }

    pair<int, int> ones = {0, one - 1};
    pair<int, int> twos = {one, one + two - 1};
    pair<int, int> threes = {one + two, n - 1};

    function <bool(int)> inone = [&] (int x) {
	return x >= 0 && x <= one - 1;
    };

    function <bool(int)> intwo = [&] (int x) {
	return x >= one && x <= one + two - 1;
    };

    function <bool(int)> inthree = [&] (int x) {
	return one + two <= x;
    };

    int onestwos = 0;
    int onesthrees = 0;
    int twosones = 0;
    int twosthrees = 0;
    int threesones = 0;
    int threestwos = 0;
    int inversions = 0;
    
    for (int i = 0; i < n; i++) {
 
	if (a[i] == 1 && !inone(i))
	    inversions++;
	else if (a[i] == 2 && !intwo(i))
	    inversions++;
	else if (a[i] == 3 && !inthree(i))
	    inversions++;

	if (a[i] == 1 && intwo(i))
	    onestwos++;
	if (a[i] == 1 && inthree(i))
	    onesthrees++;
	if (a[i] == 2 && inone(i))
	    twosones++;
	if (a[i] == 2 && inthree(i))
	    twosthrees++;
	if (a[i] == 3 && inone(i))
	    threesones++;
	if (a[i] == 3 && intwo(i))
	    threestwos++;
    }

    int ans = min(onestwos, twosones) + min(onesthrees, threesones) + min(twosthrees, threestwos);
    inversions -= 2*ans;

    if (inversions > 0)
	ans += (inversions / 3)*2;

    fout << ans << "\n";
}






