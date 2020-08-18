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
const int N = 1000;
template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int coins[N];

bool sort_pred(pair<int, int>& left, pair<int, int>& right) {
	if (left.first == right.first) {
		return left.second > right.second;
	}

	return left.first < right.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, n, m, L, R, end, start;
	bool ok;

	cin >> T;
	while (T--) {
		vector<pair<int, int>> arr;
		vector<pair<int, int>> sol;
		cin >> m;
		while (cin >> L >> R) {
			if (L == 0 && R == 0) break;
			if (R > 0) {
				arr.push_back(make_pair(L, R));
			}
		}

		sort(arr.begin(), arr.end(), sort_pred);

		/*for (int i = 0; i < arr.size(); ++i) {
			cout << arr[i].first << ' ' << arr[i].second << '\n';;
		}*/


		start = end = -1;
		if (arr.size()) {
			start = 0;
			for (int i = 1; i < arr.size() && arr[i].first <= 0; ++i) {
				if (arr[i].second > arr[start].second) {
					start = i;
				}
			}

			sol.push_back(arr[start]);
			end = arr[start].second;
			for (int i = start + 1; i < arr.size() && end < m; ++i) {
				int next = -1, j = i;
				for (; j < arr.size() && end >= arr[j].first; ++j) {
					if (arr[j].second > end) {
						if (next == -1) {
							next = j;
						}  else {
							if (arr[j].second > arr[next].second)
								next = j;
						}
					}

				}
				
				if (next > -1) {
					sol.push_back(arr[next]);
					end = arr[next].second;
					i = next;
				}
				
			}
		}
	
		if (start >-1 && arr[start].first <= 0 && end >= m) {
			cout << sol.size() << '\n';
			for (int i = 0; i < sol.size(); ++i) {
				cout << sol[i].first << ' ' << sol[i].second << '\n';
			}
		} else {
			cout << 0 << '\n';
		}
		if (T) cout << '\n';
	}
}
