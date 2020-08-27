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

const long double EPS = 1e-9;
const int N = 100;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, l, r, tc = 1;
	bool loop;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		int b[100] = {}, s[100] = {};
		for (int i = 0; i < n; ++i) {
			cin >> a;
			b[a]++;
		}
		for (int i = 0; i < m; ++i) {
			cin >> a;
			s[a]++;
		}
		loop = true;
		for (int i = 60; i >= 2; --i) {
			l = i - 1;
			r = i + 1;
			while (b[i] > 0) {
				if (s[i]) {
					s[i]--;
				} else {
					while (l >= 2 && s[l] == 0) --l;
					while (r <= 60 && s[r] == 0) ++r;
					if (l < 2 && r > 60) {
						loop = false;
						break;
					} else if (l < 2) {
						s[r]--;
					} else if (r > 60) {
						s[l]--;
					} else {
						if (i - l < r - i) {
							s[l]--;
						} else {
							s[r]--;
						}
					}

				}
				--n;
				b[i]--;
			}

			if (!loop) break;
		}

		cout << "Case " << tc++ << ": "<<n;
		if (n) {
			for (int i = 2; i <= 60; ++i) {
				if (b[i]) {
					cout <<' '<< i;
					break;
				}
			}
		} 
		cout<< '\n';
	}

}