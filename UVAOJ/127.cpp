#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <iomanip>
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
#include <climits>
#include <bitset>
#include <numeric>
using namespace std;

const long double PI = 3.14159265358979323846264338327950;
const double EPS = 1e-9;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };
const int N = 52;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}


bool pred(string& left, string& right) {
	return left[0] == right[0] || left[1] == right[1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	while (cin >> s) {
		if (s == "#") break;
		vector<vector<string>> vvs(N);
		vvs[0].push_back(s);

		for (int i = 1; i < N; ++i) {
			cin >> s;
			vvs[i].push_back(s);
		}
		// cout << vvs[N - 1].back() << '\n';
		int n = N, m, k, we, inc;
		
		for(k=0; k<n; ) {
			inc=0;
			if (k-3 >= 0 && pred(vvs[k].back(), vvs[k - 3].back())) {
				inc = -3;
			}else if (k-1 >= 0 && pred(vvs[k].back(), vvs[k - 1].back())) {
				inc = -1;
			} else {
				++k;
			}

			if (inc < 0) {
				vvs[k + inc].push_back(vvs[k].back());
				vvs[k].pop_back();

				if (vvs[k].size() == 0) {
					for (we = k; we < n - 1; ++we) {
						swap(vvs[we], vvs[we + 1]);
					}
					vvs.pop_back();
					n = vvs.size();
				}
				k += inc;
			}
			if (vvs.size() == 1) break;
		}

		if (vvs.size() == 1) {
			cout << vvs.size() << " pile remaining: " << vvs[0].size() << '\n';
		} else {
			cout << vvs.size() << " piles remaining:";
			for (int i = 0; i < vvs.size(); ++i) {
				cout << ' ' << vvs[i].size();
			}
			cout << '\n';
		}
		
	}

}
