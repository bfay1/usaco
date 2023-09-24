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

    auto check = [&] (string s) {

	    int n = s.size();
	    unordered_map<int, char> values;
	    unordered_set<int> seen;

	    for (int i = 0; i < n; i++) {
		    values[i] = s[i] - '0';
		    if (s[i] == '0' || !seen.insert(s[i] - '0').second)
			    return false;
	    }

	    for (int i = 0; ;) {
		    if (s[i] == '#') {
			    return i == 0 && count(s.begin(), s.end(), '#') == n;
		    }

		    s[i] = '#';
		    i = (i + values[i]) % n;
	    }
    };

    while (!check(to_string(++m)))
	    ;

    fout << m << "\n";
}






