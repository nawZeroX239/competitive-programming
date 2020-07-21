#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define N 1005

#define EPS 1e-9
using namespace std;

int main() {
	string S[] = { "1", "14", "144" };
	string s;
	cin >> s;
	bool isOK=true;
	for (int i = 0; i < s.length(); ++i) {
		if (S[2] == s.substr(i, S[2].length())) {
			i += S[2].length() - 1;
			continue;
		}

		if (S[1] == s.substr(i, S[1].length())) {
			i += S[1].length() - 1;
			continue;
		}

		if (S[0] == s.substr(i, S[0].length())) {
			i += S[0].length() - 1;
			continue;
		}

		isOK = false;
		break;

	}
	if (isOK) cout << "YES" << '\n';
	else cout << "NO" << '\n';

}