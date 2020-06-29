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

#define EPS 1e-9
#define N 5
#define PIXEL 1024
#define ll long long
#define pi pair<ll, ll>

using namespace std;

inline void newline() { cout << '\n'; }
inline void split(vector<string>& vect, string& str, char delim) {
	string each;
	for (auto it = str.begin(); it != str.end(); ++it) {
		if (*it != delim)
			each.push_back(*it);
		else {
			vect.push_back(each);
			each.clear();
		}
	}
	if (each.size()) vect.push_back(each);
}

inline bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
	return left.first < right.first;
}

inline bool lb_pred(const pair<int, int>& left, int right) {
	return left.first < right;
}

int arr[N];

bool backtrack(int i, int num) {
	if (i >= N) return num == 23;

	if (backtrack(i + 1, num * arr[i]))
		return true;
	if (backtrack(i + 1, num - arr[i]))
		return true;
	if (backtrack(i + 1, num + arr[i]))
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		for (int i = 0; i < N; ++i)
			scanf("%d", &arr[i]);
		if (arr[0] + arr[1] + arr[2] + arr[3] + arr[4] == 0)break;
		sort(arr, arr + N);
		bool sol = false;
		do {
			sol = sol | backtrack(1, arr[0]);
		} while (!sol && next_permutation(arr, arr + N));
		if (sol)
			puts("Possible");
		else
			puts("Impossible");
	}
}