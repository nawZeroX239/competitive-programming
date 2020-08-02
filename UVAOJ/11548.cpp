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
const int N = 3005;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

template <class T> bool isPrime(T x) {
	for (T d = 2; d * d <= x; d++) { if (x % d == 0) return false; }
	return true;
}


vector<string> words;
int n;

int match(int i, int j, int sol) {
	int best, c;
	best = 0;
	for (int k = 0; k < words[i].length(); ++k) {
		c = 0;
		if (words[i].length() - k <= sol)
			break;
		for (int a = k, b = 0; a < words[i].length() && b < words[j].length(); ++a, ++b) {
			if (words[i][a] == words[j][b])
				++c;
		}
		best = max(best, c);
	}

	return best;
}

int solve() {
	int best = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (words[i].length() <= best)
			continue;
		for (int j = i+1; j < n; ++j) {
			if (words[i].length() <= best || words[j].length() <= best)
				continue;
			
			best = max(best, match(i, j, best));
			best = max(best, match(j, i, best));
			
		}
	}

	return best;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		words.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> words[i];
		cout << solve() << '\n';
	}

}
