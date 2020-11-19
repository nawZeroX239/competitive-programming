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

#define INF 1e9
#define  EPS 1e-9
#define N 100005
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

// translation
int tx[] = { 0, 0, 1, -1 };
int ty[] = { -1, 1, 0, 0 };

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int toInt(string& s) {
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s, f;
	long long prefix[N];
	prefix[0] = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> prefix[i];
		prefix[i] += prefix[i - 1];
	}

	cin >> s >> f;
	int ans = 1, start, end;
	long long tot = -1, sum;

	for (int i = 1; i <= n; ++i) {
		start = s - i + 1;
		end = f - i;
		if (start < 1) {
			start += n;
		}

		if (end < 1) {
			end += n;
		}

		if (start < end) {
			sum = prefix[end] - prefix[start - 1];
		} else {
			sum = prefix[end] + prefix[n] - prefix[start - 1];
		}

		if (tot < sum) {
			tot = sum;
			ans = i;
		}
	}
	
	cout << ans << '\n';
}