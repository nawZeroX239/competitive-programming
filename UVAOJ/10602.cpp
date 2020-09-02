#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
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
#include <climits>
#include <cmath>
#include <bitset>
#include <numeric>
using namespace std;

const long double PI = 3.14159265358979323846264338327950;
const double EPS = 1e-9;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };
const int N = 100;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int toInt(string& s) {
	stringstream ss(s);
	int n;
	ss >> n;
	return n;
}

//bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
//	return left.second > right.second;
//}
//
//bool lb_pred(const pair<int, int>& left, const int right) {
//	return left.first < right;
//}
//

string arr[N];
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int T, n, cst, bs, sm, ps;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		
		for (int i = 0; i < n -1; ++i) {
			ps = bs = -1;
			for (int j = i + 1; j < n; ++j) {
				sm = 0;
				for (int k = 0; k < arr[i].length() && k < arr[j].length()
					&& arr[i][k] == arr[j][k]; ++k) {
					++sm;
				}
				if (bs < sm) {
					ps = j;
					bs = sm;
				}
			}
			if (i + 1 < ps) swap(arr[i + 1], arr[ps]);
		}

		cst = arr[0].length();
		for (int i = 1, j; i < n; ++i) {
			for (j = 0; j < arr[i - 1].length() && j < arr[i].length()
				&& arr[i-1][j] == arr[i][j]; ++j) {

			}
			cst += arr[i].length() - j;
		}

		cout << cst << '\n';
		for (int i = 0; i < n; ++i) {
			cout << arr[i] << '\n';
		}

	}
	return 0;
}