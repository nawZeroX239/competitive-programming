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
const int N = 500005;

using namespace std;

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
int arr[N], cnt[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	long long sum, d, ans;
	cin >> n;
	sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum % 3) {
		ans = 0;
	} else {
		d = sum / 3;
		sum = 0;
		for (int i = n - 1; i >= 0; --i) {
			sum += arr[i];
			if (sum == d) {
				cnt[i] = 1;
			}
			cnt[i] += cnt[i + 1];
		}
		ans = sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += arr[i];
			if (sum == d) {
				ans += cnt[i + 2];
			}
		}
	}
	cout << ans << '\n';
	
}