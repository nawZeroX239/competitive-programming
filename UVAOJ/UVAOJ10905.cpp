#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
struct cmp {
	inline bool operator() (const string& str1, const string& str2) {
		string p = str1 + str2;
		string q = str2 + str1;
		for (int i = 0; i < str1.length() + str2.length(); ++i)
			if (p[i] > q[i])
				return true;
			else if (p[i] < q[i])
				return false;

		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	while (cin >> n) {
		if (n == 0)
			break;
		vector<string> vect;
		while (n) {
			cin >> s;
			vect.push_back(s);
			--n;
		}

		sort(vect.begin(), vect.end(), cmp());
		for (int i = 0; i < vect.size(); ++i)
			cout << vect[i];
		cout << '\n';
	}

}