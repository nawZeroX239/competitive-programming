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
const int N = 24;
const int K = sqrt(50000);

template <class T> T gcd(T a, T b) {
	if (b == 0){ return a;} 
	return gcd(b, a % b);
}

template <class T> bool isPrime(T x) {
	for (T d = 2; d * d <= x; d++) { if (x % d == 0) return false; }
	return true;
}


string s, t;

void recur(int i, string u, string v, string ans) {
	if (v.length() == t.length() && v == t) {
		cout << ans.substr(0, ans.length()-1) << '\n';
		return;
	}

	if (i < s.length()) {
		recur(i + 1, u + s.substr(i, 1), v, ans + "i ");
	}

	if (u.length() && u[u.length()-1] == t[v.length()]) {
		recur(i, u.substr(0, u.length()-1), v + u.substr(u.length()-1), ans + "o ");
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (cin >> s >> t) {
		cout << "[" << '\n';
		recur(0, "", "", "");
		cout << "]" << '\n';
	}
	
}
		