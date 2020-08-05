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
#include <climits>
#include <bitset>
#include <numeric>
using namespace std;


const long double PI = 3.14159265358979323846264338327950;
const double EPS = 1e-9;
const int N = 200001;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

template <class T> bool isPrime(T x) {
	for (T d = 2; d * d <= x; d++) { if (x % d == 0) return false; }
	return true;
}

struct dummy{
	int cnt, num;
};

dummy arr[N] = {};

bool sort_pd(dummy& L, dummy& R) {
	return L.cnt < R.cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k, m;
	int cnt;
	cin >> n >> k;

	cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> m;
		++arr[m].cnt;
		arr[m].num = m;
	}

	for (int i = 1; i <= N; ++i) {
		if (arr[i].cnt) {
			++cnt;
		}
	}

	int ans = 0;
	if (cnt <= k) {
		cout << ans << '\n';
	} else {
		sort(arr, arr + N, sort_pd);
		for (int i = 1; i <= N; ++i) {
			// cout << arr[i].num << '\n';
			if (arr[i].cnt) {
				ans += arr[i].cnt;
				cnt--;

				if(cnt <= k)
				break;
			}
		}
		cout << ans << '\n';
	}

}