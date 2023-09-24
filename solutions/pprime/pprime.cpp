/*
ID: jbrenda1
TASK: pprime
LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

bool is_prime[10000000];

int main()
{
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");

    int a, b;
    fin >> a >> b;

    b = min(10000000 - 1, b);

    for (int i = 2; i <= b; i++)
	is_prime[i] = true;

    for (int i = 2; i <= b; i++)
	if (is_prime[i])
	    for (int j = 2*i; j <= b; j += i)
		is_prime[j] = false;

    vector<int> ans;

    for (int i = a; i <= b; i++) {
	if (is_prime[i]) {
	    string s = to_string(i);
	    int l = 0, r = s.size() - 1;
	    while (s[l] == s[r] && l < r) {
		l++;
		r--;
	    }
	    if (s[l] == s[r]) {
		ans.push_back(i);
	    }
	}
    }

    for (auto p : ans)
	fout << p << "\n";

}
