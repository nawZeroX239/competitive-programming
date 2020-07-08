#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <deque>
#include <array>
#include <forward_list>
#include <queue>
#include <stack>
#include <sstream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define N 30
using namespace std;
int a, b, n, type;

vector<string> sols[N];
vector<string> title;

void dfs(int k, string s, int sz) {
	if (sz>0) sols[sz - 1].push_back(s);

	if (s.length()) s += ", ";
	for (int i = k; i < title.size(); ++i) {
		dfs(i + 1,s +title[i], sz+1);
	}
}

void out(int lo, int hi) {
	for (int i =lo; i <= hi; ++i) {
		cout << "Size " << i + 1 << '\n';
		for (int j = 0; j < sols[i].size(); ++j)
			cout << sols[i][j] << '\n';
		cout << '\n';
	}
}

int main() {
	int tc;
	string nl, ins;
	cin >> tc;
	getline(cin, nl);
	getline(cin, nl);
	while(tc--) {
		getline(cin, ins);
		if (ins[0] == '*') {
			type = -1;
		} else {
			stringstream ss(ins);
			ss >> a;
			type = 0;
			if (ss >> b) type = 1;
		}

		title.clear();
		for (int i = 0; i < N; ++i) sols[i].clear();
		while (getline(cin, ins)) {
			if (ins.length() == 0) break;
			title.push_back(ins);
		}

		n = title.size();
		dfs(0, "", 0);

		if (type == -1) {
			out(0, title.size() - 1);
		} else if (type == 0) {
			out(a - 1, a - 1);
		} else {
			out(a - 1, b - 1);
		}

		if (tc) cout << '\n';
	}
}