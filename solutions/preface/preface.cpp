/*
ID: jbrenda1
TASK: preface
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

struct state {
	unordered_map<char, int> frequency {
		{'I', 0},
		{'V', 0},
		{'X', 0},
		{'L', 0},
		{'C', 0},
		{'D', 0},
		{'M', 0}
	};
};

static const set<int> st {
	1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000
};

static unordered_map<int, string> dictionary {
	{1, "I"},
	{4, "IV"},
	{5, "V"},
	{9, "IX"},
	{10, "X"},
	{40, "XL"},
	{50, "L"},
	{90, "XC"},
	{100, "C"},
	{400, "CD"},
	{500, "D"},
	{900, "CM"},
	{1000, "M"},
};

static const string digits = "IVXLCDM";

string itor(int number) {
	string roman = "";

	while (0 < number) {
		auto target = st.lower_bound(number);
		if (number < *target || target == st.end()) {
			--target;
		}
		roman += dictionary[*target];
		number -= *target;
	}

	return roman;
}

int main()
{
	ifstream fin("preface.in");
	ofstream fout("preface.out");

	int n;
	fin >> n;

	vector<state> count(n + 1);

	for (int i = 1; i <= n; i++) {
		string roman = itor(i);
		count[i].frequency = count[i - 1].frequency;
		for (const auto& digit : roman) {
			count[i].frequency[digit]++;
		}
	}

	for (const auto& digit : digits) {
		if (count[n].frequency[digit])
			fout << digit << " " << count[n].frequency[digit] << "\n";
	}
}
