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
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

using namespace std;
string s;
void backtrack(string str, int k) {
	if (k == s.length()) {
		cout << str << '\n';
		return;
	}

	backtrack(s[k] + str, k+1);
	for (int i = 0; i < str.length(); ++i)
		backtrack(str.substr(0, i+1) + s[k] + str.substr(i+1), k + 1);

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; cin >> s; ++i) {
		if (i > 0) cout << '\n';
		backtrack("", 0);
	}

	return 0;
}
